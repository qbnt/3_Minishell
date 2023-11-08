/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:08:56 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/08 14:27:17 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*----------------------------------------------------------------------------*/

// Prend un char et renvoit un t_bool indiquant si le char est un whitespace ou
//pas.
t_bool	ft_is_whitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == 'v' || c == 'f' || c == 'r')
		return (1);
	return (0);
}

// Prend un char et renvoie un t_bol indiquant si le char est un caractère
//alphabétique
t_bool	ft_is_alpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
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
			len ++;
			tmp = tmp->next;
			while (tmp)
			{
				if (tmp->c == 34)
					return (len + 1);
				len ++;
				tmp = tmp->next;
			}
		}
		else
		{
			len ++;
			tmp = tmp->next;
		}
	}
	return (len);
}

void	ft_print_t_pars(t_pars **oui)
{
	t_pars	*tmp;

	tmp = *oui;
	printf("_________________t_pars__________________\n");
	while (tmp != NULL)
	{
		printf("|	%c	->	id = %d		|\n", tmp->c, tmp->id);
		tmp = tmp->next;
	}
	printf("-----------------------------------------\n");
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
