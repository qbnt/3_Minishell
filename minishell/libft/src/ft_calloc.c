/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 10:46:19 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/29 15:43:53 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	res;

	res = size * nmemb;
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (res / size !=  nmemb || res / nmemb != size)
		return (NULL);
	ptr = malloc(res);
	if (ptr)
		ft_bzero(ptr, res);
	return (ptr);
}
