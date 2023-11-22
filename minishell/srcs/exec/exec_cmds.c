/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:56:27 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/22 17:29:41 by qbanet           ###   ########.fr       */
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
			ft_pwd(ms->env);
		else if (!ft_strncmp(ms->cmds[i]->str, "exit", 4))
			ft_exit();
//		else
//			select_syst_cmd();
		i ++;
	}
}
