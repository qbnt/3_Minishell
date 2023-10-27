/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_t_pars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:44:22 by qbanet            #+#    #+#             */
/*   Updated: 2023/10/27 13:43:39 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*----------------------------------------------------------------------------*/

//Initiallise la premiere node d'un t_pars avec le char c.
t_pars	*t_pars_first(t_pars *first, char c)
{
	if (!first)
	{
		first = malloc(sizeof(t_pars));
		first->prev = NULL;
		first->next = NULL;
		first->c = c;
		first->id = 0;
		first->token = NO_TOKEN;
		return (first);
	}
	else
		return (perror("t_pars * already set\n"), first);
}

//Ajoute une node a un t_pars avec le char c et retourne la node d'apres.
t_pars	*t_pars_add_back(t_pars *pars, char c)
{
	t_pars	*next;

	if (!pars)
		return (perror("t_pars * is NULL\n"), NULL);
	next = malloc(sizeof(t_pars));
	pars->next = next;
	next->prev = pars;
	next->c = c;
	next->id = pars->id ++;
	next->token = NO_TOKEN;
	return (next);
}
