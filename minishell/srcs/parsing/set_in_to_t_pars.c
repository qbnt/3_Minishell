/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_in_to_t_pars.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:07:37 by qbanet            #+#    #+#             */
/*   Updated: 2023/12/08 11:49:24 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	clean_cmd(t_pars *cmd);

/*============================================================================*/

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
