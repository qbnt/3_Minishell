/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:38:58 by qpuig             #+#    #+#             */
/*   Updated: 2023/12/06 11:44:31 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	tilde_case(t_pars *cmds);
static void	key_pwd_case(char *old, t_env *env);
static void	key_oldpwd_case(t_env *env, char *old);

int	ft_cd(t_pars *cmds, t_env *env)
{
	char	*old;

	if (cmds->next)
		cmds = cmds->next;
	tilde_case(cmds);
	if (chdir(cmds->str) == 0)
	{
		while ((ft_strcmp(env->env_elems->key, "PWD") == FALSE)
			&& env->env_elems->next)
			env->env_elems = env->env_elems->next;
		if (ft_strcmp(env->env_elems->key, "PWD") == TRUE)
		{
			old = ft_calloc((env->env_elems->value_len + 1), sizeof(char));
			key_pwd_case(old, env);
			while ((ft_strcmp(env->env_elems->key, "OLDPWD") == FALSE)
				&& env->env_elems->next)
				env->env_elems = env->env_elems->next;
			key_oldpwd_case(env, old);
			free(old);
		}
	}
	else
		ft_printf("cd: %s: No such file or directory\n", cmds->str);
	return (env->env_elems = env->env_elems->first, SUCCESS);
}

static void	key_pwd_case(char *old, t_env *env)
{
	ft_strcpy(old, env->env_elems->value);
	free(env->env_elems->value);
	env->env_elems->value = ft_calloc(4097, sizeof(char));
	getcwd(env->env_elems->value, 4096);
	env->env_elems = env->env_elems->first;
}

static void	key_oldpwd_case(t_env *env, char *old)
{
	if (ft_strcmp(env->env_elems->key, "OLDPWD") == TRUE)
	{
		free(env->env_elems->value);
		env->env_elems->value
			= ft_calloc((ft_strlen(old) + 1), sizeof(char));
		ft_strcpy(env->env_elems->value, old);
	}
}

static void	tilde_case(t_pars *cmds)
{
	if (ft_strcmp(cmds->str, "~") == TRUE)
	{
		free(cmds->str);
		cmds->str = ft_calloc((ft_strlen(getenv("HOME")) + 1), sizeof(char));
		ft_strcpy(cmds->str, getenv("HOME"));
	}
}
