/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:44:29 by qpuig             #+#    #+#             */
/*   Updated: 2023/12/05 16:45:04 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit(t_pars *cmd, t_mini **ms)
{
	if (!cmd->pipe_op)
	{
		free_cmds_tab((*ms)->cmds, (*ms)->elem_pars->nb_cmd);
		free_pipes((*ms)->pipes);
		free((*ms)->elem_pars);
		free_all(*ms);
		exit(SUCCESS);
	}
}
