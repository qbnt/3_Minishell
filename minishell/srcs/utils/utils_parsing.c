/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:25:50 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/13 11:41:09 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	clean_cmd(t_pars *cmd);

// Ajouter une fonction qui check si " est % 2. Si oui line ok, sinon return
//erreur

/*----------------------------------------------------------------------------*/

// Prends la ligne que retourne ReadLine et retourne la premiere node de la
//liste cree.
t_in	*set_str_to_t_in(char *str)
{
	t_in	*oui;

	oui = NULL;
	oui = t_in_first(oui, *str);
	while (*(str + 1))
	{
		str ++;
		oui = t_in_add_back(oui, *str);
	}
	return (oui->first);
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
