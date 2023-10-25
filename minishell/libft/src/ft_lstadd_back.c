/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:36:36 by qbanet            #+#    #+#             */
/*   Updated: 2023/03/23 17:03:57 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *n)
{
	t_list	*temp;

	if (!*lst)
	{
		*lst = n;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = n;
}
