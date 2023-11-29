/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_clear_cmds.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:03:57 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/29 19:25:37 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_pars	*cpy_cmd(t_pars *pars, t_env_elems *env);
static char		*clean_cote(char *str, t_token token);
static int		clean_cote_loop(char *str, t_token token, char *res);
static void		clear_cmd(char **str, char *res, int *i);

/*----------------------------------------------------------------------------*/

t_pars	**make_clear_cmds(t_elem_pars *elems, t_pars *pars, t_env_elems *env)
{
	t_pars	**res;
	t_pars	*tmp;
	int		i;

	res = ft_calloc(sizeof(t_pars), elems->nb_cmd);
	i = -1;
	tmp = pars;
	while (++i < elems->nb_cmd)
	{
		res[i] = cpy_cmd(pars, env);
		while (pars && pars->token != OPP)
			pars = pars->next;
		while (pars && pars->token == OPP)
			pars = pars->next;
	}
	free_t_pars(tmp);
	return (res);
}

static t_pars	*cpy_cmd(t_pars *pars, t_env_elems *env)
{
	t_pars	*cmd;

	cmd = ft_calloc(sizeof(t_pars), 1);
	cmd->prev = NULL;
	cmd->first = cmd;
	while (pars && pars->token != OPP)
	{
		cmd->str = clean_dol(clean_cote(pars->str, pars->token), env,
				pars->token);
		cmd->group = pars->group;
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
	size_t	nb_cote;
	int		i;

	i = 0;
	nb_cote = count_cote(str, token);
	res = malloc((sizeof(char) * (ft_strlen(str) - nb_cote)) + 1);
	i = clean_cote_loop(str, token, res);
	return (res[i] = 0, res);
}

static int	clean_cote_loop(char *str, t_token token, char *res)
{
	int		i;

	i = 0;
	while (*str)
	{
		if (token == CMD)
			clear_cmd(&str, res, &i);
		else if (token == STR)
		{
			if (*str != 34)
				res[i++] = *(str++);
			else
				str ++;
		}
		else if (token == LIT_STR)
		{
			if (*str != 39)
				res[i++] = *(str++);
			else
				str ++;
		}
		else
			res[i++] = *(str++);
	}
	return (i);
}

static void	clear_cmd(char **str, char *res, int *i)
{
	int	j;

	j = *i;
	if ((*(*str)) != 34 && (*(*str)) != 39)
				res[j++] = (*(*str)++);
	else
		(*str)++;
	*i += (j - (*i));
}
