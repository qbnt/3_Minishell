/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 14:57:59 by qbanet            #+#    #+#             */
/*   Updated: 2023/02/05 11:49:35 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	lenstr;
	int	i;

	lenstr = ft_strlen(str);
	if (c == 0)
		return ((char *)(str + (lenstr)));
	i = 0;
	while ((lenstr - i) >= 0)
	{
		if (str[lenstr - i] == (char)c)
			return ((char *)str + (lenstr - i));
		i ++;
	}
	return (NULL);
}
