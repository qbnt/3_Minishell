/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_t_l_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:06:14 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/01 12:29:45 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*t_l_args_make_str(t_pars **pars);
static int	t_l_args_pick_token(char *str);

/*----------------------------------------------------------------------------*/

t_l_args	*t_l_args_first(t_pars **pars)
{
	t_l_args	*oui;

	oui = malloc(sizeof(t_l_args));
	oui->prev = NULL;
	oui->next = NULL;
	oui->str = t_l_args_make_str(pars);
	oui->token = NO_TOKEN;
	return (oui);
}

void	t_l_args_add_next(t_pars **pars, t_l_args *full_cmd)
{
	t_l_args	*oui;

	oui = malloc(sizeof(t_l_args));
	oui->prev = full_cmd;
	oui->next = NULL;
	oui->str = t_l_args_make_str(pars);
	oui->token = t_l_args_pick_token(oui->str);
	full_cmd->next = oui;
	full_cmd = oui;
}

static char	*t_l_args_make_str(t_pars **pars)
{
	char	*cmd;
	int		i;

	while ((*pars)->token == NO_TOKEN)
		(*pars) = (*pars)->next;
	cmd = malloc((sizeof(char) * ft_ltrlen(pars)) + 1);
	cmd[0] = (*pars)->c;
	(*pars) = (*pars)->next;
	i = 1;
	while ((*pars) && (*pars)->token == (*pars)->prev->token)
	{
		cmd[i ++] = (*pars)->c;
		(*pars) = (*pars)->next;
	}
	cmd[i] = 0;
	return (cmd);
}

static int	t_l_args_pick_token(char *str)
{
	str += 0;
	return (ERR);
}
