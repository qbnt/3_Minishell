/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:17:57 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/27 09:31:15 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*============================================================================*/

void	exec_child(t_mini *ms, int i, int **pipes, int index)
{
	ms += 0;
	i += 0;
	pipes += 0;
	index += 0;
	printf("Bonjour de l'enfant\n");
}

int	ft_pipelen(t_pars **cmds, int i)
{
	int	len;

	len = 0;
	while (cmds[i] && cmds[i]->pipe_op == TRUE)
	{
		len ++;
		i ++;
	}
	return (len);
}

t_pipes	*init_pipe(int pipelen)
{
	t_pipes	*pipes;
	int		i;

	pipes = ft_calloc(1, sizeof(t_pipes));
	pipes->pipes = ft_calloc(pipelen, sizeof(int *));
	pipes->pid = ft_calloc(pipelen, sizeof(int));
	pipes->saved_fd = dup(STDOUT_FILENO);
	i = -1;
	while (++i < pipelen)
	{
		pipes->pipes[i] = ft_calloc(2, sizeof(int));
		pipe(pipes->pipes[i]);
	}
	return (pipes);
}
