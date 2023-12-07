/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:55:17 by qbanet            #+#    #+#             */
/*   Updated: 2023/12/07 14:13:09 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

static int	print_export(t_env *env);
static void	export_tab_creat(int *env_len, t_env *env, char ***dbtab);

/*============================================================================*/

int	ft_export_2(t_mini **ms, t_pars *cmd)
{
	char		**res;
	t_env_elems	*add_env;

	if (!cmd->next)
		return (print_export((*ms)->env));
	cmd = cmd->next;
	res = ft_split(cmd->str, '=');
	res = verif_split(res);
	add_env = t_env_elems_first(res[0], res[1]);
	free_dtab(res);
	while (cmd)
	{
		res = ft_split(cmd->str, '=');
		res = verif_split(res);
		t_env_elems_next(add_env, res[0], res[1]);
		free_dtab(res);
		cmd = cmd->next;
	}
	add_env = add_env->first;
	return (SUCCESS);
}

static int	print_export(t_env *env)
{
	char		**dbtab;
	int			env_len;

	env_len = ft_envlen(env);
	dbtab = ft_calloc(env_len, sizeof(char *));
	export_tab_creat(&env_len, env, &dbtab);
	while (env_len < ft_envlen(env))
	{
		ft_printf("declare -x %s=\"%s\"\n", dbtab[env_len],
			getenv(dbtab[env_len]));
		free(dbtab[env_len]);
		env_len ++;
	}
	free(dbtab);
	return (SUCCESS);
}

static void	export_tab_creat(int *env_len, t_env *env, char ***dbtab)
{
	t_env_elems	*travel;
	int			i;

	while (*env_len > 0)
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
		(*dbtab)[i] = ft_strdup(env->env_elems->key);
		(*env_len)--;
		if (env->env_elems->next)
			env->env_elems = env->env_elems->next;
	}
}
