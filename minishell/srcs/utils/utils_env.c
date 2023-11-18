/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 13:46:45 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/18 21:06:55 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	cpy_system_env(char **system_env, char **dest);
static void	create_env(char **new_env);

/*============================================================================*/

char	**ft_envcpy(char **system_env)
{
	int		i;
	int		j;
	char	**env_res;

	if (!system_env)
		create_env(env_res);
	else
		cpy_system_env(system_env, env_res);
	return (env_res);
}

static void	cpy_system_env(char **system_env, char **dest)
{
	int		i;
	int		j;

	i = 0;
	dest = ft_calloc(sizeof(char *), (ft_tablen(system_env) + 1));
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

static void	create_env(char **new_env)
{
	printf("create\n");
}
