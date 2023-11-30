/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:04:44 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/30 14:46:57 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*============================================================================*/

void	free_dtab(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free (str);
}

size_t	t_parslen(t_pars *cmd)
{
	size_t	len;

	len = 0;
	while (cmd)
	{
		len++;
		cmd = cmd->next;
	}
	return (len);
}

int	switch_res(char **str, t_mini *ms, int total_len, char *res_str)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_itoa(ms->res);
	ft_strlcat(res_str, tmp, total_len + 1);
	(*str) += 2;
	i += ft_strlen(tmp);
	free (tmp);
	return (i);
}
