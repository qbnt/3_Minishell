/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_unsign.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:02:54 by qbanet            #+#    #+#             */
/*   Updated: 2023/03/23 12:45:30 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lendigit(unsigned int n)
{
	int	len;

	len = 0;
	while (n)
	{
		n /= 10;
		len ++;
	}
	return (len);
}

static char	*ft_unsitoa(unsigned int n)
{
	char	*res;
	int		len;

	len = ft_lendigit(n);
	res = (char *)ft_calloc(len + 1, sizeof(char));
	if (!res)
		return (0);
	while (n)
	{
		res[len - 1] = n % 10 + '0';
		n /= 10;
		len --;
	}
	return (res);
}

int	ft_printunsigned(unsigned int n)
{
	int		len;
	char	*num;

	len = 0;
	if (!n)
		len += write(1, "0", 1);
	else
	{
		num = ft_unsitoa(n);
		len += ft_printstr(num);
		free(num);
	}
	return (len);
}
