/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_t_l_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:06:14 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/04 15:28:45 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*t_l_args_make_str(t_pars **pars);
static int	t_l_args_pick_token(t_pars **pars, t_l_args *arg);

/*----------------------------------------------------------------------------*/

t_l_args	*t_l_args_first(t_pars **pars)
{
	t_l_args	*oui;

	oui = malloc(sizeof(t_l_args));
	oui->prev = NULL;
	oui->next = NULL;
	oui->str = t_l_args_make_str(pars);
	oui->token = CMD;
	return (oui);
}

void	t_l_args_add_next(t_pars **pars, t_l_args *full_cmd)
{
	t_l_args	*oui;

	oui = malloc(sizeof(t_l_args));
	oui->prev = full_cmd;
	oui->next = NULL;
	oui->str = t_l_args_make_str(pars);
	oui->token = t_l_args_pick_token(pars, full_cmd);
	full_cmd->next = oui;
	full_cmd = oui;
}

static char	*t_l_args_make_str(t_pars **pars)
{
	char	*cmd;
	int		i;

	while (ft_is_whitespace((*pars)->c))
		(*pars) = (*pars)->next;
	cmd = malloc((sizeof(char) * ft_ltrlen(pars)) + 1);
	cmd[0] = (*pars)->c;
	printf("make str -> pars[0] = %c\n", (*pars)->c);
	(*pars) = (*pars)->next;
	i = 1;
	while ((*pars) && !ft_is_whitespace((*pars)->c))
	{
		cmd[i ++] = (*pars)->c;
		(*pars) = (*pars)->next;
	}
	printf("\n");
	cmd[i] = 0;
	return (cmd);
}

static int	t_l_args_pick_token(t_pars **pars, t_l_args *arg)
{
	t_pars	*test;

	test = *pars;
	printf("pick token -> str[0] = %c\n", arg->str[0]);
	if (arg->str[0] == '-')
		return (ARGS);
	else if (arg->str[0] == 34
		|| (arg->prev && (arg->prev->token == STR && (test && test->c != 34))))
		return (STR);
	else if (arg->str[0] == 39)
		return (STR);
	else if (arg->str[0] == '|')
		return (REDIR);
	return (ERR);
}
