/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:01:21 by qbanet            #+#    #+#             */
/*   Updated: 2023/02/11 12:42:36 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*out;

	if (!lst || !f || !del)
		return (NULL);
	out = ft_lstnew(NULL);
	if (!out)
		return (NULL);
	node = out;
	while (lst)
	{
		node->content = f(lst->content);
		if (lst->next)
		{
			node->next = ft_lstnew(NULL);
			if (!node)
			{
				ft_lstclear(&out, del);
				return (NULL);
			}
			node = node->next;
		}
		lst = lst->next;
	}
	return (out);
}
