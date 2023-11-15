/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_clear_cmds.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:03:57 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/15 15:17:30 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//static void		clear_prev(t_pars *res);
static t_pars	*cpy_cmd(t_pars *pars);

/*----------------------------------------------------------------------------*/

t_pars	**make_clear_cmds(t_elem_pars *elems, t_pars *pars)
{
	t_pars	**res;
	int		i;

	res = ft_calloc(sizeof(t_pars), elems->nb_cmd);
	i = -1;
	while (++i < elems->nb_cmd)
	{
		res[i] = cpy_cmd(pars);
		while (pars && pars->token != OPP)
			pars = pars->next;
		if (pars)
			pars = pars->next;
	}
	return (res);
}

static t_pars	*cpy_cmd(t_pars *pars)
{
	t_pars	*cmd;

	cmd = malloc(sizeof(t_pars));
	cmd->prev = NULL;
	cmd->first = cmd;
	while (pars && pars->token != OPP)
	{
		cmd->str = ft_strdup(pars->str);
		cmd->token = pars->token;
		cmd->pipe = FALSE;
		pars = pars->next;
		cmd->next = malloc(sizeof(t_pars));
		cmd->next->prev = cmd;
		cmd = cmd->next;
		if (cmd->prev)
			cmd->first = cmd->prev->first;
	}
	if (pars && pars->token == OPP)
		cmd->prev->pipe = TRUE;
	if (cmd->prev)
		cmd = cmd->prev;
	free(cmd->next);
	cmd->next = NULL;
	return (cmd->first);
}
