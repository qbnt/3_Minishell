/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:12:59 by qbanet            #+#    #+#             */
/*   Updated: 2023/10/27 13:51:09 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*----------------------------------------------------------------------------*/

int	main(int argc, char **argv, char **envp)
{
	t_pars	*test;

	argv += 0;
	envp += 0;
	test = set_str_to_t_pars("      echo bon | echo \"'oui' oui\" > oui.txt | echo $(USR)");
	printf("\n");
	while (test)
	{
		printf("%c", test->c);
		test = test->next;
	}
	return (argc);
}
