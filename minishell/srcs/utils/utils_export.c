/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:01:38 by qpuig             #+#    #+#             */
/*   Updated: 2023/12/07 19:11:59 by qbanet           ###   ########.fr       */
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
	t_env_elems	*tmp;

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

static void	allocate_key(char **key, char *str, int len)
{
	int	i;

	*key = (char *)malloc(len + 1);
	if (*key == NULL)
		return ;
	i = -1;
	while (++i < len)
		(*key)[i] = str[i];
	(*key)[len] = '\0';
}

static void	allocate_value(char **value, char *str, int len)
{
	*value = strdup(str + len + 1);
	if (*value == NULL)
		return ;
}

void	ft_key(t_pars *cmds, char **key, char **value)
{
	int	len;

	*key = NULL;
	*value = NULL;
	len = 0;
	while (cmds->str[len] && cmds->str[len] != '=')
		len++;
	allocate_key(key, cmds->str, len);
	if (cmds->str[len] == '=')
		allocate_value(value, cmds->str, len);
	else
		*value = NULL;
}
