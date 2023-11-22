/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:11:23 by qpuig             #+#    #+#             */
/*   Updated: 2023/11/22 16:46:10 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_pwd(t_env *env)
{
    char	*path;

	while (ft_strcmp(env->env_elems->key, "PWD") != TRUE)
		env->env_elems = env->env_elems->next;
	if (env->env_elem)
	{
		path = ft_calloc(env->env_elems->value_len, sizeof(char));
		ft_printf("%s", getcwd(path, env->env_elems->value_len));
		free(path);
		exit(SUCCESS);
	}
}
