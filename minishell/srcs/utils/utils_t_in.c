/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_t_in.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:44:22 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/19 16:31:34 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*----------------------------------------------------------------------------*/

//Initiallise la premiere node d'un t_in avec le char c.
t_in	*t_in_first(t_in *first, char c, int group)
{
	if (!first)
	{
		first = malloc(sizeof(t_in));
		first->prev = NULL;
		first->next = NULL;
		first->first = first;
		first->c = c;
		first->group = group;
		first->id = 0;
		return (first);
	}
	else
		return (perror("t_in * already set\n"), first);
}

//Ajoute une node a un t_in avec le char c et retourne la node d'apres.
t_in	*t_in_add_back(t_in *in, char c, int group)
{
	t_in	*next;

	if (!in)
		return (perror("t_in * is NULL\n"), NULL);
	next = malloc(sizeof(t_in));
	next->first = in->first;
	in->next = next;
	next->prev = in;
	next->next = NULL;
	next->c = c;
	next->group = group;
	next->id = next->prev->id + 1;
	return (next);
}

void	free_t_in(t_in *pars)
{
	t_in	*node;

	node = pars;
	while (pars)
	{
		node = node->next;
		free (pars);
		pars = node;
	}
}
