/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:12:59 by qbanet            #+#    #+#             */
/*   Updated: 2023/10/28 15:55:46 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*----------------------------------------------------------------------------*/

int	main(int argc, char **argv, char **envp)
{
	t_pars		*test;
//	t_l_args	*test2;

	argv += 0;
	envp += 0;
	test = set_str_to_t_pars(argv[1]);
	ft_print_t_pars(&test);
//	test2 = set_pars_to_l_args(test);
//	test2 += 0;
	return (argc);
}
