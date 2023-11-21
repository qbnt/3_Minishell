/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_t_env_elem_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:35:21 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/21 19:14:30 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*============================================================================*/

char	*ft_cpy_dol(char *dol_str)
{
	char	*dol;
	int		i;

	dol = NULL;
	i = 1;
	if (*dol_str)
	{
		while (dol_str[i]
			&& (!ft_is_whitespace(dol_str[i]) && dol_str[i] != '$'))
			i ++;
		dol = malloc(sizeof(char) * (i + 1));
		dol = ft_strncpy(dol, dol_str, i);
	}
	return (dol);
}

int	ft_dol_len_in_str(char *str)
{
	size_t	res;
	size_t	key_len;
	size_t	val_len;

	while (*str)
	{
		if (*str == '$')
		{
			key_len = 
		}
		str ++;
	}
}
