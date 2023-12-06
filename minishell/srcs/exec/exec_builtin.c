/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:11:48 by qbanet            #+#    #+#             */
/*   Updated: 2023/12/06 16:32:24 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	exec_builtin(t_pars *cmd, t_mini *ms);

/*============================================================================*/

t_bool	is_builtin(char *cmd)
{
	if (ft_strcmp(cmd, "echo") || ft_strcmp(cmd, "cd")
		|| ft_strcmp(cmd, "env") || ft_strcmp(cmd, "exit")
		|| ft_strcmp(cmd, "export") || ft_strcmp(cmd, "pwd")
		|| ft_strcmp(cmd, "exit") || ft_strcmp(cmd, "unset"))
		return (TRUE);
	return (FALSE);
}

void	make_builtin(t_pars *cmd, t_mini *ms, t_bool end)
{
	if (!end)
		dup2(ms->pipes->pipes[1], STDOUT_FILENO);
	else
		dup2(ms->pipes->saved_fd_out, STDOUT_FILENO);
	if (redir_in_cmd(cmd))
		redirections(&cmd, ms);
	exec_builtin(cmd, ms);
	if (!end)
		dup2(ms->pipes->pipes[0], STDIN_FILENO);
	else
		dup2(ms->pipes->saved_fd_in, STDIN_FILENO);
	dup2(ms->pipes->saved_fd_out, STDOUT_FILENO);
	close(ms->pipes->pipes[1]);
	close(ms->pipes->pipes[0]);
	return ;
}

static void	exec_builtin(t_pars *cmd, t_mini *ms)
{
	if (ft_strcmp(cmd->str, "echo"))
		ms->res = ft_echo(cmd);
	else if (ft_strcmp(cmd->str, "exit"))
		ft_exit(cmd, &ms);
	else if (ft_strcmp(cmd->str, "pwd"))
		ms->res = ft_pwd();
	else if (ft_strcmp(cmd->str, "env"))
		ms->res = ft_env(ms->env);
	else if (ft_strcmp(cmd->str, "cd"))
		ms->res = ft_cd(cmd, ms->env);
	else if (ft_strcmp(cmd->str, "export"))
		ms->res = ft_export(cmd, ms->env);
	else if (ft_strcmp(cmd->str, "unset"))
		ms->res = ft_unset(&(ms->env), cmd);
}

void	clear_in_out(t_mini *ms)
{
	dup2(ms->pipes->saved_fd_in, STDIN_FILENO);
	dup2(ms->pipes->saved_fd_out, STDOUT_FILENO);
}
