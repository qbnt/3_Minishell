/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:56:27 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/28 17:44:40 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool	exec_prio_cmd(t_mini *ms, int *i);
static void		handle_and_op(t_mini *ms, int *i);
static void		handle_or_op(t_mini *ms, int *i);

/*============================================================================*/

int	exec_cmds(t_mini *ms)
{
	int	i;

	ms->pipes = init_pipes(ms);
	if (!ms->cmds)
		return (FAIL);
	i = 0;
	while (i < ms->elem_pars->nb_cmd)
	{
		printf("cmd = %s	| i = %d\n", ms->cmds[i]->str, i);
		if (ms->cmds[i]->first->and_op || ms->cmds[i]->first->or_op)
			exec_prio_cmd(ms, &i);
		else if (ms->cmds[i]->first->pipe_op)
		{
			TEST1 ;
			if (ms->pipes->nb_pipes --)
			{
				printf("nb pipe = %d cmd in pipe = %s\n\n", ms->pipes->nb_pipes, ms->cmds[i]->str);
				exec_simple_cmd(ms->cmds[i], ms, 0);
			}
			else
				exec_simple_cmd(ms->cmds[i], ms, 1);
		}
		else
			exec_simple_cmd(ms->cmds[i], ms, 1);
		++i;
	}
	return (SUCCESS);
}

static t_bool	exec_prio_cmd(t_mini *ms, int *i)
{
	exec_simple_cmd(ms->cmds[(*i)], ms, 1);
	while ((*i) < ms->elem_pars->nb_cmd)
	{
		if (ms->cmds[(*i)]->first->and_op)
			handle_and_op(ms, i);
		else if (ms->cmds[(*i)]->first->or_op)
			handle_or_op(ms, i);
		else
			return (printf("cmd in handle = %s\n", ms->cmds[*i]->str), --(*i), SUCCESS);
	}
	return (FAIL);
}

static void	handle_and_op(t_mini *ms, int *i)
{
	++(*i);
	if (ms->res != 0)
	{
		while ((ms->cmds[(*i)]->first->and_op || ms->cmds[(*i)]->first->pipe_op)
			&& (*i) < ms->elem_pars->nb_cmd)
			(*i)++;
		if (ms->cmds[(*i) - 1]->first->pipe_op)
			(*i)++;
	}
	else
		return ;
}

static void	handle_or_op(t_mini *ms, int *i)
{
	++(*i);
	if (ms->res == SUCCESS)
	{
		while ((ms->cmds[(*i)]->first->or_op || ms->cmds[(*i)]->first->pipe_op)
		&& (*i) < ms->elem_pars->nb_cmd)
			++(*i);
		if (ms->cmds[(*i) - 1]->pipe_op)
			++(*i);
	}
	else
		return ;
}
