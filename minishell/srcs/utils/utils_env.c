/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 13:46:45 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/18 20:27:22 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*----------------------------------------------------------------------------*/

char	**ft_envcpy(char **system_env)
{
	int		i;
	int		j;
	char	**env_res;

	i = 0;
	env_res = ft_calloc(sizeof(char *), (ft_tablen(system_env) + 1));
	while (system_env[i])
	{
		j = 0;
		env_res[i] = ft_calloc(sizeof(char *), (ft_strlen(system_env[i]) + 1));
		while (system_env[i][j])
		{
			env_res[i][j] = system_env[i][j];
			j ++;
		}
		env_res[i][j] = 0;
		i ++;
	}
	env_res[i] = 0;
	return (env_res);
}
