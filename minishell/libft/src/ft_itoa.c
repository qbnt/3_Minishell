/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:21:08 by qbanet            #+#    #+#             */
/*   Updated: 2023/02/09 10:46:52 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*res;
	unsigned int	nbr;
	int				len;

	len = ft_nbrlen(n);
	res = (char *)ft_calloc((len + 1), sizeof(char));
	if (!res)
		return (NULL);
	nbr = n;
	if (n < 0)
		nbr = -n;
	while (nbr >= 10)
	{
		res[--len] = nbr % 10 + '0';
		nbr /= 10;
	}
	res[--len] = nbr % 10 + '0';
	if (n < 0)
		res[--len] = '-';
	return (res);
}
