/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:26:25 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/19 23:39:24 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	pars_is_or_op(char **input, t_elem_pars **oui);

/*============================================================================*/

void	pars_is_pipe(char **input, t_elem_pars **oui)
{
	if (((*(*input - 1) != '|' && *(*input + 1) != '|'))
		&& ((*oui)->nb_scote % 2 == 0 && (*oui)->nb_dcote % 2 == 0))
	{
		(*oui)->nb_pipe ++;
		while (*(*input + 1) && ft_is_whitespace(*(*input + 1)))
			(*input)++;
		if (*(*input + 1) && !ft_is_opp(*(*input + 1)))
			(*oui)->nb_cmd ++;
	}
	else if ((!ft_strncmp(*input, "||", 2))
		&& ((*oui)->nb_scote % 2 == 0 && (*oui)->nb_dcote % 2 == 0))
		pars_is_or_op(input, oui);
}

static void	pars_is_or_op(char **input, t_elem_pars **oui)
{
	(*oui)->nb_or_op ++;
	if (*(*input + 2))
	{
		if (*(*input + 2) == '|')
			(*oui)->error = TRUE;
		else
		{
			while (**input && ft_is_whitespace(**input))
				(*input)++;
			if (*(*input + 1))
				(*oui)->nb_cmd ++;
		}
	}
}

void	pars_is_and_op(char **input, t_elem_pars **oui)
{
	if (((*(*input + 1) != '&' && *(*input - 1) != '&')
			|| (*(*input + 1) == '&' && *(*input - 1) == '&'))
		&& ((*oui)->nb_scote % 2 == 0 && (*oui)->nb_dcote % 2 == 0))
		(*oui)->nb_and_char ++;
	else if ((ft_strncmp(*input, "&&", 2))
		&& ((*oui)->nb_scote % 2 == 0 && (*oui)->nb_dcote % 2 == 0))
	{
		(*oui)->nb_and_op ++;
		if (*(*input + 2))
		{
			while (**input && ft_is_whitespace(**input))
				(*input)++;
			if (*(*input + 1))
				(*oui)->nb_cmd ++;
		}
	}
}

t_bool	empty_parenth(char *input)
{
	if (*input == '(' && *(input + 1) == ')')
		return (TRUE);
	else if (*input == '(')
	{
		input += 1;
		while (*input && ft_is_whitespace(*input))
			input += 1;
		if (*input == ')')
			return (TRUE);
	}
	else if (*input == ')')
	{
		input += 1;
		while (*input && ft_is_whitespace(*input))
			input += 1;
		if (*input == '(')
			return (TRUE);
	}
	return (FALSE);
}
