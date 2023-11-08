/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:25:50 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/07 11:25:25 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	while (*(str + 1))
	{
		str ++;
		oui = t_pars_add_back(oui, *str);
	}
	return (first_node);
}

// Prends le premier maillon d'un t_pars * avec tokens et reforme les arguments
//dans un t_l_args qu'il retourne.
t_l_args	*set_pars_to_l_args(t_pars *pars)
{
	t_l_args	*full_cmd;
	t_l_args	*first_node;
	t_pars		*first_pars;

	first_pars = pars;
	full_cmd = t_l_args_first(&pars);
	first_node = full_cmd;
	while (pars)
	{
		t_l_args_add_next(&pars, full_cmd);
		full_cmd = full_cmd->next;
	}
	while (full_cmd)
	{
		full_cmd->token = t_l_args_pick_token(&pars, full_cmd);
		full_cmd = full_cmd->prev;
	}
	free_t_pars(first_pars);
	return (first_node);
}
