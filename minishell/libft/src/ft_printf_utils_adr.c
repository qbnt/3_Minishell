/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_adr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:12:40 by qbanet            #+#    #+#             */
/*   Updated: 2023/03/23 12:45:21 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_adrlen(unsigned long long adr)
{
	int	len;

	len = 0;
	while (adr)
	{
		adr /= 16;
		len ++;
	}
	return (len);
}

static void	ft_putadr(unsigned long long adr)
{
	if (adr >= 16)
	{
		ft_putadr(adr / 16);
		ft_putadr(adr % 16);
	}
	else
	{
		if (adr <= 9)
			ft_putchar_fd((adr + '0'), 1);
		else
			ft_putchar_fd((adr - 10 + 'a'), 1);
	}
}

int	ft_printadr(unsigned long long adr)
{
	int	len;

	len = 0;
	if (!adr)
		len += write(1, "(nil)", 5);
	else
	{
		len += write(1, "0x", 2);
		ft_putadr(adr);
		len += ft_adrlen(adr);
	}
	return (len);
}
