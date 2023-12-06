/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:45:21 by qbanet            #+#    #+#             */
/*   Updated: 2023/12/06 10:48:25 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*============================================================================*/

t_bool	redir_in_cmd(t_pars *cmd)
{
	while (cmd)
	{
		if (cmd->token == REDIR || cmd->token == RE_IN || cmd->token == RE_OUT)
			return (TRUE);
		cmd = cmd->next;
	}
	return (FALSE);
}

char	*find_redir_dir(t_pars **cmd)
{
	t_pars	*dir;
	char	*res_dir;

	dir = *cmd;
	while (dir && (dir->token != REDIR && dir->token != RE_IN
			&& dir->token != RE_OUT))
		dir = dir->next;
	if (dir && dir->next)
	{
		dir = dir->next;
		res_dir = ft_strdup(dir->str);
		t_pars_remove_node(&(dir));
	}
	return (res_dir);
}

int	all_redir_add(t_elem_pars *elem_pars)
{
	int	res;

	res = elem_pars->nb_redir + elem_pars->nb_dredir_in
		+ elem_pars->nb_dredir_out;
	return (res);
}

char	*copy_in(char *delimiter)
{
	char	*line;
	char	*res;

	res = NULL;
	while (1)
	{
		write(1, "> ", 2);
		line = get_next_line(STDIN_FILENO);
		if (!ft_strncmp(line, delimiter, ft_strlen(delimiter))
			&& ft_strlen(delimiter) == ft_strlen(line) - 1)
		{
			free(line);
			break ;
		}
		res = ft_strcat(res, line);
		free(line);
	}
	return (res);
}
