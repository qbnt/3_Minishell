/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:17:24 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/13 14:02:14 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(long long n, int fd)
{
	if (n < 0)
	{
		if (n == -2147483648)
			write (fd, "-2147483648", 11);
		else
		{
			n = n * -1;
			ft_putchar_fd('-', fd);
		}
	}
	if (n >= 0 && n <= 9)
		ft_putchar_fd(n + 48, fd);
	if (n > 9)
	{
		if (n == 0)
			return ;
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + 48, fd);
	}
}
