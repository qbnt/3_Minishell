/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:56:27 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/27 11:27:32 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool	exec_prio_cmd(t_mini *ms, int *i);
static void		handle_and_op(t_mini *ms, int *i, t_bool *res);
static void		handle_or_op(t_mini *ms, int *i, t_bool *res);
static t_bool	exec_with_pipe(t_mini *ms, int *i);

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
			exec_with_pipe(ms, &i);
	}
	return (SUCCESS);
}

static t_bool	exec_with_pipe(t_mini *ms, int *i)
{
	t_pipes	*pipes;
	int		pipelen;
	int		j;

	pipelen = ft_pipelen(ms->cmds, *i);
	pipes = init_pipe(pipelen);
	j = -1;
	while (++j < pipelen + 1)
	{
		pipes->pid[pipes->pid_index] = fork();
		if (pipes->pid[pipes->pid_index] == -1)
			return (printf("Error during fork\n"), FAIL);
		else if (pipes->pid[pipes->pid_index] == 0)
		{
			exec_child(ms, *i, pipes->pipes, pipes->pid_index);
			return (SUCCESS);
		}
		else
			(*i)++;
		pipes->pid_index ++;
		wait(NULL);
	}
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
