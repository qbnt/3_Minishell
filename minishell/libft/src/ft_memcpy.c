/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:55:59 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/13 14:00:51 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*cdest;
	unsigned char		*csrc;
	size_t				i;

	i = 0;
	if (!dest && !src)
		return (0);
	cdest = dest;
	csrc = (unsigned char *)src;
	while (i++ < n)
		*cdest++ = *csrc++;
	return (dest);
}
