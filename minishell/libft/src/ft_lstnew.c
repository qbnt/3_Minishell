/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:53:40 by qbanet            #+#    #+#             */
/*   Updated: 2023/02/09 15:15:56 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*oui;

	oui = malloc(sizeof(t_list));
	if (!oui)
		return (NULL);
	oui->content = content;
	oui->next = NULL;
	return (oui);
}
