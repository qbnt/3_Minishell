/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:25:50 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/16 12:17:16 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	clean_cmd(t_pars *cmd);
static void	parenth_cote(t_bool *in_cote, char c);

/*----------------------------------------------------------------------------*/

// Prends la ligne que retourne ReadLine et retourne la premiere node de la
//liste cree.
t_in	*set_str_to_t_in(char *str)
{
	t_in	*oui;
	t_bool	in_cote;

	while (str && (*str == '(' || *str == ')'))
		str ++;
	in_cote = FALSE;
	oui = NULL;
	if (*str)
	{
		if (*str == 34 || *str == 39)
			in_cote = TRUE;
		oui = t_in_first(oui, *str);
		while (*str && *(str + 1))
		{
			str ++;
			parenth_cote(&in_cote, *str);
			if ((*str == '(' || *str == ')') && in_cote == FALSE)
				continue ;
			else
				oui = t_in_add_back(oui, *str);
		}
		return (oui->first);
	}
	else
		return (NULL);
}

static void	parenth_cote(t_bool *in_cote, char c)
{
	if ((c == 34 || c == 39) && *in_cote == FALSE)
		*in_cote = TRUE;
	else if (*in_cote == TRUE && (c == 34 || c == 39))
		*in_cote = FALSE;
}

// Prends le premier maillon d'un t_in * avec tokens et reforme les arguments
//dans un t_l_args qu'il retourne.
t_pars	*set_in_to_t_pars(t_in *in)
{
	t_pars		*full_cmd;
	t_pars		*first_cmd;
	t_in		*first_in;

	first_in = in->first;
	full_cmd = t_pars_first(&in);
	first_cmd = full_cmd->first;
	while (in)
	{
		t_pars_add_next(&in, full_cmd);
		full_cmd = full_cmd->next;
	}
	while (full_cmd)
	{
		full_cmd->token = t_pars_pick_token(full_cmd);
		full_cmd = full_cmd->prev;
	}
	free_t_in(first_in);
	clean_cmd(first_cmd);
	return (first_cmd);
}

static void	clean_cmd(t_pars *cmd)
{
	while (cmd->next)
		cmd = cmd->next;
	if (cmd->str[0] == 0)
	{
		cmd = cmd->prev;
		free(cmd->next->str);
		free(cmd->next);
		cmd->next = NULL;
	}
}
