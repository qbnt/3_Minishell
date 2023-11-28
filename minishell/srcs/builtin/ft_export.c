/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <qpuig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:10:52 by qpuig             #+#    #+#             */
/*   Updated: 2023/11/28 17:40:00 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_tri(t_env *env)
{
	int	i;
	int	envlen;
	char	**dbtab;
	t_env_elems	*travel;

	envlen = ft_envlen(env);
	dbtab = ft_calloc((ft_envlen(env) + 1), sizeof(char *));
	while (envlen > 0)
	{
		i = 0;
		travel = env->env_elems->first;
		while (travel)
		{
			if (ft_strcmp_ex(env->env_elems->key, travel->key) > 0)
				i++;
			if (travel->next)
				travel = travel->next;
			else
				break ;
		}
		dbtab[i] = ft_strdup(env->env_elems->key);
		envlen--;
		if (env->env_elems->next)
			env->env_elems = env->env_elems->next;
	}
	while (envlen < ft_envlen(env))
	{
		ft_printf("declare -x %s=\"%s\"\n", dbtab[envlen], getenv(dbtab[envlen]));
		free(dbtab[envlen]);
		envlen++;
	}
	free(dbtab);
	env->env_elems = env->env_elems->first;
}

int	ft_export(t_pars *cmds, t_env *env)
{
	if (!cmds->next)
		ft_tri(env);
	return (SUCCESS);
}