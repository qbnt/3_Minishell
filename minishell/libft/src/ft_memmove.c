/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:08:39 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/13 14:00:45 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char			*cdest;
	const char		*csrc;

	cdest = dest;
	csrc = src;
	if (cdest <= csrc)
		ft_memcpy(dest, src, n);
	if (cdest > csrc)
		while (n--)
			cdest[n] = csrc[n];
	return (dest);
}
