/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 11:26:17 by qbanet            #+#    #+#             */
/*   Updated: 2023/02/09 08:50:56 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		i;

	i = 0;
	dup = (char *)ft_calloc((ft_strlen(s) + 1), sizeof(char));
	if (dup == NULL)
		return (NULL);
	while (*s)
		dup[i++] = *s++;
	return (dup);
}
