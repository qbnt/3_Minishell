/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:56:10 by qbanet            #+#    #+#             */
/*   Updated: 2023/12/06 15:26:12 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	remove_env(t_env_elems **node);

/*============================================================================*/

int	ft_unset(t_env **env, t_pars *cmd)
{
	t_env_elems	*tmp;

	tmp = (*env)->env_elems;
	while (tmp && !ft_strcmp(tmp->key, cmd->next->str))
		tmp = tmp->next;
	if (tmp && ft_strcmp(tmp->key, cmd->next->str))
		remove_env(&tmp);
	else
		return (3);
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
			tmp->next->prev = tmp->prev;
		tmp->prev->next = tmp->next;
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
