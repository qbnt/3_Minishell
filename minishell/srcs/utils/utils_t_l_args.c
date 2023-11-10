/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_t_l_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:06:14 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/10 14:59:02 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*t_l_args_make_str(t_pars **pars);
static void	create_cmd(char *cmd, int *i, size_t *len, t_pars **pars);

/*----------------------------------------------------------------------------*/

t_l_args	*t_l_args_first(t_pars **pars)
{
	t_l_args	*oui;

	oui = malloc(sizeof(t_l_args));
	oui->first = oui;
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
	oui->first = full_cmd->first;
	oui->prev = full_cmd;
	oui->next = NULL;
	oui->str = t_l_args_make_str(pars);
	oui->token = NO_TOKEN;
	full_cmd->next = oui;
	full_cmd = oui;
}

static char	*t_l_args_make_str(t_pars **pars)
{
	char	*cmd;
	size_t	len;
	int		i;

	while ((*pars) && ft_is_whitespace((*pars)->c))
		(*pars) = (*pars)->next;
	len = ft_ltrlen(pars);
	printf("len = %ld\n", len);
	cmd = malloc((sizeof(char) * len) + 1);
	i = -1;
	while ((*pars) && !ft_is_whitespace((*pars)->c))
	{
		create_cmd(cmd, &i, &len, pars);
	}
	if ((*pars))
		(*pars) = (*pars)->next;
	return (cmd[++i] = 0, cmd);
}

static void	create_cmd(char *cmd, int *i, size_t *len, t_pars **pars)
{
	if ((*pars)->c == 34)
	{
		cmd[++(*i)] = (*pars)->c;
		(*pars) = (*pars)->next;
		while (*len - 1 - *i)
		{
			printf("pars c = %c\n", (*pars)->c);
			cmd[++(*i)] = (*pars)->c;
			(*pars) = (*pars)->next;
		}
	}
	else
	{
		cmd[++(*i)] = (*pars)->c;
		(*pars) = (*pars)->next;
	}
}

int	t_l_args_pick_token(t_l_args *arg)
{
	if (ft_isalpha(arg->str[0])
		&& (arg->prev == NULL || arg->prev->str[0] == '|'))
		return (CMD);
	else if (arg->str[0] == 34 || arg->str[0] == 39)
		return (STR);
	if ((arg->str[0] == '-' && arg->str[1] != 0)
		&& (t_l_args_pick_token(arg->prev) != STR))
		return (ARGS);
	else if (arg->str[0] == '|' || arg->str[0] == '>' || arg->str[0] == '<')
		return (OPP);
	else
		return (STR);
	return (ERR);
}
