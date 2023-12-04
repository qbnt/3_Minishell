/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:41:36 by qbanet            #+#    #+#             */
/*   Updated: 2023/12/04 21:46:29 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**save_files_redir(t_pars *tmp, t_elem_pars *elem_pars);
static void	make_redir(t_pars **cmd, char **files, t_mini *ms);
static void	siple_redir(char *redirtype, char *file);
static void	dredir_stdin(char *file);

/*============================================================================*/

void	redirections(t_pars **cmd, t_mini *ms)
{
	char	**file;
	t_pars	*tmp;
	int		i;

	tmp = *cmd;
	i = 0;
	i += 0;
	file = save_files_redir(tmp, ms->elem_pars);
	make_redir(cmd, file, ms);
	free_dtab(file);
}

static char	**save_files_redir(t_pars *tmp, t_elem_pars *elem_pars)
{
	char	**files;
	int		i;

	files = ft_calloc(all_redir_add(elem_pars) + 1, sizeof(char *));
	i = -1;
	while (tmp)
	{
		if (ft_strcmp(tmp->str, ">") || ft_strcmp(tmp->str, "<")
			|| ft_strcmp(tmp->str, ">>") || ft_strcmp(tmp->str, "<<"))
			files[++i] = find_redir_dir(&tmp);
		tmp = tmp->next;
	}
	return (files);
}

static void	make_redir(t_pars **cmd, char **files, t_mini *ms)
{
	int	i;

	i = 0;
	ms += 0;
	while (*cmd)
	{
		if ((*cmd)->token == REDIR || (*cmd)->token == RE_IN)
			siple_redir((*cmd)->str, files[i++]);
		else if ((*cmd)->token == RE_OUT)
			dredir_stdin(files[i++]);
		*cmd = (*cmd)->next;
	}
}

static void	siple_redir(char *redirtype, char *file)
{
	if (ft_strcmp(redirtype, ">"))
		sredir_out(file);
	else if (ft_strcmp(redirtype, ">>"))
		dredir_out(file);
	else if (ft_strcmp(redirtype, "<"))
		sredir_in(file);
}

static void	dredir_stdin(char *delimiter)
{
	char	*line;

	if (*delimiter == 0)
	{
		printf("syntax error near unexpected token `newline'\n");
		_exit(FAIL);
	}
	printf("deli = %s\n", delimiter);
	while (1)
	{
		write(1, "> ", 2);
		line = get_next_line(STDIN_FILENO);
		if (ft_strcmp(line, delimiter) == FALSE)
		{
			free(line);
			break ;
		}
		free(line);
	}
}

