/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <qpuig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:01:38 by qpuig             #+#    #+#             */
/*   Updated: 2023/12/07 18:11:27 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	change_value(t_env_elems **env, char *key, char *value)
{
	t_env_elems	*tmp;

	tmp = *env;
	while (*env)
	{
		if (ft_strcmp_ex((*env)->key, key) == 0 && value)
		{
			free((*env)->value);
			(*env)->value = ft_strdup(value);
			(*env) = tmp;
			return ;
		}
		(*env) = (*env)->next;
	}
	(*env) = tmp;
}

int	ft_strchr_env(t_env	*env, char *str)
{
	t_env_elems *tmp;
	
	tmp = env->env_elems->first;
	while (env->env_elems)
	{
		if (ft_strcmp_ex(env->env_elems->key, str) == 0)
		{
			env->env_elems = tmp;
			return (1);
		}
		env->env_elems = env->env_elems->next;
	}
	env->env_elems = tmp;
	return (0);
}

void	ft_key(t_pars *cmds, char **keyc, char **valuec)
{
	int	len;
	int	i;
	int	j;

	len = 0;
	i = 0;
	while (cmds->str[i])
	{
		if (cmds->str[i] == '=')
		{
			*keyc = ft_calloc((i + 1), sizeof(char));
			while (len < i)
			{
				(*keyc)[len] = cmds->str[len];
				len++;
			}
			break ;
		}
		i++;
	}
	while (cmds->str[i])
		i++;
	*valuec = ft_calloc((i - len + 1), sizeof(char));
	j = 0;
	while (len <= i)
		(*valuec)[j++] = cmds->str[++len];
}