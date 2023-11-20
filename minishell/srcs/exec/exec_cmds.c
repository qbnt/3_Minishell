/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:56:27 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/20 17:49:10 by qbanet           ###   ########.fr       */
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
		printf("| Exec	->	%s	gr = %d|\n\n", ms->cmds[i]->str,
			ms->cmds[i]->group);
		if (!ft_strncmp(ms->cmds[i]->str, "echo", 4))
			ft_echo(ms->cmds[i]);
		i ++;
		printf("-------------------------------\n");
	}
	printf("\n\n");
}
