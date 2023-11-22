/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:41:10 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/22 22:55:26 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*============================================================================*/

char	**get_dtab_cmd(t_pars *cmd)
{
	char	**res;
	size_t	parslen;
	size_t	i;

	parslen = t_parslen(cmd);
	res = ft_calloc(parslen + 1, sizeof(char *));
	i = 0;
	while (i < parslen)
	{
		res[i] = ft_strdup(cmd->str);
		i ++;
	}
	return (res);
}
