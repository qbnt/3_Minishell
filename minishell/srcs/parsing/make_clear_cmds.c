/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_clear_cmds.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:03:57 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/17 16:49:24 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//static void		clear_prev(t_pars *res);
static t_pars	*cpy_cmd(t_pars *pars);
static void		select_opp(t_pars	*pars, t_pars **cmd);
static char		*clean_cote(char *str, t_token token);
static int		count_cote(char *str, t_token token);

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
		cmd->str = clean_cote(pars->str, pars->token);
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

static char	*clean_cote(char *str, t_token token)
{
	char	*res;
	int		nb_cote;
	int		i;

	nb_cote = count_cote(str, token);
	res = malloc((sizeof(char) * (ft_strlen(str) - nb_cote)) + 1);
	i = 0;
	while (*str)
	{
		if (token == STR)
		{
			if (*str != 34)
				res[i++] = *(str++);
			else
				str ++;
		}
		else
		{
			if (*str != 39)
				res[i++] = *(str++);
			else
				str ++;
		}
	}
	return (res[i] = 0, res);
}

static int	count_cote(char *str, t_token token)
{
	int		res;
	char	c;

	if (token == STR)
		c = 34;
	else if (token == LIT_STR)
		c = 39;
	else
		c = 0;
	res = 0;
	while (*str)
	{
		if (*str == c)
			res ++;
		str ++;
	}
	return (res);
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
