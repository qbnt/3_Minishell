/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:17:57 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/28 13:54:35 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*============================================================================*/

void	exec_child(t_pars *cmd, t_pipes *pipes, t_bool end, t_env *env)
{
	if (!end)
		dup2(pipes->pipes[1], STDOUT_FILENO);
	else
		dup2(pipes->saved_fd_out, STDOUT_FILENO);
	close(pipes->pipes[0]);
	close(pipes->pipes[1]);
	if (ft_strcmp(cmd->str, "echo"))
		ft_echo(cmd);
	else if (ft_strcmp(cmd->str, "pwd"))
		ft_pwd();
	else if (ft_strcmp(cmd->str, "env"))
		ft_env(env);
	else if (ft_strcmp(cmd->str, "cd"))
		ft_cd(cmd, env);
	else
		select_syst_cmd(cmd, env);
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
