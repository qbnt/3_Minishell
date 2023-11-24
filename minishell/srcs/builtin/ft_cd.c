/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <qpuig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:38:58 by qpuig             #+#    #+#             */
/*   Updated: 2023/11/24 14:58:47 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cd(t_pars *cmds, t_env *env) // pas sur qu'un pointeur simple mofifie le vrai env
{

	char	*old;

	if (cmds->next)
		cmds = cmds->next;
	if (chdir(env->env_elems->value) == 0)
	{
		while ((ft_strcmp(env->env_elems->key, "PWD") == FALSE) && env->env_elems->next)
			env->env_elems = env->env_elems->next;
		if (ft_strcmp(env->env_elems->key, "PWD") == TRUE)
		{
			old = ft_calloc((env->env_elems->value_len + 1), sizeof(char));
			old = env->env_elems->value;
			env->env_elems->value = getcwd(env->env_elems->value, 4096);
			env->env_elems = env->env_elems->first;
			while ((ft_strcmp(env->env_elems->key, "OLDPWD") == FALSE) && env->env_elems->next)
				env->env_elems = env->env_elems->next;
			if (ft_strcmp(env->env_elems->key, "OLDPWD") == TRUE)
				env->env_elems->value = old;
			free(old);
		}
	}
}