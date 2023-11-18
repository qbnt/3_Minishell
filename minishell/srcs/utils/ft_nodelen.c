/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodelen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 20:04:32 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/18 13:14:04 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		is_cote(size_t *len, t_in **tmp, char cote);
static int		is_end_cote(size_t *len, t_in **tmp, char cote);
static int		is_end_cote_recursive(size_t *len, t_in **tmp, char cote);

/*----------------------------------------------------------------------------*/

size_t	ft_nodelen(t_in **oui)
{
	size_t	len;
	t_in	*tmp;

	len = 0;
	tmp = *oui;
	while (tmp && (!ft_is_whitespace(tmp->c)))
	{
		if (tmp && tmp->c == 34 && is_cote(&len, &tmp, 34))
			return (len);
		else if (tmp && tmp->c == 39 && is_cote(&len, &tmp, 39))
			return (len);
		else
		{
			if (tmp && ft_is_opp(tmp->c) && tmp->next && tmp->c == tmp->next->c)
				return (2);
			else if (tmp->next && ft_is_opp(tmp->next->c))
				return (++len);
			else if (tmp && ft_is_opp(tmp->c) && tmp->next
				&& tmp->next->c != '&')
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
		if ((*tmp)->c == cote && (*tmp)->next)
		{
			(*len) += 1;
			(*tmp) = (*tmp)->next;
			is_end_cote(len, tmp, cote);
			return (1);
		}
		else if ((*tmp)->c == cote)
			return ((*len) += 1, (*tmp) = (*tmp)->next, 1);
		else
		{
			*len += 1;
			(*tmp) = (*tmp)->next;
		}
	}
	return (0);
}


static int	is_end_cote_recursive(size_t *len, t_in **tmp, char cote)
{
	if (!(*tmp))
		return (0);
	if ((*tmp)->c == cote)
	{
		(*len) += 1;
		(*tmp) = (*tmp)->next;
		return (is_end_cote(len, tmp, cote));
	}
	else
	{
		(*len) += 1;
		(*tmp) = (*tmp)->next;
		return (is_end_cote_recursive(len, tmp, cote));
	}
}

static int	is_end_cote(size_t *len, t_in **tmp, char cote)
{
	if (!(*tmp))
		return (0);
	if ((*tmp)->c == 34 || (*tmp)->c == 39)
	{
		cote = (*tmp)->c;
		(*len) += 1;
		(*tmp) = (*tmp)->next;
		return (is_end_cote_recursive(len, tmp, cote));
	}
	else if (!ft_is_whitespace((*tmp)->c))
	{
		while ((*tmp) && !ft_is_whitespace((*tmp)->c))
		{
			(*len) += 1;
			(*tmp) = (*tmp)->next;
		}
	}
	return (1);
}
