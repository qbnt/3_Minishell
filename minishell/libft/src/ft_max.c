/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:32:23 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/13 16:42:59 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_max(int *tab, unsigned int len)
{
	unsigned int	i;
	int				max;

	if (len == 0)
		return (0);
	i = 1;
	max = *tab;
	while (i != len)
	{
		if (max < *(tab + i))
			max = *(tab + i);
		i++;
	}
	return (max);
}
