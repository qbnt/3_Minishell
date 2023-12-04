/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <qpuig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:47:20 by qpuig             #+#    #+#             */
/*   Updated: 2023/12/04 15:46:51 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_getenv(t_env *env, char *str)
{
	while ((ft_strcmp(env->env_elems->key, str) == FALSE) && env->env_elems->next)
			env->env_elems = env->env_elems->next;
	if (env->env_elems)
		return (env->env_elems->value);
	return (NULL);
}