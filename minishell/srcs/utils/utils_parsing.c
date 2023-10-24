/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:25:50 by qbanet            #+#    #+#             */
/*   Updated: 2023/10/24 14:56:43 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	pick_token(t_pars *pars, t_token current_token);

/*----------------------------------------------------------------------------*/

// Prends la ligne que retourne ReadLine et retourne la premiere node de la
//liste cree.
t_pars	*set_str_to_t_pars(char *str)
{
	t_pars	*oui;
	t_pars	*first_node;

	oui = NULL;
	oui = pars_first(oui, *str);
	first_node = oui;
	while (*str)
	{
		str ++;
		oui = pars_add_back(oui, *str);
	}
	return (first_node);
}

// Prends un t_pars * sans tokens et la parcourt pour faire la tokennisation.
void	set_token_in_t_pars(t_pars *pars)
{
	t_token	current_token;

	current_token = NO_TOKEN;
	while (ft_is_whitespace(pars->c))
		pars = pars->next;
	while (pars)
	{
		pick_token(pars, current_token);
		pars->token = current_token;
		pars = pars->next;
	}
}

// Fonction de set_token_in_t_pars, détermine le token attenant a un caractère.
static void	pick_token(t_pars *pars, t_token current_token)
{
	
}

// Prends un t_pars * avec tokens et reforme les arguments dans un t_l_args
//qu'il retourne.
t_l_args	*set_pars_to_l_args(t_pars *pars)
{
	
}
