/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 21:34:52 by qbanet            #+#    #+#             */
/*   Updated: 2023/03/27 13:16:36 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printerr(void)
{
	int	len;

	len = 0;
	len = ft_printstr("Invalid Argument");
	return (len);
}

int	ft_printchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_format(va_list *args, const char format)
{
	if (format == 'c')
		return (ft_printchar(va_arg(*args, int)));
	else if (format == 's')
		return (ft_printstr(va_arg(*args, char *)));
	else if (format == 'p')
		return (ft_printadr(va_arg(*args, unsigned long long)));
	else if (format == 'd' || format == 'i')
		return (ft_printnbr(va_arg(*args, int)));
	else if (format == 'u')
		return (ft_printunsigned(va_arg(*args, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (ft_printhexa(va_arg(*args, int), format));
	else if (format == '%')
		return (ft_printpourcent());
	else
		return (ft_printerr());
}

int	ft_printf(const char *str, ...)
{
	size_t		i;
	va_list		args;
	int			len;

	i = 0;
	len = 0;
	if (!str)
		return (0);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
			len += ft_format(&args, str[++i]);
		else
		{
			ft_printchar(str[i]);
			len ++;
		}
		i ++;
	}
	va_end(args);
	return (len);
}
