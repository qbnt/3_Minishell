/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:17:57 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/28 16:15:17 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*============================================================================*/

void	exec_child(t_pars *cmd, t_bool end, t_mini *ms)
{
	if (!end)
		dup2(ms->pipes->pipes[1], STDOUT_FILENO);
	else
		dup2(ms->pipes->saved_fd_out, STDOUT_FILENO);
	close(ms->pipes->pipes[0]);
	close(ms->pipes->pipes[1]);
	if (ft_strcmp(cmd->str, "echo"))
		ms->res = ft_echo(cmd);
	else if (ft_strcmp(cmd->str, "pwd"))
		ms->res = ft_pwd();
	else if (ft_strcmp(cmd->str, "env"))
		ms->res = ft_env(ms->env);
	else if (ft_strcmp(cmd->str, "cd"))
		ms->res = ft_cd(cmd, ms->env);
	else
		select_syst_cmd(cmd, ms->env);
	return ;
}

void	ft_waitpid(t_mini *ms)
{
	int	i;

	i = -1;
	while (++i < ms->elem_pars->nb_cmd && ms->pipes->pid[i])
	{
		waitpid(ms->pipes->pid[i], &(ms->pipes->status), 0);
		if (WIFEXITED(ms->pipes->status))
			ms->res = WEXITSTATUS(ms->pipes->status);
	}
}
