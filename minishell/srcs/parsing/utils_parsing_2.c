/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:18:19 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/20 12:18:54 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*============================================================================*/

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
