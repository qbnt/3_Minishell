/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:56:27 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/24 21:00:24 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool	exec_prio_cmd(t_mini *ms, int *i);
static void		handle_and_op(t_mini *ms, int *i, t_bool *res);
static void		handle_or_op(t_mini *ms, int *i, t_bool *res);
static t_bool	exec_with_pipe(t_mini *ms, int *i, int count, int save_fd);

/*============================================================================*/

int	exec_cmds(t_mini *ms)
{
	int	i;

	if (!ms->cmds)
		return (FAIL);
	i = -1;
	while (++i < ms->elem_pars->nb_cmd)
	{
		if (!ms->cmds[i]->first->and_op && !ms->cmds[i]->first->or_op
			&& !ms->cmds[i]->first->pipe_op)
			exec_simple_cmd(ms->cmds[i], ms->env);
		else if (ms->cmds[i]->first->and_op || ms->cmds[i]->first->or_op)
			exec_prio_cmd(ms, &i);
		else if (ms->cmds[i]->first->pipe_op)
			exec_with_pipe(ms, &i, 1, STDOUT_FILENO);
		i ++;
	}
	return (SUCCESS);
}

static t_bool	exec_with_pipe(t_mini *ms, int *i, int count, int save_fd)
{
	t_pipes	pipes;

	pipes.save_fd = save_fd;
	if (!ms->cmds[*i] || pipe(pipes.fd) == -1)
		return (FAIL);
	pipes.pid = fork();
	if (pipes.pid == -1)
		return (close_pipe(pipes.fd), FAIL);
	if (pipes.pid == 0)
		exec_child(ms, i, count, &pipes);
	close_pipe(pipes.fd);
	(*i)++;
	if (count > 0)
		exec_with_pipe(ms, i, count - 1, pipes.fd[0]);
	if (waitpid(pipes.pid, NULL, 0) == -1)
		return (FAIL);
	return (SUCCESS);
}

static t_bool	exec_prio_cmd(t_mini *ms, int *i)
{
	t_bool	res;

	res = exec_simple_cmd(ms->cmds[(*i)], ms->env);
	while (((*i) + 1) < ms->elem_pars->nb_cmd)
	{
		if (ms->cmds[(*i)]->first->and_op)
			handle_and_op(ms, i, &res);
		else if (ms->cmds[(*i)]->first->or_op)
			handle_or_op(ms, i, &res);
		else
			return (SUCCESS);
	}
	return (FAIL);
}

static void	handle_and_op(t_mini *ms, int *i, t_bool *res)
{
	if (*res == FAIL)
		while (ms->cmds[(*i)]->first->and_op && (*i) < ms->elem_pars->nb_cmd)
			(*i)++;
	else
		*res = exec_simple_cmd(ms->cmds[++(*i)], ms->env);
}

static void	handle_or_op(t_mini *ms, int *i, t_bool *res)
{
	if (*res == SUCCESS)
		while (ms->cmds[(*i)]->first->or_op && (*i) < ms->elem_pars->nb_cmd)
			(*i)++;
	else
		*res = exec_simple_cmd(ms->cmds[++(*i)], ms->env);
}
