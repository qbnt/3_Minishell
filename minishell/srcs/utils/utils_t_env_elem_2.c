/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_t_env_elem_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:35:21 by qbanet            #+#    #+#             */
/*   Updated: 2023/12/08 17:37:42 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	dol_len_else(char **key, char **val, t_mini *ms, char *str);

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

static int	res_dolint(int res, int key)
{
	char	*val;

	val = ft_itoa(key);
	res = ft_strlen(val) - 2;
	free(val);
	return (res);
}

static int	ft_nbrlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

size_t	ft_dol_len_in_str(char *str, t_mini *ms, size_t res)
{
	char	*key;
	char	*val;

	key = NULL;
	val = NULL;
	res = 0;
	while (*str)
	{
		if (*str == '$')
		{
			if ((str + 1) && *(str + 1) == '?')
				res += (res_dolint(res, ms->res));
			else
				res += dol_len_else(&key, &val, ms, str);
			str += ft_nbrlen(ms->res);
		}
		if (*str && *str != '$')
			++ str;
	}
	return (res);
}

static int	dol_len_else(char **key, char **val, t_mini *ms, char *str)
{
	int	res;

	res = 0;
	*key = ft_cpy_dol(str);
	*val = t_env_elems_find_value_of(ms->env->env_elems, ((*key) + 1));
	if (!*val)
		res += ft_strlen(*key);
	else
		res += ft_strlen(*val) - ft_strlen(*key);
	multi_free_str(*key, *val, NULL, NULL);
	return (res);
}
