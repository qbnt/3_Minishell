/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:56:27 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/27 13:35:01 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool	exec_prio_cmd(t_mini *ms, int *i);
static void		handle_and_op(t_mini *ms, int *i, t_bool *res);
static void		handle_or_op(t_mini *ms, int *i, t_bool *res);

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
		else if (ms->cmds[i]->first->pipe_op)
			exec_simple_cmd(ms->cmds[i], ms->env);
		else if (ms->cmds[i]->first->and_op || ms->cmds[i]->first->or_op)
			exec_prio_cmd(ms, &i);
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
