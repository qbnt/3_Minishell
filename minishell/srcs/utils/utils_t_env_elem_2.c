/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_t_env_elem_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:35:21 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/30 14:38:29 by qbanet           ###   ########.fr       */
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
		while (dol_str[i] && (ft_isalnum(dol_str[i])))
			i ++;
		dol = ft_calloc(sizeof(char), (i + 2));
		dol = ft_strncpy(dol, dol_str, i);
	}
	return (dol);
}

size_t	ft_dol_len_in_str(char *str, t_mini *ms)
{
	size_t	res;
	char	*key;
	char	*val;

	res = 0;
	while (*str)
	{
		if (*str == '$')
		{
			if ((str + 1) && *(str + 1) == '?' && !*(str + 2))
				return (ft_strlen(ft_itoa(ms->res) - 2));
			key = ft_cpy_dol(str);
			val = t_env_elems_find_value_of(ms->env->env_elems, (key + 1));
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
