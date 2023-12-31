/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:08:56 by qbanet            #+#    #+#             */
/*   Updated: 2023/12/08 11:45:14 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*----------------------------------------------------------------------------*/

t_bool	ft_is_whitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r')
		return (1);
	else
		return (0);
}

t_bool	ft_is_opp(char c)
{
	if (c == '|' || c == '>' || c == '<' || c == '&')
		return (1);
	else
		return (0);
}

t_bool	ft_strcmp(const char *s1, const char *s2)
{
	if (ft_strlen(s1) != ft_strlen(s2))
		return (FALSE);
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (FALSE);
		s1 ++;
		s2 ++;
	}
	return (TRUE);
}

size_t	ft_tablen(char **dtab)
{
	size_t	len;

	len = 0;
	while (dtab[len])
		len ++;
	return (len);
}

void	free_cmds_tab(t_pars **cmds, int nb_cmds)
{
	int	i;

	i = -1;
	while (++i < nb_cmds && cmds[i])
		free_t_pars(cmds[i]);
	free(cmds);
}
