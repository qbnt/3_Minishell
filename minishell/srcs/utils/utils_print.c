/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:33:45 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/19 12:22:21 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*----------------------------------------------------------------------------*/

void	ft_print_t_in(t_in **oui, int arg)
{
	t_in	*tmp;

	tmp = *oui;
	if (arg == ID)
	{
		printf("__________________t_in___________________\n");
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

void	ft_print_t_pars(t_pars *oui)
{
	t_pars	*tmp;

	tmp = oui;
	printf("_________________t_pars__________________\n");
	while (tmp != NULL)
	{
		printf("|	%s	->	token = %d	|\n", tmp->str, tmp->token);
		tmp = tmp->next;
	}
	printf("-----------------------------------------\n");
}

void	ft_print_dtab(char **dtab)
{
	int	i;

	i = 0;
	while (dtab[i])
	{
		printf("%s\n", dtab[i]);
		i ++;
	}
	printf("\n\n");
}

void	ft_print_t_env_elems(t_env_elems *elems)
{
	int	i;

	i = 0;
	while (elems)
	{
		printf("Elem %d\n", i ++);
		printf("Key = %s\nValue = %s\n\n", elems->key, elems->value);
		elems = elems->next;
	}
}
