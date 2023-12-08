/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_types.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:59:46 by qbanet            #+#    #+#             */
/*   Updated: 2023/12/08 11:39:32 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*============================================================================*/

void	sredir_out(char *file)
{
	int	fd;

	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	dup2(fd, STDOUT_FILENO);
	close(fd);
}

void	dredir_out(char *file)
{
	int	fd;

	fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	dup2(fd, STDOUT_FILENO);
	close(fd);
}

void	sredir_in(char *file, t_mini *ms, char *save)
{
	int		fd;

	ms += 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("bash: %s: No such file or directory\n", file);
		if (is_builtin(save))
			return ;
		_exit(FAIL);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
}
