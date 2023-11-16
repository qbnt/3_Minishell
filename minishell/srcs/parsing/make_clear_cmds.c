/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_clear_cmds.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:03:57 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/16 15:28:26 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//static void		clear_prev(t_pars *res);
static t_pars	*cpy_cmd(t_pars *pars);
static void		select_opp(t_pars	*pars, t_pars **cmd);

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
		while (pars && pars->token == OPP)
			pars = pars->next;
		ft_print_t_pars(res[i]->first);
		printf("pipe = %d, and = %d, or = %d\n\n", res[i]->pipe_op,
			res[i]->and_op, res[i]->or_op);
	}
	return (res);
}

static t_pars	*cpy_cmd(t_pars *pars)
{
	t_pars	*cmd;

	cmd = ft_calloc(sizeof(t_pars), 1);
	cmd->prev = NULL;
	cmd->first = cmd;
	while (pars && pars->token != OPP)
	{
		cmd->str = ft_strdup(pars->str);
		cmd->token = pars->token;
		pars = pars->next;
		cmd->next = ft_calloc(sizeof(t_pars), 1);
		cmd->next->prev = cmd;
		cmd = cmd->next;
		if (cmd->prev)
			cmd->first = cmd->prev->first;
	}
	select_opp(pars, &cmd);
	if (cmd->prev)
		cmd = cmd->prev;
	free(cmd->next);
	cmd->next = NULL;
	return (cmd->first);
}

static void	select_opp(t_pars	*pars, t_pars **cmd)
{
	if (pars && pars->token == OPP && !ft_strncmp(pars->str, "|", 1)
		&& ft_strlen(pars->str) == 1)
		(*cmd)->first->pipe_op = TRUE;
	else if (pars && pars->token == OPP && !ft_strncmp(pars->str, "||", 2)
		&& ft_strlen(pars->str) == 2)
		(*cmd)->first->or_op = TRUE;
	else if (pars && pars->token == OPP && !ft_strncmp(pars->str, "&&", 2)
		&& ft_strlen(pars->str) == 2)
		(*cmd)->first->and_op = TRUE;
}
