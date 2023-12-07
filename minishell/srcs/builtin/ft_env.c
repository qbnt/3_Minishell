/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <qpuig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:02:32 by qpuig             #+#    #+#             */
/*   Updated: 2023/12/07 14:01:29 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(t_env *env)
{
	while (env->env_elems && env->env_elems->key)
	{
		if (env->env_elems->value)
			ft_printf("%s=%s\n", env->env_elems->key, env->env_elems->value);
		if (env->env_elems->next)
			env->env_elems = env->env_elems->next;
		else
			break ;
	}
	env->env_elems = env->env_elems->first;
	return (SUCCESS);
}
