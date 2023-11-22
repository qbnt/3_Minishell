/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <qpuig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:11:23 by qpuig             #+#    #+#             */
/*   Updated: 2023/11/21 17:22:44 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_pwd(t_env env)
{
    char	*path;
	
	path = ft_calloc(ft_strlen(env_pwd), sizeof(char));
	ft_printf("%s", getcwd(path, ft_strlen(env_pwd)));
	free(path);
	exit(SUCCESS);
}