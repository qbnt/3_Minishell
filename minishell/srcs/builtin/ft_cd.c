/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:38:58 by qpuig             #+#    #+#             */
/*   Updated: 2023/12/08 15:36:36 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	update_pwd(t_env *env, char **old, t_env_elems *save);
static void	key_pwd_case(char **old, t_env *env);
static void	update_oldpwd(t_env *env, char **old);
static void	key_oldpwd_case(t_env *env, char **old);

int	ft_cd(t_pars *cmds, t_env *env)
{
	char		*old;
	t_env_elems	*save;

	save = env->env_elems->first;
	tilde_case(&cmds);
	if (chdir(cmds->str) == 0)
	{
		update_pwd(env, &old, save);
	}
	else
		ft_printf("cd: %s: No such file or directory\n", cmds->str);
	env->env_elems = save;
	return (SUCCESS);
}

static void	update_pwd(t_env *env, char **old, t_env_elems *save)
{
	while (env->env_elems && ft_strcmp(env->env_elems->key, "PWD") != TRUE)
		env->env_elems = env->env_elems->next;
	if (env->env_elems)
	{
		*old = ft_calloc((ft_strlen(env->env_elems->value) + 1), sizeof(char));
		key_pwd_case(old, env);
		env->env_elems = save;
		update_oldpwd(env, old);
		free(*old);
	}
}

static void	key_pwd_case(char **old, t_env *env)
{
	size_t	new_size;

	new_size = 4097;
	ft_strcpy(*old, env->env_elems->value);
	free(env->env_elems->value);
	env->env_elems->value = ft_calloc(new_size, sizeof(char));
	if (env->env_elems->value == NULL)
		return ;
	getcwd(env->env_elems->value, new_size - 1);
	env->env_elems->value[new_size - 1] = '\0';
	env->env_elems = env->env_elems->first;
}

static void	key_oldpwd_case(t_env *env, char **old)
{
	size_t	old_len;

	old_len = ft_strlen(*old) + 1;
	free(env->env_elems->value);
	env->env_elems->value = ft_calloc(old_len, sizeof(char));
	if (env->env_elems->value == NULL)
		return ;
	ft_strcpy(env->env_elems->value, *old);
}

static void	update_oldpwd(t_env *env, char **old)
{
	while (env->env_elems && ft_strcmp(env->env_elems->key, "OLDPWD") != TRUE)
		env->env_elems = env->env_elems->next;
	if (env->env_elems)
		key_oldpwd_case(env, old);
}
