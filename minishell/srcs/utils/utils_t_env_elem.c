/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_t_env_elem.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 11:49:47 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/30 15:52:26 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*============================================================================*/

t_env_elems	*t_env_elems_first(char *key, char *value)
{
	t_env_elems	*oui;

	oui = malloc(sizeof(t_env_elems));
	oui->first = oui;
	oui->prev = NULL;
	oui->next = NULL;
	oui->key = ft_strdup(key);
	free(key);
	oui->key_len = ft_strlen(oui->key);
	oui->value = ft_strdup(value);
	free(value);
	oui->value_len = ft_strlen(oui->value);
	return (oui);
}

void	t_env_elems_next(t_env_elems *env_elems, char *key, char *value)
{
	t_env_elems	*oui;

	oui = malloc(sizeof(t_env_elems));
	oui->first = env_elems->first;
	oui->prev = env_elems;
	oui->next = NULL;
	oui->key = ft_strdup(key);
	free(key);
	oui->key_len = ft_strlen(oui->key);
	oui->value = ft_strdup(value);
	free(value);
	oui->value_len = ft_strlen(oui->value);
	env_elems->next = oui;
	env_elems = oui;
}

char	*t_env_elems_find_value_of(t_env_elems *env_elems, char *key)
{
	char	*value;

	if (!key)
		return (0);
	value = ft_calloc(sizeof(char), 1);
	while (env_elems && !ft_strcmp(env_elems->key, key))
		env_elems = env_elems->next;
	if (env_elems)
		value = ft_strdup(env_elems->value);
	return (value);
}

void	t_env_elems_free(t_env_elems *first)
{
	t_env_elems	*tmp;

	tmp = first;
	while (first)
	{
		tmp = tmp->next;
		free (first->key);
		free (first->value);
		free (first);
		first = tmp;
	}
}
