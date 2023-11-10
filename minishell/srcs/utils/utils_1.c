/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:08:56 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/10 12:10:24 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_dcote(size_t *len, t_pars **tmp);

/*----------------------------------------------------------------------------*/

// Prend un char et renvoit un t_bool indiquant si le char est un whitespace ou
//pas.
t_bool	ft_is_whitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == 'v' || c == 'f' || c == 'r')
		return (1);
	return (0);
}

size_t	ft_ltrlen(t_pars **oui)
{
	size_t	len;
	t_pars	*tmp;

	len = 0;
	tmp = *oui;
	while (tmp && !ft_is_whitespace(tmp->c))
	{
		if (tmp->c == 34)
		{
			if (is_dcote(&len, &tmp))
				return (len + 1);
		}
		else
		{
			len ++;
			tmp = tmp->next;
		}
	}
	return (len);
}

static int	is_dcote(size_t *len, t_pars **tmp)
{
	(*tmp) = (*tmp)->next;
	*len += 1;
	while (*tmp)
	{
		if ((*tmp)->c == 34 && (*tmp)->next->c != 34)
		{
			*len += 1;
			return (1);
		}
		else if ((*tmp)->c == 34)
		{
			*len += 2;
			(*tmp) = (*tmp)->next->next;
		}
		*len += 1;
		(*tmp) = (*tmp)->next;
	}
	return (0);
}

void	ft_print_t_pars(t_pars **oui, int arg)
{
	t_pars	*tmp;

	tmp = *oui;
	if (arg == ID)
	{
		printf("_________________t_pars__________________\n");
		while (tmp != NULL)
		{
			printf("|	%c	->	id = %d		|\n", tmp->c, tmp->id);
			tmp = tmp->next;
		}
		printf("-----------------------------------------\n");
	}
	else if (arg == CHAR)
	{
		printf("\n|\\");
		while (tmp != NULL)
		{
			printf("%c", tmp->c);
			tmp = tmp->next;
		}
		printf("/|\n\n");
	}
}

void	ft_print_t_l_args(t_l_args **oui)
{
	t_l_args	*tmp;

	tmp = *oui;
	printf("________________t_l_args_________________\n");
	while (tmp != NULL)
	{
		printf("|	%s	->	token = %d	|\n", tmp->str, tmp->token);
		tmp = tmp->next;
	}
	printf("-----------------------------------------\n");
}
