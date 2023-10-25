/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base_unsign.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:27:24 by qbanet            #+#    #+#             */
/*   Updated: 2023/03/25 14:32:39 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_digist(t_ull n, int base)
{
	size_t	count;

	count = 0;
	while (n)
	{
		n /= base;
		count++;
	}
	return (count);
}

char	*ft_convert_base_unsign(t_ull num, const char *base_set, int base)
{
	char	*result;
	size_t	len;

	if (num == 0)
		return (ft_strdup("0"));
	len = ft_count_digist(num, base);
	result = malloc(sizeof(char) * (len + 1));
	if (!(result))
		return (0);
	result[len] = 0;
	while (len)
	{
		result[--len] = base_set[num % base];
		num = num / base;
	}
	return (result);
}
