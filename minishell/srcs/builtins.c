/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <qpuig@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:17:30 by qpuig             #+#    #+#             */
/*   Updated: 2023/11/20 12:17:30 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	echo(t_mini *mini)
{
	int	i;
	int	flag;

	i = 1;
	flag = 0;
	mini = mini->cmds->next
	if (mini->cmds->token == 11)
	{
		while (str[i] == 'n')
			i++
		if (str[i] != ' ')
			return (FAIL);
		mini = mini->cmds->next;
		flag = 1;
	}
	while (mini->cmds)
	{
		ft_printf("%s", mini->cmds->str);
		if (mini->cmds->next)
		{
			ft_printf(" ");
			mini = mini->cmds->next;
		}
	}
	if (flag == 0)
		ft_printf("\n");
	return (SUCCESS);
}
// cd
// pwd
// export
// unset
// env
// exit