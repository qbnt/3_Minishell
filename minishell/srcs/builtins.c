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

void	echo(t_pars *cmds)
{
	int	i; //index pour la verif du -n
	int	flag; //flag pour veif la presence d'un -n

	i = 1; // 1 pour pas check le tiret
	flag = 0;
	cmds = cmds->next // le premier c'est echo donc on skip
	if (cmds->token == 11) // verif de la presence du -n
	{
		while (str[i] == 'n') //si c'est pas un n il rentre pas dedans
			i++
		if (str[i] != ' ') //si c'est pas un n en premier ni au milieu ca return 
			return (FAIL);
		cmds = cmds->next; // je passe au prochain dans le if au cas ou y'a pas de -n
		flag = 1; // la verif pour la fin
	}
	while (cmds && (token == 12 || token == 18)) // tant que y'a des trucs a ecrire
	{
		ft_printf("%s", cmds->str);
		if (cmds->next) // si y'a une autre string je met un espace
		{
			ft_printf(" ");
			cmds = cmds->next;
		}
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