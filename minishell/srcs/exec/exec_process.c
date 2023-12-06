/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <qpuig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:17:57 by qbanet            #+#    #+#             */
/*   Updated: 2023/12/05 15:54:02 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_child(t_mini *ms);

/*============================================================================*/

void	exec_child(t_pars *cmd, t_bool end, t_mini *ms)
{
	int	res;
	char	*a;

	if (!end)
		dup2(ms->pipes->pipes[1], STDOUT_FILENO);
	else
		dup2(ms->pipes->saved_fd_out, STDOUT_FILENO);
	close(ms->pipes->pipes[0]);
	close(ms->pipes->pipes[1]);
	if (ft_strcmp(cmd->str, "echo"))
		res = ft_echo(cmd);
	else if (ft_strcmp(cmd->str, "pwd"))
		res = ft_pwd();
	else if (ft_strcmp(cmd->str, "env"))
		res = ft_env(ms->env);
	else if (ft_strcmp(cmd->str, "cd"))
		res = ft_cd(cmd, ms->env);
	else if (ft_strcmp(cmd->str, "export"))
		res = ft_export(cmd, ms->env);
	else
		res = select_syst_cmd(cmd, ms->env);
	a = ft_calloc(4097, sizeof(char));
	getcwd(a, 4096);
	ft_printf("%s\n", a);
	free(a);
	free_child(ms);
	_exit(res);
}

void	exec_parent(t_pars *cmd, t_bool end, t_mini *ms, int i)
{
	if (!end)
	{
		dup2(ms->pipes->pipes[0], STDIN_FILENO);
	}
	else
	{
		dup2(ms->pipes->saved_fd_in, STDIN_FILENO);
		if (cmd->first->and_op || cmd->first->or_op)
		{
			waitpid(ms->pipes->pid[i], &(ms->pipes->status), 0);
			if (WIFEXITED(ms->pipes->status))
				ms->res = WEXITSTATUS(ms->pipes->status);
		}
		else
			ft_waitpid(ms);
	}
}

void	ft_waitpid(t_mini *ms)
{
	int	i;

	i = -1;
	while (ms->pipes->pid[++i] != 0)
	{
		waitpid(ms->pipes->pid[i], &(ms->pipes->status), 0);
		if (WIFEXITED(ms->pipes->status))
			ms->res = WEXITSTATUS(ms->pipes->status);
	}
}

static void	free_child(t_mini *ms)
{
	free_cmds_tab(ms->cmds, ms->elem_pars->nb_cmd);
	free_pipes(ms->pipes);
	free(ms->elem_pars);
	free_all(ms);
}
