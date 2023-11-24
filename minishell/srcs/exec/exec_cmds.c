/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <qpuig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:56:27 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/24 14:57:56 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		exec_simple_cmd(t_pars *cmd, t_env *env);
static t_bool	exec_prio_cmd(t_mini *ms, int *i);

/*============================================================================*/

void	exec_cmds(t_mini *ms)
{
	int	i;

	i = 0;
	while (i < ms->elem_pars->nb_cmd)
	{
		if (!ms->cmds[i]->and_op && !ms->cmds[i]->or_op
			&& !ms->cmds[i]->pipe_op)
			exec_simple_cmd(ms->cmds[i++], ms->env);
		else if (ms->cmds[i]->first->and_op || ms->cmds[i]->first->or_op)
			if (exec_prio_cmd(ms, &i) == FAIL)
				break ;
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
	else if (ft_strcmp(cmd->str, "env"))
		ft_env(env);
	else if (ft_strcmp(cmd->str, "cd"))
		ft_cd(cmd, env);
	else
		res = select_syst_cmd(cmd, env);
	return (res);
}

static t_bool	exec_prio_cmd(t_mini *ms, int *i)
{
	t_bool	res;

	res = exec_simple_cmd(ms->cmds[(*i)], ms->env);
	while (((*i) + 1) < ms->elem_pars->nb_cmd)
	{
		if (ms->cmds[((*i))]->first->and_op)
		{
			if (res == FAIL)
			{
				while (ms->cmds[((*i))]->first->and_op)
					(*i)++;
				if ((*i) + 1 >= ms->elem_pars->nb_cmd)
					return (FAIL);
			}
			res = exec_simple_cmd(ms->cmds[++(*i)], ms->env);
		}
		else if (ms->cmds[((*i))]->first->or_op)
		{
			if (res == SUCCESS)
				return (FAIL);
			res = exec_simple_cmd(ms->cmds[++(*i)], ms->env);
			while (ms->cmds[((*i))]->first->or_op)
				(*i)++;
		}
	}
	(*i)++;
	return (SUCCESS);
}
