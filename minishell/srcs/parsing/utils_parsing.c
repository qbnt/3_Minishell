/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:26:25 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/27 13:32:09 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	pars_is_or_op(char **input, t_elem_pars **oui);
static void	pars_is_dredir(char **input, t_elem_pars **oui);

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

void	pars_is_redir(char **input, t_elem_pars **oui)
{
	if (((*(*input - 1) != **input && *(*input + 1) != **input))
		&& ((*oui)->nb_scote % 2 == 0 && (*oui)->nb_dcote % 2 == 0))
	{
		(*oui)->nb_redir ++;
		while (*(*input + 1) && ft_is_whitespace(*(*input + 1)))
			(*input)++;
		if (*(*input + 1) && (*(*input + 1) == '<' || *(*input + 1) == '>'))
			(*oui)->error = TRUE;
	}
	if ((!ft_strncmp(*input, ">>", 2) || !ft_strncmp(*input, "<<", 2))
		&& ((*oui)->nb_scote % 2 == 0 && (*oui)->nb_dcote % 2 == 0))
		pars_is_dredir(input, oui);
}

static void	pars_is_dredir(char **input, t_elem_pars **oui)
{
	if (!ft_strncmp(*input, "<<", 2))
		(*oui)->nb_dredir_out += 1;
	else if (!ft_strncmp(*input, ">>", 2))
		(*oui)->nb_dredir_in += 1;
	if (*(*input + 2))
	{
		if (*(*input + 2) == '<' || *(*input + 2) == '>')
			(*oui)->error = TRUE;
		else
		{
			(*input) += 2;
			while (**input && ft_is_whitespace(**input))
				(*input)++;
			if (*(*input) == '<' || *(*input) == '>')
				(*oui)->error = TRUE;
		}
	}
}
