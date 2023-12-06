/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:17:57 by qbanet            #+#    #+#             */
/*   Updated: 2023/12/06 16:30:34 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_child(t_mini *ms);

/*============================================================================*/

void	exec_child(t_pars *cmd, t_bool end, t_mini *ms)
{
	int	res;

	if (!end)
		dup2(ms->pipes->pipes[1], STDOUT_FILENO);
	else
		dup2(ms->pipes->saved_fd_out, STDOUT_FILENO);
	if (redir_in_cmd(cmd))
		redirections(&cmd, ms);
	close(ms->pipes->pipes[0]);
	close(ms->pipes->pipes[1]);
	res = select_syst_cmd(cmd, ms->env);
	free_child(ms);
	_exit(res);
}

void	exec_parent(t_pars *cmd, t_bool end, t_mini *ms, int i)
{
	if (!end)
		dup2(ms->pipes->pipes[0], STDIN_FILENO);
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
		{
			ft_waitpid(ms);
			clear_in_out(ms);
		}
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
