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

//ECHO : cette fonction prends en parametre le t_pars correspondant a la commande echo et print les parametres
//si le parametre -n est specifie la newline n est pas ajoutee

int	ft_echo(t_pars *cmds)
{
	int	i;
	int	flag;

	i = 1;
	flag = 0;
	cmds = cmds->next;
	while (cmds)
	{
		if (cmds->token == 11)
		{
			while (cmds->str[i] && cmds->str[i] == 'n')
				i++;
			if (cmds->str[i] && (cmds->str[i] != 'n'))
				cmds->token = 12;
		}
		if (cmds->token == 12 || cmds->token == 18)
		{
			ft_printf("%s", cmds->str);
			if (cmds->next)
				ft_printf(" ");
		}
		if (cmds->token == 11)
			flag = 1;
		if (cmds->next)
			cmds = cmds->next;
		else
			break ;
	}
	if (flag == 0)
		ft_printf("\n");
	return (SUCCESS);
}

// export
// unset