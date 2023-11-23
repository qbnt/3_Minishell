/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:56:27 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/23 15:41:20 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	exec_simple_cmd(t_pars *cmd, t_env *env);
static void	exec_prio_cmd(t_mini *ms, int *i);

/*============================================================================*/

void	exec_cmds(t_mini *ms)
{
	int	i;

	i = 0;
	while (i < ms->elem_pars->nb_cmd)
	{
		if (!ms->cmds[i]->and_op
			&& !ms->cmds[i]->or_op
			&& !ms->cmds[i]->pipe_op)
			exec_simple_cmd(ms->cmds[i], ms->env);
		else if (ms->cmds[i]->first->and_op || ms->cmds[i]->first->or_op)
			exec_prio_cmd(ms, &i);
		i ++;
	}
}

static t_bool	exec_simple_cmd(t_pars *cmd, t_env *env)
{
	t_bool	res;

	if (ft_strcmp(cmd->str, "echo"))
		res = ft_echo(cmd);
	else if (ft_strcmp(cmd->str, "pwd"))
		res = ft_pwd();
	else if (ft_strcmp(cmd->str, "exit"))
		ft_exit();
	else
		res = select_syst_cmd(cmd, env);
	return (res);
}

static void	exec_prio_cmd(t_mini *ms, int *i)
{
	t_bool	res;

	res = exec_simple_cmd(ms->cmds[(*i)], ms->env);
	while (*i < ms->elem_pars->nb_cmd)
	{
		if (ms->cmds[((*i))]->first->and_op)
		{
			if (res == FAIL)
			{
				(*i)++;
				break ;
			}
			res = exec_simple_cmd(ms->cmds[++(*i)], ms->env);
		}
		else if (ms->cmds[((*i))]->first->or_op)
		{
			if (res == SUCCESS)
			{
				(*i)++;
				break ;
			}
			res = exec_simple_cmd(ms->cmds[++(*i)], ms->env);
		}
		(*i)++;
	}
}
