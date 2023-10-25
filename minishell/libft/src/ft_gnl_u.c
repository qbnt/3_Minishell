/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 09:32:40 by qbanet            #+#    #+#             */
/*   Updated: 2023/06/20 13:50:37 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_free_gnl(t_gnl **lst)
{
	t_gnl	*next;

	while (*lst)
	{
		free((*lst)->tempo);
		next = (*lst)->next;
		free(*lst);
		*lst = next;
	}
	return (0);
}

void	ft_list_add_last(t_gnl **save, t_gnl *elem)
{
	t_gnl	*list;

	list = *save;
	while (list->next)
		list = list->next;
	list->next = elem;
}

t_gnl	*ft_create_list(int fd)
{
	t_gnl	*list;

	list = (t_gnl *)malloc(sizeof(*list));
	if (!list)
		return (NULL);
	list->fd = fd;
	list->tempo = ft_calloc(1, sizeof(char *));
	list->next = NULL;
	list->text = NULL;
	return (list);
}
