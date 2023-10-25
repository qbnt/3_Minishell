/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_hexa.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 23:11:48 by qbanet            #+#    #+#             */
/*   Updated: 2023/03/23 12:45:25 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_hexalen(unsigned int n)
{
	int	len;

	len = 0;
	while (n)
	{
		n /= 16;
		len ++;
	}
	return (len);
}

static void	ft_puthexa(unsigned int n, const char format)
{
	if (n >= 16)
	{
		ft_puthexa(n / 16, format);
		ft_puthexa(n % 16, format);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd((n + '0'), 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd((n - 10 + 'a'), 1);
			if (format == 'X')
				ft_putchar_fd((n - 10 + 'A'), 1);
		}
	}
}

int	ft_printhexa(int n, const char format)
{
	if (n == 0)
		return (write(1, "0", 1));
	else
		ft_puthexa(n, format);
	return (ft_hexalen(n));
}
