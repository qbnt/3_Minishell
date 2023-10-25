/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_wrd_sep.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 19:53:01 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/17 16:20:43 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_wrd_sep(char const *s, char c)
{
	int	count;
	int	sep;

	sep = 0;
	count = 0;
	while (*s)
	{
		if (sep == 1 && *s == c)
			sep = 0;
		if (sep == 0 && *s != c)
		{
			sep = 1;
			count ++;
		}
		s++;
	}
	if (sep == 0 && *s == 0)
		count ++;
	return (count);
}
