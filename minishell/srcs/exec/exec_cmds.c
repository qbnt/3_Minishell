/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:56:27 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/22 22:54:35 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	exec_simple_cmd(t_pars *cmd, t_env *env);
static void	select_syst_cmd(t_pars *cmd, t_env *env);

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
		i ++;
	}
}

static void	exec_simple_cmd(t_pars *cmd, t_env *env)
{
	if (!ft_strncmp(cmd->str, "echo", 4))
		ft_echo(cmd);
	else if (!ft_strncmp(cmd->str, "pwd", 3))
		ft_pwd();
	else if (!ft_strncmp(cmd->str, "exit", 4))
		ft_exit();
	else
		select_syst_cmd(cmd, env);
}

static void	select_syst_cmd(t_pars *cmd, t_env *env)
{
	char	*path;
	char	**tab_cmd;

	path = get_cmd_path(cmd->str, env->env_elems);
	tab_cmd = get_dtab_cmd(cmd);
	if (!path)
		return (printf("cmd not found\n"), (void) 0);
	execve(path, tab_cmd, env->env_cpy);
	free (tab_cmd);
}
