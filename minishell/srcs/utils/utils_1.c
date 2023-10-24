/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:08:56 by qbanet            #+#    #+#             */
/*   Updated: 2023/10/24 14:06:05 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*----------------------------------------------------------------------------*/

// Prend une chaine de caractères et retourne sa taille en size_t.
size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (*str)
	{
		len ++;
		str ++;
	}
	return (len);
}

//Prend un char et renvoit un t_bool indiquant si le char est un whitespace ou
//pas.
t_bool	ft_is_whitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == 'v' || c == 'f' || c == 'r')
		return (1);
	return (0);
}
