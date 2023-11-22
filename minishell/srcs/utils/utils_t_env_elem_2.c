/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_t_env_elem_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:35:21 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/22 16:33:10 by qbanet           ###   ########.fr       */
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
		dol = ft_calloc(sizeof(char), (i + 2));
		dol = ft_strncpy(dol, dol_str, i);
	}
	return (dol);
}

size_t	ft_dol_len_in_str(char *str, t_env_elems *env)
{
	size_t	res;
	char	*key;
	char	*val;

	res = 0;
	while (*str)
	{
		if (*str == '$')
		{
			key = ft_cpy_dol(str);
			val = t_env_elems_find_value_of(env, (key + 1));
			res += ft_strlen(val) - ft_strlen(key);
			str += ft_strlen(key);
			free(key);
			free(val);
		}
		if (*str && *str != '$')
			++ str;
	}
	return (res);
}
