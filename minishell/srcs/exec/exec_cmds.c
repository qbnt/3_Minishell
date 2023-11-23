/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <qpuig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:56:27 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/23 15:32:20 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*============================================================================*/

void	exec_cmds(t_mini *ms)
{
	int	i;

	i = 0;
	while (i < ms->elem_pars->nb_cmd)
	{
		if (!ft_strncmp(ms->cmds[i]->str, "echo", 4))
			ft_echo(ms->cmds[i]);
		else if (!ft_strncmp(ms->cmds[i]->str, "pwd", 3))
			ft_pwd();
		else if (!ft_strncmp(ms->cmds[i]->str, "exit", 4))
			ft_exit();
//		else
//			select_syst_cmd();
		i ++;
	}
}
