/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_t_pars_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:10:01 by qbanet            #+#    #+#             */
/*   Updated: 2023/12/04 12:12:19 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool	verif_star(char *str);
static t_pars	*change_star(t_pars **cmd);

/*============================================================================*/

void	t_pars_remove_node(t_pars **node)
{
	t_pars	*tmp;

	if (!node || !*node)
		return ;
	tmp = *node;
	if (tmp->prev)
	{
		if (tmp->next)
			tmp->next->prev = tmp->prev;
		tmp->prev->next = tmp->next;
	}
	else if (tmp->next)
	{
		tmp->next->prev = NULL;
	}
	free(tmp->str);
	free(tmp);
	*node = NULL;
}


t_pars	*t_pars_switch_node(t_pars **old_node, t_pars **new_list)
{
	t_pars	*old;
	t_pars	*new_start;
	t_pars	*new_end;

	if (!old_node || !new_list || !*old_node || !*new_list)
		return ((*old_node));
	old = *old_node;
	new_start = *new_list;
	new_end = new_start;
	if (new_end && new_end->next && new_end->next->next)
		while (new_end->next->next)
			new_end = new_end->next;
	if (old->prev)
	{
		old->prev->next = new_start;
		new_start->prev = old->prev;
	}
	else
		*old_node = new_start;
	if (old->next)
	{
		old->next->prev = new_end;
		new_end->next = old->next;
	}
	return (free(old->str), free(old), new_start);
}



void	verif_wc(t_pars **cmd)
{
	t_pars	*tmp;

	tmp = *cmd;
	while ((*cmd))
	{
		if ((*cmd)->token != LIT_STR)
		{
			if (verif_star((*cmd)->str) == TRUE)
				(*cmd) = change_star(cmd);
		}
		(*cmd) = (*cmd)->next;
	}
	*cmd = tmp;
}

static t_bool	verif_star(char *str)
{
	while (*str)
	{
		if (*str == '*')
			return (TRUE);
		str ++;
	}
	return (FALSE);
}

static t_pars	*change_star(t_pars **cmd)
{
	t_dir	dir;

	dir.d = opendir(getcwd(dir.tmp, 250));
	if (!dir.d)
		return (closedir(dir.d), (*cmd));
	dir.dir = readdir(dir.d);
	dir.dir_lst = dir_lst_create(*cmd, TRUE);
	if (star_ok(dir.dir->d_name, (*cmd)->str) == TRUE)
		dir_lst_add(dir.dir->d_name, dir.dir_lst);
	while (dir.dir)
	{
		if (star_ok(dir.dir->d_name, (*cmd)->str) == TRUE)
		{
			dir_lst_add(dir.dir->d_name, dir.dir_lst);
			dir.dir_lst = dir.dir_lst->next;
		}
		dir.dir = readdir(dir.d);
	}
	closedir(dir.d);
	dir.dir_lst = dir.dir_lst->prev;
	if (dir.dir_lst && dir.dir_lst->next)
		t_pars_remove_node(&dir.dir_lst->next);
	if (dir.dir_lst && dir.dir_lst->first && dir.dir_lst->first->str != 0)
		return (t_pars_switch_node(cmd, &dir.dir_lst->first));
	return (free(dir.dir_lst), dir.dir_lst->first);
}
