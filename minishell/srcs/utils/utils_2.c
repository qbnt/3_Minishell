/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <qpuig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:04:44 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/28 17:26:21 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*============================================================================*/

int	ft_strcmp_ex(char const *s1, char const *s2)
{
	while ((unsigned char)*s1 == (unsigned char)*s2 && *s1)
	{
		s1++;
		s2++;
	}
	if ((unsigned char)*s1 == (unsigned char)*s2)
		return (0);
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

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
