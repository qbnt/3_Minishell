/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodelen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 20:04:32 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/13 20:05:23 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_dcote(size_t *len, t_in **tmp);
static int	is_end_dcote(size_t *len, t_in **tmp);

/*----------------------------------------------------------------------------*/

size_t	ft_nodelen(t_in **oui)
{
	size_t	len;
	t_in	*tmp;

	len = 0;
	tmp = *oui;
	while (tmp && (!ft_is_whitespace(tmp->c)))
	{
		if (tmp->c == 34)
		{
			if (is_dcote(&len, &tmp))
				return (len);
		}
		else
		{
			if (tmp->next && tmp->next->c == '|')
				return (++len);
			else if (tmp->c == '|')
				return (1);
			len ++;
			tmp = tmp->next;
		}
	}
	return (len);
}

static int	is_dcote(size_t *len, t_in **tmp)
{
	*len += 1;
	(*tmp) = (*tmp)->next;
	while (*tmp)
	{
		if ((*tmp)->c == 34)
		{
			return (is_end_dcote(len, tmp));
		}
		else
		{
			*len += 1;
			(*tmp) = (*tmp)->next;
		}
	}
	return (0);
}

static int	is_end_dcote(size_t *len, t_in **tmp)
{
	if (!(*tmp)->next || ((*tmp)->next
			&& (ft_is_whitespace((*tmp)->next->c))))
		return (*len += 1, 1);
	else if ((*tmp)->next->c == 34)
	{
		*len += 2;
		(*tmp) = (*tmp)->next->next;
	}
	else
	{
		while ((*tmp) && !ft_is_whitespace((*tmp)->c))
		{
			if ((*tmp)->next && (*tmp)->next->c == '|')
				return (++(*len));
			else if ((*tmp)->c == '|')
				return (1);
			*len += 1;
			(*tmp) = (*tmp)->next;
		}
		return (1);
	}
	return (0);
}
