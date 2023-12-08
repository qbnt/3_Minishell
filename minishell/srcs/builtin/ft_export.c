/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:10:52 by qpuig             #+#    #+#             */
/*   Updated: 2023/12/07 19:18:31 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_dbtab(t_env *env)
{
	int			i;
	int			envlen;
	char		**dbtab;
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
	return (env->env_elems = env->env_elems->first, dbtab);
}

void	ft_egal_ex(t_env *env, t_pars *cmds)
{
	int		i;
	int		len;
	int		j;
	char	*key;
	char	*value;

	i = 0;
	len = 0;
	while (cmds->str[i])
	{
		if (cmds->str[i] == '=')
		{
			key = ft_calloc((i + 1), sizeof(char));
			while (len < i)
			{
				key[len] = cmds->str[len];
				len++;
			}
			break ;
		}
		i++;
	}
	while (cmds->str[i])
		i++;
	value = ft_calloc((i - len + 1), sizeof(char));
	j = 0;
	while (len < i)
		value[j++] = cmds->str[++len];
	while (env->env_elems->next)
		env->env_elems = env->env_elems->next;
	t_env_elems_next(env->env_elems, key, value);
	env->env_elems = env->env_elems->first;
	multi_free_str(key, value, NULL, NULL);
}

void	ft_no_egal(t_env *env, t_pars *cmds)
{
	int		i;
	int		len;
	char	*key;

	i = 0;
	len = 0;
	while (cmds->str[i])
		i++;
	key = ft_calloc((i + 1), sizeof(char));
	while (len < i)
	{
		key[len] = cmds->str[len];
		len++;
	}
	while (env->env_elems->next)
		env->env_elems = env->env_elems->next;
	t_env_elems_next(env->env_elems, key, NULL);
	env->env_elems = env->env_elems->first;
	free(key);
}

void	ft_tri(t_env *env)
{
	int			envlen;
	char		**dbtab;
	char		*verif;

	dbtab = ft_dbtab(env);
	envlen = 0;
	while (envlen != ft_envlen(env))
	{
		verif = ft_getenv(env, dbtab[envlen]);
		if (verif)
			ft_printf("declare -x %s=\"%s\"\n", dbtab[envlen], verif);
		else
			ft_printf("declare -x %s\n", dbtab[envlen]);
		env->env_elems = env->env_elems->first;
		free(dbtab[envlen]);
		envlen++;
	}
	free(dbtab);
	env->env_elems = env->env_elems->first;
}

int	ft_export(t_pars *cmds, t_env *env)
{
	char	*keyc;
	char	*valuec;

	if (!cmds->next)
		ft_tri(env);
	cmds = cmds->next;
	while (cmds)
	{
		ft_key(cmds, &keyc, &valuec);
		if (ft_strchr_env(env, keyc) == 1)
		{
			change_value(&(env->env_elems), keyc, valuec);
			multi_free_str(keyc, valuec, NULL, NULL);
			cmds = cmds->next;
			continue ;
		}
		if ((ft_isalpha(cmds->str[0]) == 1)
			&& (ft_strchr_ex(cmds->str, '=') == 1))
			ft_egal_ex(env, cmds);
		else if ((ft_isalpha(cmds->str[0]) == 1)
			&& (ft_strchr_ex(cmds->str, '=') == 0))
			ft_no_egal(env, cmds);
		cmds = cmds->next;
		multi_free_str(keyc, valuec, NULL, NULL);
	}
	return (SUCCESS);
}
