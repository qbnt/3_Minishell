/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 09:53:08 by qbanet            #+#    #+#             */
/*   Updated: 2023/02/07 12:42:02 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_verifset(char c, char *set)
{
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
}

static char	*ft_verifstr(void)
{
	char	*res;

	res = (char *)malloc(1 * sizeof(char));
	if (!res)
		return (NULL);
	*res = 0;
	return (res);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		lenstr;
	int		i;
	int		j;
	char	*res;

	if (!s1 || !set)
		return (NULL);
	lenstr = ft_strlen(s1) - 1;
	i = 0;
	while (ft_verifset(s1[i], (char *)set) && s1[i])
		i++;
	while (ft_verifset(s1[lenstr], (char *)set) && lenstr >= 0)
		lenstr--;
	if (i > lenstr)
		return (ft_verifstr());
	res = (char *)malloc((lenstr - i + 2) * sizeof(char));
	if (!res)
		return (res);
	j = 0;
	while (i <= lenstr)
		res[j++] = s1[i++];
	res[j] = 0;
	return (res);
}
