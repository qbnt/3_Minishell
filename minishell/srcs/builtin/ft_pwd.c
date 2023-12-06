/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:11:23 by qpuig             #+#    #+#             */
/*   Updated: 2023/12/06 10:51:41 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(void)
{
	char	*path;

	path = ft_calloc(4096, sizeof(char));
	getcwd(path, 4096);
	ft_printf("%s\n", path);
	free(path);
	return (SUCCESS);
}
