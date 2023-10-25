/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:08:39 by qbanet            #+#    #+#             */
/*   Updated: 2023/02/03 16:54:59 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

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
