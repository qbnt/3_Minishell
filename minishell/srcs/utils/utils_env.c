/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 13:46:45 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/30 16:05:34 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void			cpy_system_env(char **system_env, char **dest);
static t_env_elems	*set_env_elems(t_env *env);

/*============================================================================*/

t_env	*ft_envcpy(char **system_env)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	env->env_cpy = ft_calloc(sizeof(char *), (ft_tablen(system_env) + 1));
	cpy_system_env(system_env, env->env_cpy);
	env->env_elems = set_env_elems(env);
	return (env);
}

static void	cpy_system_env(char **system_env, char **dest)
{
	int		i;
	int		j;

	i = 0;
	while (system_env[i])
	{
		j = 0;
		dest[i] = ft_calloc(sizeof(char *), (ft_strlen(system_env[i]) + 1));
		while (system_env[i][j])
		{
			dest[i][j] = system_env[i][j];
			j ++;
		}
		dest[i][j] = 0;
		i ++;
	}
	dest[i] = 0;
}

static t_env_elems	*set_env_elems(t_env *env)
{
	t_env_elems	*oui;
	char		**line;
	int			i;

	line = ft_split(env->env_cpy[0], '=');
	oui = t_env_elems_first(line[0], line[1]);
	free (line);
	i = 1;
	while (env->env_cpy[i])
	{
		line = ft_split(env->env_cpy[i], '=');
		t_env_elems_next(oui, line[0], line[1]);
		free (line);
		oui = oui->next;
		i ++;
	}
	return (oui->first);
}
