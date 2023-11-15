/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodelen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 20:04:32 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/15 15:17:10 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_cote(size_t *len, t_in **tmp, char cote);
static int	is_end_cote(size_t *len, t_in **tmp, char cote);

/*----------------------------------------------------------------------------*/

size_t	ft_nodelen(t_in **oui)
{
	size_t	len;
	t_in	*tmp;

	len = 0;
	tmp = *oui;
	while (tmp && (!ft_is_whitespace(tmp->c)))
	{
		if (tmp->c == 34 && is_cote(&len, &tmp, 34))
			return (len);
		else if (tmp->c == 39 && is_cote(&len, &tmp, 39))
			return (len);
		else
		{
			if (ft_is_opp(tmp->c) && tmp->next && tmp->c == tmp->next->c)
				return (2);
			else if (tmp->next && ft_is_opp(tmp->next->c))
				return (++len);
			else if (ft_is_opp(tmp->c) && tmp->next->c != '&')
				return (1);
			len ++;
			tmp = tmp->next;
		}
	}
	return (len);
}

static int	is_cote(size_t *len, t_in **tmp, char cote)
{
	*len += 1;
	(*tmp) = (*tmp)->next;
	while (*tmp)
	{
		if ((*tmp)->c == cote)
		{
			return (is_end_cote(len, tmp, cote));
		}
		else
		{
			*len += 1;
			(*tmp) = (*tmp)->next;
		}
	}
	return (0);
}

static int	is_end_cote(size_t *len, t_in **tmp, char cote)
{
	if (!(*tmp)->next || ((*tmp)->next
			&& (ft_is_whitespace((*tmp)->next->c))))
		return (*len += 1, 1);
	else if ((*tmp)->next->c == cote)
	{
		*len += 2;
		(*tmp) = (*tmp)->next->next;
	}
	else
	{
		while ((*tmp) && !ft_is_whitespace((*tmp)->c))
		{
			if ((*tmp)->next && ft_is_opp((*tmp)->next->c))
				return (++(*len));
			else if (ft_is_opp((*tmp)->c))
				return (1);
			*len += 1;
			(*tmp) = (*tmp)->next;
		}
		return (1);
	}
	return (0);
}
