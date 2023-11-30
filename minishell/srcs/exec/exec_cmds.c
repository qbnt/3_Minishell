/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:56:27 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/30 13:33:08 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool		exec_prio_cmd(t_mini *ms, int *i);
static t_bool		handle_and_op(t_mini *ms, int *i, int group1);
static t_bool		handle_or_op(t_mini *ms, int *i, int group1);

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
		if (ms->cmds[i]->first->and_op || ms->cmds[i]->first->or_op)
			exec_prio_cmd(ms, &i);
		else if (ms->cmds[i]->first->pipe_op)
		{
			if (ms->pipes->nb_pipes--)
				exec_simple_cmd(ms->cmds[i++], ms, 0);
			else
				exec_simple_cmd(ms->cmds[i++], ms, 1);
		}
		else
			exec_simple_cmd(ms->cmds[i++], ms, 1);
	}
	return (SUCCESS);
}

static t_bool	exec_prio_cmd(t_mini *ms, int *i)
{
	int	group1;

	group1 = ms->cmds[*i]->first->group;
	exec_simple_cmd(ms->cmds[(*i)++], ms, 1);
	while ((*i) < ms->elem_pars->nb_cmd)
	{
		if (ms->cmds[(*i) - 1]->first->and_op)
			handle_and_op(ms, i, group1);
		else if (ms->cmds[(*i) - 1]->first->or_op)
			handle_or_op(ms, i, group1);
		return (SUCCESS);
	}
	return (FAIL);
}

static t_bool	handle_and_op(t_mini *ms, int *i, int group1)
{
	int	group2;

	if (ms->res != 0)
	{
		while (ms->cmds[(*i)]->first->and_op || ms->cmds[(*i)]->first->pipe_op)
			(*i)++;
		if (ms->cmds[(*i) - 1]->first->pipe_op)
			(*i)++;
		if (group1 != ms->cmds[*i]->first->group)
		{
			group2 = ms->cmds[*i]->first->group;
			while (*i < ms->elem_pars->nb_cmd
				&& group2 == ms->cmds[*i]->first->group)
				++(*i);
		}
		++(*i);
	}
	return (1);
}

static t_bool	handle_or_op(t_mini *ms, int *i, int group1)
{
	int	group2;

	if (ms->res == 0)
	{
		while (ms->cmds[(*i)]->first->or_op || ms->cmds[(*i)]->first->pipe_op)
			++(*i);
		if (ms->cmds[(*i) - 1]->pipe_op)
			++(*i);
		if (group1 != ms->cmds[*i]->first->group)
		{
			group2 = ms->cmds[*i]->first->group;
			while (*i < ms->elem_pars->nb_cmd
				&& group2 == ms->cmds[*i]->first->group)
				++(*i);
		}
		++(*i);
	}
	return (1);
}
