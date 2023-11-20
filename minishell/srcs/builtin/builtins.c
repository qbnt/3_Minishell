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

int	ft_echo(t_pars *cmds)
{
	int	i;
	int	flag;

	i = 1;
	flag = 0;
	cmds = cmds->next;
	if (cmds->token == 11)
	{
		while (cmds->str[i] == 'n')
			i++;
		if (cmds->str[i] != ' ') //si c'est pas un n en premier ni au milieu ca return 
			return (FAIL);
		cmds = cmds->next; // je passe au prochain dans le if au cas ou y'a pas de -n
		flag = 1; // la verif pour la fin
	}
	while (cmds && (cmds->token == 12 || cmds->token == 18)) // tant que y'a des trucs a ecrire
	{
		ft_printf("%s", cmds->str);
		if (cmds->next) // si y'a une autre string je met un espace
		{
			ft_printf(" ");
			cmds = cmds->next;
		}
		else
			cmds = cmds->next;
	}
	if (flag == 0) //si y'a pas de flag je rajoute une newline
		ft_printf("\n");
	return (SUCCESS);
}

// cd
// pwd
// export
// unset
// env
// exit