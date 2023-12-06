/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <qpuig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:11:23 by qpuig             #+#    #+#             */
/*   Updated: 2023/12/05 15:41:29 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_pwd(void)
{
    char	*path;

	path = ft_calloc(4096, sizeof(char));
	getcwd(path, 4096);
	ft_printf("%s\n", path);
	free(path);
	return (SUCCESS);
}