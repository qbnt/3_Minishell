/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:44:41 by qbanet            #+#    #+#             */
/*   Updated: 2023/02/09 10:50:26 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_wrd(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == c))
			i++;
		if (str[i] && (str[i++] != c))
			count ++;
		while (str[i] != c && str[i])
			i++;
	}
	return (count);
}

static char	*ft_wrd_dup(char *src, char c, int *i)
{
	char	*dest;
	int		j;

	j = 0;
	while (src[(*i) + j] && (src[(*i) + j] != c))
		j++;
	dest = (char *)ft_calloc((j + 1), sizeof(char));
	if (!dest)
		return (NULL);
	j = 0;
	while ((src[(*i)] != c) && src[(*i)])
		dest[j++] = src[(*i)++];
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**res;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	res = ft_calloc((ft_count_wrd((char *)s, c) + 1), sizeof(char *));
	if (!res)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if ((s[i] != c) && s[i])
			res[j++] = ft_wrd_dup((char *)s, c, &i);
	}
	return (res);
}
