/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_str_to_t_in.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:25:50 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/30 13:45:31 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	in_cote(t_bool *in_cote, char c);
static void	make_parenth_groups(char **str, int *group);
static void	cpy_loop(char *str, t_bool *in_cote, int *group, t_in **oui);

/*----------------------------------------------------------------------------*/

// Prends la ligne que retourne ReadLine et retourne la premiere node de la
//liste cree.
t_in	*set_str_to_t_in(char *str)
{
	t_in	*oui;
	t_bool	is_in_cote;
	int		group;

	group = 0;
	is_in_cote = FALSE;
	make_parenth_groups(&str, &group);
	oui = NULL;
	if (*str)
	{
		if (*str == 34 || *str == 39)
			is_in_cote = TRUE;
		if (*str == '(' || *str == ')')
			while (str && (*str == '(' || *str == ')'))
				str ++;
		oui = t_in_first(oui, *str, group);
		str ++;
		cpy_loop(str, &is_in_cote, &group, &oui);
		return (oui->first);
	}
	else
		return (NULL);
}

static void	cpy_loop(char *str, t_bool *is_in_cote, int *group, t_in **oui)
{
	while (*(str))
	{
		in_cote(is_in_cote, *str);
		if ((*str == '(' || *str == ')') && *is_in_cote == FALSE)
		{
			make_parenth_groups(&str, group);
			continue ;
		}
		else
			(*oui) = t_in_add_back((*oui), *str, *group);
		str ++;
	}
}

static void	make_parenth_groups(char **str, int *group)
{
	if (*(*str) && (*(*str) == '(' || *(*str) == ')'))
	{
		(*group) += 1;
		(*str)++;
	}
}

static void	in_cote(t_bool *in_cote, char c)
{
	if ((c == 34 || c == 39) && *in_cote == FALSE)
		*in_cote = TRUE;
	else if (*in_cote == TRUE && (c == 34 || c == 39))
		*in_cote = FALSE;
}
