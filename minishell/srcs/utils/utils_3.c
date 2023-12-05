/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:47:20 by qpuig             #+#    #+#             */
/*   Updated: 2023/12/05 11:54:05 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_getenv(t_env *env, char *str)
{
	while ((ft_strcmp(env->env_elems->key, str) == FALSE)
		&& env->env_elems->next)
			env->env_elems = env->env_elems->next;
	if (env->env_elems)
		return (env->env_elems->value);
	return (NULL);
}

char	*ft_strndup(const char *s, size_t size)
{
	char	*str;
	size_t	i;
	size_t	len;

	if (size > ft_strlen(s))
		len = ft_strlen(s);
	else
		len = size;
	str = malloc(len * sizeof(char) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = ((char *)s)[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_strcat(char *src, char *dest)
{
	char	*res;
	int		lendest;
	int		lensrc;
	int		i;

	lendest = ft_strlen(dest);
	lensrc = ft_strlen(src);
	res = ft_calloc(lendest + lensrc + 1, sizeof(char));
	i = -1;
	while (src && src[++i])
		res[i] = src[i];
	i = -1;
	while (dest[++i])
		res[lensrc + i] = dest[i];
	free(src);
	return (res);
}
