/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 10:46:19 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/09 09:39:03 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ret;
	size_t	test;

	if (size != 0 && nmemb != 0)
	{
		test = size * nmemb;
		if ((test / nmemb != size) || (test / size != nmemb))
			return (NULL);
	}
	ret = (void *)malloc(size * nmemb);
	if (!ret)
		return (NULL);
	ft_bzero(ret, size * nmemb);
	return (ret);
}
