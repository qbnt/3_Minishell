/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:17:57 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/24 20:56:32 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*============================================================================*/

void	exec_child(t_mini *ms, int *i, int count, t_pipes *pipes)
{
	dup2(pipes->save_fd, STDIN_FILENO);
	printf("%d exec %s\n", *i, ms->cmds[(*i)]->str);
	if (count)
		dup2(pipes->fd[1], STDOUT_FILENO);
	close_pipe(pipes->fd);
	if (count)
		exec_simple_cmd(ms->cmds[(*i)], ms->env);
	else
	{
		exec_simple_cmd(ms->cmds[(*i) + 1], ms->env);
		_exit(SUCCESS);
	}
}

void	close_pipe(int *fd)
{
	close(fd[0]);
	close(fd[1]);
}
