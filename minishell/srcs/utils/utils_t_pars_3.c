/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_t_pars_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:04:19 by qbanet            #+#    #+#             */
/*   Updated: 2023/12/04 14:24:47 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool	verif_star(char *prefix, char *suffix, char *name);

/*============================================================================*/

t_pars	*dir_lst_create(t_pars *cmd, t_bool start)
{
	t_pars	*new_node;

	new_node = ft_calloc(1, sizeof(t_pars));
	if (!new_node)
		return (NULL);
	if (start)
		new_node->first = new_node;
	else
		new_node->first = cmd->first;
	new_node->prev = NULL;
	new_node->next = NULL;
	new_node->group = cmd->group;
	new_node->token = cmd->token;
	new_node->and_op = cmd->and_op;
	new_node->or_op = cmd->or_op;
	new_node->pipe_op = cmd->pipe_op;
	return (new_node);
}

void	dir_lst_add(char *str, t_pars *dir_lst)
{
	t_pars	*new_node;

	dir_lst->str = ft_strdup(str);
	if (dir_lst->str == NULL)
		return ;
	new_node = dir_lst_create(dir_lst, FALSE);
	new_node->prev = dir_lst;
	new_node->next = NULL;
	dir_lst->next = new_node;
}

t_bool	star_ok(char *name, char *star)
{
	char	*prefix;
	char	*suffix;
	t_bool	res;
	int		i;
	int		j;

	if (ft_strcmp(name, ".") || ft_strcmp(name, ".."))
		return (FALSE);
	i = 0;
	prefix = NULL;
	suffix = NULL;
	while (star[i] && star[i] != '*')
		i ++;
	prefix = ft_substr(star, 0, i);
	j = 0;
	while (star[i + j])
		j ++;
	suffix = ft_substr(star, i + 1, j);
	res = verif_star(prefix, suffix, name);
	return (free(prefix), free(suffix), res);
}

static t_bool	verif_star(char *prefix, char *suffix, char *name)
{
	t_bool	res;

	if (prefix)
	{
		if (!ft_strncmp(prefix, name, ft_strlen(prefix)))
			res = TRUE;
		else
			return (FALSE);
	}
	if (suffix)
	{
		if (!ft_strnrcmp(name, suffix, ft_strlen(suffix)))
			res = TRUE;
		else
			return (FALSE);
	}
	return (res);
}

void	init_change_star(t_pars **cmd, t_dir *dir)
{
	dir->dir = readdir(dir->d);
	dir->dir_lst = dir_lst_create(*cmd, TRUE);
	if (star_ok(dir->dir->d_name, (*cmd)->str) == TRUE)
	{
		dir_lst_add(dir->dir->d_name, dir->dir_lst);
		dir->dir_lst = dir->dir_lst ->next;
		dir->dir = readdir(dir->d);
	}
}
