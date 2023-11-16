/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_t_pars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:06:14 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/16 15:06:03 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*make_str_in_t_pars(t_in **in);
//static void	create_cmd(char *cmd, int *i, size_t *len, t_in **in);

/*----------------------------------------------------------------------------*/

t_pars	*t_pars_first(t_in **in)
{
	t_pars	*oui;

	oui = malloc(sizeof(t_pars));
	oui->first = oui;
	oui->prev = NULL;
	oui->next = NULL;
	oui->str = make_str_in_t_pars(in);
	oui->token = NO_TOKEN;
	return (oui);
}

void	t_pars_add_next(t_in **in, t_pars *full_cmd)
{
	t_pars	*oui;

	oui = malloc(sizeof(t_pars));
	oui->first = full_cmd->first;
	oui->prev = full_cmd;
	oui->next = NULL;
	oui->str = make_str_in_t_pars(in);
	oui->token = NO_TOKEN;
	full_cmd->next = oui;
	full_cmd = oui;
}

static char	*make_str_in_t_pars(t_in **in)
{
	char	*cmd;
	size_t	len;
	int		i;

	while ((*in) && ft_is_whitespace((*in)->c))
		(*in) = (*in)->next;
	len = ft_nodelen(in);
	cmd = malloc((sizeof(char) * len) + 1);
	i = 0;
	while (*in && len - i)
	{
		cmd[i++] = (*in)->c;
		(*in) = (*in)->next;
	}
	return (cmd[i] = 0, cmd);
}

int	t_pars_pick_token(t_pars *arg)
{
	if (ft_isalpha(arg->str[0])
		&& (arg->prev == NULL || (arg->prev->str[0] == '|')
			|| arg->prev->str[0] == '&'))
		return (CMD);
	else if (arg->str[0] == 34)
		return (STR);
	else if (arg->str[0] == 39)
		return (LIT_STR);
	else if ((arg->str[0] == '-' && arg->str[1] != 0)
		&& (t_pars_pick_token(arg->prev) != STR))
		return (ARGS);
	else if (arg->str[0] == '|' || !ft_strncmp(arg->str, "&&", 2)
		|| !ft_strncmp(arg->str, "||", 2))
		return (OPP);
	else if ((arg->str[0] == '<' || arg->str[0] == '>')
		&& ft_strlen(arg->str) == 1)
		return (REDIR);
	else if (!ft_strncmp(arg->str, ">>", 2) && ft_strlen(arg->str) == 2)
		return (RE_IN);
	else if (!ft_strncmp(arg->str, "<<", 2) && ft_strlen(arg->str) == 2)
		return (RE_OUT);
	else if (!ft_strncmp(arg->str, "&&", 2) && ft_strlen(arg->str) == 2)
		return (AND);
	else
		return (STR);
}
