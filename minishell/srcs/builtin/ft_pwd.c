/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:11:23 by qpuig             #+#    #+#             */
/*   Updated: 2023/12/08 15:36:15 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(void)
{
	char	*path;

	path = ft_calloc(4097, sizeof(char));
	getcwd(path, 4096);
	ft_printf("%s\n", path);
	free(path);
	return (SUCCESS);
}

void	tilde_case(t_pars **cmds)
{
	t_pars	*tmp;

	if ((*cmds)->next)
		*cmds = (*cmds)->next;
	else
	{
		tmp = ft_calloc(1, sizeof(t_pars));
		tmp->str = ft_strdup("~");
		tmp->prev = *cmds;
		tmp->next = NULL;
		tmp->first = *cmds;
		tmp->and_op = (*cmds)->and_op;
		tmp->and_op = (*cmds)->or_op;
		tmp->and_op = (*cmds)->pipe_op;
		tmp->group = (*cmds)->group;
		tmp->token = STR;
		(*cmds)->next = tmp;
		(*cmds) = (*cmds)->next;
	}
	if (ft_strcmp((*cmds)->str, "~") == TRUE)
	{
		free((*cmds)->str);
		(*cmds)->str = ft_calloc((ft_strlen(getenv("HOME")) + 1), sizeof(char));
		ft_strcpy((*cmds)->str, getenv("HOME"));
	}
}
