/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:08:56 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/13 15:47:57 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_dcote(size_t *len, t_in **tmp);
static int	find_end_dcote(size_t *len, t_in **tmp);

/*----------------------------------------------------------------------------*/

// Prend un char et renvoit un t_bool indiquant si le char est un whitespace ou
//pas.
t_bool	ft_is_whitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r')
		return (1);
	return (0);
}

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
		else if (tmp->c == '|')
			if (ft_is_whitespace(tmp->prev->c))
				return (1);
			else
				return (len);
		else
		{
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
			return (find_end_dcote(len, tmp));
		}
		else
		{
			*len += 1;
			(*tmp) = (*tmp)->next;
		}
	}
	return (0);
}

static int	find_end_dcote(size_t *len, t_in **tmp)
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
			*len += 1;
			(*tmp) = (*tmp)->next;
		}
		return (1);
	}
	return (0);
}
