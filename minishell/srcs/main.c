/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:12:59 by qbanet            #+#    #+#             */
/*   Updated: 2023/10/30 14:57:48 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*----------------------------------------------------------------------------*/

int	main(int argc, char **argv, char **envp)
{
	t_pars		*test;
	t_l_args	*test2;

	argv += 0;
	envp += 0;
	test = set_str_to_t_pars(argv[1]);
	test2 = set_pars_to_l_args(test);
	ft_print_t_l_args(&test2);
	return (argc);
}
