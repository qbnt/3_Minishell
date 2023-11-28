/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:38:58 by qpuig             #+#    #+#             */
/*   Updated: 2023/11/27 14:18:31 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cd(t_pars *cmds, t_env *env) // pas sur qu'un pointeur simple mofifie le vrai env
{

	char	*old;

	if (cmds->next)
		cmds = cmds->next;
	if (chdir(cmds->str) == 0)
	{
		while ((ft_strcmp(env->env_elems->key, "PWD") == FALSE) && env->env_elems->next)
			env->env_elems = env->env_elems->next;
		if (ft_strcmp(env->env_elems->key, "PWD") == TRUE)
		{
			old = ft_calloc((env->env_elems->value_len + 1), sizeof(char));
			ft_strcpy(old, env->env_elems->value);
			free(env->env_elems->value);
			env->env_elems->value = ft_calloc(4097, sizeof(char));
			getcwd(env->env_elems->value, 4096);
			env->env_elems = env->env_elems->first;
			while ((ft_strcmp(env->env_elems->key, "OLDPWD") == FALSE) && env->env_elems->next)
				env->env_elems = env->env_elems->next;
			if (ft_strcmp(env->env_elems->key, "OLDPWD") == TRUE)
			{
				free(env->env_elems->value);
				env->env_elems->value = ft_calloc((ft_strlen(old) + 1), sizeof(char));
				ft_strcpy(env->env_elems->value, old);
			}
			free(old);
		}
	}
	else 
		ft_printf("cd: %s: No such file or directory\n", cmds->str);
	env->env_elems = env->env_elems->first;
}
