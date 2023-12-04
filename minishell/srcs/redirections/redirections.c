/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:41:36 by qbanet            #+#    #+#             */
/*   Updated: 2023/12/04 17:55:38 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**save_files_redir(t_pars *tmp, t_elem_pars *elem_pars);
static void	make_redir(t_pars *cmd, char **files);

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
	make_redir(*cmd, file);
	ft_print_t_pars((*cmd)->first);
	free_dtab(file);
}

static char	**save_files_redir(t_pars *tmp, t_elem_pars *elem_pars)
{
	char	**files;
	int		i;

	files = ft_calloc(all_redir_add(elem_pars) + 1, sizeof(char *));
	i = 0;
	while(tmp)
	{
		if (ft_strcmp(tmp->str, ">") || ft_strcmp(tmp->str, "<")
			|| ft_strcmp(tmp->str, ">>") || ft_strcmp(tmp->str, "<<"))
		{
			files[i] = find_redir_dir(&tmp);
			printf("redir = %s et file = %s\n", tmp->str, files[i]);
			i ++;
		}
		tmp = tmp->next;
	}
	return (files);
}

static void	make_redir(t_pars *cmd, char **files)
{

}
