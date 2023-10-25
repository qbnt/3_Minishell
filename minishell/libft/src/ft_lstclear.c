/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:40:50 by qbanet            #+#    #+#             */
/*   Updated: 2023/02/10 15:46:36 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*swp;
	t_list	*temp;

	if (!lst || !del)
		return ;
	swp = *lst;
	while (swp)
	{
		temp = swp->next;
		del(swp->content);
		free(swp);
		swp = temp;
	}
	*lst = NULL;
}
