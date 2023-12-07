/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <qpuig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 13:46:45 by qbanet            #+#    #+#             */
/*   Updated: 2023/12/07 17:15:35 by qpuig            ###   ########.fr       */
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
	line = verif_split(line);
	oui = t_env_elems_first(line[0], line[1]);
	free_dtab(line);
	i = 1;
	while (env->env_cpy[i])
	{
		line = ft_split(env->env_cpy[i], '=');
		line = verif_split(line);
		t_env_elems_next(oui, line[0], line[1]);
		free_dtab(line);
		oui = oui->next;
		i ++;
	}
	return (oui->first);
}

char	**verif_split(char **dstr)
{
	int		i;
	char	**res;
	int		total_len;

	i = 0;
	total_len = 0;
	if (dstr[1] != 0 && dstr[2] != 0)
	{
		res = ft_calloc(sizeof(char *), 3);
		res[0] = ft_strdup(dstr[0]);
		while (dstr[++i])
			total_len += ft_strlen(dstr[i]);
		res[1] = ft_calloc(sizeof(char), total_len + 1);
		i = 0;
		while (dstr[++i])
		{
			ft_strlcat(res[1], dstr[i], total_len);
			ft_strlcat(res[1], "=", total_len);
		}
		ft_strlcat(res[1], "\0", total_len);
		return (free_dtab(dstr), res);
	}
	else if (!dstr[1])
	{
		res = ft_calloc(sizeof(char *), 2);
		res[0] = ft_strdup(dstr[0]);
		res[1] = NULL;
		return (free_dtab(dstr), res);
	}
	return (dstr);
}
