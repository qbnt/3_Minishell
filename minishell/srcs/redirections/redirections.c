/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:41:36 by qbanet            #+#    #+#             */
/*   Updated: 2023/12/08 11:37:36 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**save_files_redir(t_pars *tmp, t_elem_pars *elem_pars);
static void	make_redir(t_pars **cmd, char **files, t_mini *ms, char *save);
static void	siple_redir(t_pars **cmd, char *file, t_mini *ms, char *save);
static void	dredir_stdin(char *file, t_pars **cmd);

/*============================================================================*/

void	redirections(t_pars **cmd, t_mini *ms)
{
	char	**file;
	t_pars	*save;
	t_pars	*tmp;
	int		i;

	tmp = *cmd;
	save = (*cmd)->first;
	i = 0;
	i += 0;
	file = save_files_redir(tmp, ms->elem_pars);
	make_redir(cmd, file, ms, save->str);
	free_dtab(file);
	(*cmd) = save;
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

static void	make_redir(t_pars **cmd, char **files, t_mini *ms, char *save)
{
	int	i;

	i = 0;
	while (*cmd)
	{
		if ((*cmd)->token == REDIR || (*cmd)->token == RE_IN)
			siple_redir((cmd), files[i++], ms, save);
		else if ((*cmd)->token == RE_OUT)
			dredir_stdin(files[i++], cmd);
		else
			*cmd = (*cmd)->next;
	}
}

static void	siple_redir(t_pars **cmd, char *file, t_mini *ms, char *save)
{
	if (ft_strcmp((*cmd)->str, ">"))
		sredir_out(file);
	else if (ft_strcmp((*cmd)->str, ">>"))
		dredir_out(file);
	else if (ft_strcmp((*cmd)->str, "<"))
		sredir_in(file, ms, save);
	*cmd = t_pars_remove_node(cmd);
}

static void	dredir_stdin(char *delimiter, t_pars **cmd)
{
	char	*res;
	int		r_pipe[2];

	res = NULL;
	if (delimiter && *delimiter == 0)
	{
		printf("syntax error near unexpected token `newline'\n");
		_exit(FAIL);
	}
	if (pipe(r_pipe) == -1)
		_exit(FAIL);
	res = copy_in(delimiter);
	write(r_pipe[1], res, ft_strlen(res));
	close (r_pipe[1]);
	dup2(r_pipe[0], STDIN_FILENO);
	close (r_pipe[0]);
	*cmd = t_pars_remove_node(cmd);
}
