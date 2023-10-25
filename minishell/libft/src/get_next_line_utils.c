/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 09:53:42 by qbanet            #+#    #+#             */
/*   Updated: 2023/03/23 12:51:53 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_gnl(char *str, size_t c)
{
	char	*res;
	size_t	i;

	i = 0;
	while (str[i])
		i ++;
	res = (char *)malloc((i - c + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (str[i + c])
	{
		res[i] = str[i + c];
		i ++;
	}
	res[i] = '\0';
	return (res);
}

size_t	ft_strlen_gnl(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i ++;
	return (i);
}

char	*ft_check_gnl(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)(str + i));
		i ++;
	}
	if ((char)c == 0)
		return ((char *)(str + i));
	return (NULL);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	res = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	if (s1)
	{
		while (s1[i])
		{
			res[i] = s1[i];
			i ++;
		}
		free(s1);
	}
	j = 0;
	while (s2[j])
		res[i ++] = s2[j ++];
	res[i] = 0;
	return (res);
}
