/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 09:01:38 by qbanet            #+#    #+#             */
/*   Updated: 2023/02/10 11:51:57 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;
	unsigned int	j;

	if (!s)
		return ;
	i = 0;
	j = 0;
	if (s != NULL || f != NULL)
	{
		i = ft_strlen(s);
		while (j < i)
			(*f)(j++, s++);
	}
}
