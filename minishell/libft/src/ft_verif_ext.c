/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_ext.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:02:14 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/13 12:39:37 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_verif_ext(const char *s, const char *ext)
{
	size_t	ext_len;

	ext_len = ft_strlen(ext);
	if (ft_strncmp(ext, ft_strrchr(s, '.'), ext_len)
		|| ft_strlen(ft_strrchr(s, '.')) == ext_len)
		return (1);
	return (0);
}
