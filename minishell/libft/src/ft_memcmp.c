/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 11:00:39 by qbanet            #+#    #+#             */
/*   Updated: 2023/02/08 15:45:46 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	size_t			i;
	unsigned char	*cptr1;
	unsigned char	*cptr2;

	if (ptr1 == ptr2 || num == 0)
		return (0);
	i = 0;
	cptr1 = (unsigned char *)ptr1;
	cptr2 = (unsigned char *)ptr2;
	while (i < num)
	{
		if (cptr1[i] != cptr2[i])
			return (cptr1[i] - cptr2[i]);
		i ++;
	}
	return (0);
}
