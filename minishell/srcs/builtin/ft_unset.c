/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:56:10 by qbanet            #+#    #+#             */
/*   Updated: 2023/12/08 11:17:54 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	remove_env(t_env_elems **node);

/*============================================================================*/

int	ft_unset(t_env **env, t_pars *cmd)
{
	t_env_elems	*tmp;
	t_env_elems	*save;

	tmp = (*env)->env_elems;
	save = tmp->first;
	cmd = cmd->next;
	while (cmd)
	{
		while (tmp && !ft_strcmp(tmp->key, cmd->str))
			tmp = tmp->next;
		if (tmp && ft_strcmp(tmp->key, cmd->str))
			remove_env(&(tmp));
		tmp = save;
		cmd = cmd->next;
	}
	return (SUCCESS);
}

static int	remove_env(t_env_elems **node)
{
	t_env_elems	*tmp;

	if (!node || !*node)
		return (FAIL);
	tmp = *node;
	if (tmp->prev)
	{
		if (tmp->next)
		{
			tmp->next->prev = tmp->prev;
			tmp->prev->next = tmp->next;
		}
		tmp->prev->next = NULL;
	}
	else if (tmp->next)
	{
		tmp->next->prev = NULL;
	}
	free(tmp->key);
	free(tmp->value);
	free(tmp);
	*node = NULL;
	return (SUCCESS);
}
