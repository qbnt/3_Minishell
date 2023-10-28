/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:25:50 by qbanet            #+#    #+#             */
/*   Updated: 2023/10/28 15:50:02 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*----------------------------------------------------------------------------*/

static t_token	pick_token(char c);

/*----------------------------------------------------------------------------*/

// Prends la ligne que retourne ReadLine et retourne la premiere node de la
//liste cree.
t_pars	*set_str_to_t_pars(char *str)
{
	t_pars	*oui;
	t_pars	*first_node;

	oui = NULL;
	oui = t_pars_first(oui, *str);
	first_node = oui;
	oui->token = pick_token(oui->c);
	while (*(str + 1))
	{
		str ++;
		oui = t_pars_add_back(oui, *str);
		oui->token = pick_token(oui->c);
	}
	return (first_node);
}

// Fonction de set_str_to_t_pars, détermine le token attenant a un caractère.
static t_token	pick_token(char c)
{
	if (c == 39)
		return (SQUOTE);
	else if (c == 34)
		return (DQUOTE);
	else if (c == '|')
		return (PIPE);
	else if (c == '>')
		return (SUP);
	else if (c == '<')
		return (INF);
	else if (c == '$')
		return (DOL);
	else if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\r'
		|| c == '\f')
		return (NO_TOKEN);
	else if (ft_isprint(c))
		return (LTR);
	else
		return (ERR);
}
/*
// Prends le premier maillon d'un t_pars * avec tokens et reforme les arguments
//dans un t_l_args qu'il retourne.
t_l_args	*set_pars_to_l_args(t_pars *pars)
{
	t_l_args	*full_cmd;
	t_l_args	*first_node;

	full_cmd = NULL;
	t_l_args_first(full_cmd);
	first_node = full_cmd;
	while (pars->token == NO_TOKEN)
	{
		pars = pars->next;
		free(pars->prev);
		pars->prev = NULL;
	}
	while (pars)
	{
		t_l_args_add_next(pars, full_cmd);
		free_t_pars_prev(pars);
	}
	return (first_node);
}
*/
