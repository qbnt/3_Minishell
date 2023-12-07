/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <qpuig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:11:53 by qbanet            #+#    #+#             */
/*   Updated: 2023/12/07 17:11:01 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i ++;
	}
}

int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstr("(nill)");
		return (6);
	}
	while (str[i])
		i += write(1, &str[i], 1);
	return (i);
}

int	ft_printnbr(int n)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(n);
	len = ft_printstr(num);
	free(num);
	return (len);
}

int	ft_printpourcent(void)
{
	write(1, "%", 1);
	return (1);
}
