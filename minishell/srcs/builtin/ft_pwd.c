/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <qpuig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:11:23 by qpuig             #+#    #+#             */
/*   Updated: 2023/11/22 15:59:44 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_pwd(t_env env)
{
    char	*path;
	
	while (ft_strcmp(env.env_elems->key, "PWD") != TRUE)
		env.env_elems = env.env_elems->next;
	path = ft_calloc(env.env_elems->value_len, sizeof(char));
	ft_printf("%s", getcwd(path, env.env_elems->value_len));
	free(path);
	exit(SUCCESS);
}