/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:26:25 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/16 15:03:33 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*----------------------------------------------------------------------------*/

void	pars_is_pipe(char **input, t_elem_pars **oui)
{
	(*oui)->nb_pipe ++;
	(*input)++;
	while (**input && ft_is_whitespace(**input))
		(*input)++;
	if (*(*input + 1))
		(*oui)->nb_cmd ++;
}

void	pars_is_and_op(char **input, t_elem_pars **oui)
{
	if (*(*input + 1) != '&' && *(*input - 1) != '&'
		&& ((*oui)->nb_scote % 2 == 0 && (*oui)->nb_dcote % 2 == 0))
		(*oui)->nb_and_char ++;
	else if ((ft_strncmp(*input, "&&", 2))
		&& ((*oui)->nb_scote % 2 == 0 && (*oui)->nb_dcote % 2 == 0))
	{
		(*oui)->nb_and_op ++;
		if (*(*input + 2))
		{
			(*input) += 2;
			while (**input && ft_is_whitespace(**input))
				(*input)++;
			if (*(*input + 1))
				(*oui)->nb_cmd ++;
		}
	}
}
