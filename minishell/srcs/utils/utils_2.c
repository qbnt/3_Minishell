/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:04:44 by qbanet            #+#    #+#             */
/*   Updated: 2023/12/06 10:50:03 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*============================================================================*/

int	ft_strchr_ex(const char *str, int c)
{
	int	i;

	i = 0;
	if (c == 0)
		return (0);
	while (str[i])
	{
		if (str[i] == (char)c)
			return (1);
		i ++;
	}
	return (0);
}

int	ft_envlen(t_env *env)
{
	int	i;

	i = 0;
	while (env->env_elems)
	{
		i++;
		if (env->env_elems->next)
			env->env_elems = env->env_elems->next;
		else
			break ;
	}
	env->env_elems = env->env_elems->first;
	return (i);
}

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
