/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:12:59 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/10 14:36:29 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool	space_input(char *input);
static t_bool	stop_input(char *input);

/*----------------------------------------------------------------------------*/

int	main(int argc, char **argv, char **envp)
{
	t_pars		*test;
	t_l_args	*test2;
	char		*input;

	argv += 0;
	envp += 0;
	rl_bind_key('\t', rl_complete);
	while (1)
	{
		input = readline("minishell v1.0 > ");
		if (space_input(input))
			continue ;
		if (stop_input(input))
			exit(EXIT_SUCCESS);
		add_history(input);
		test = set_str_to_t_pars(input);
		ft_print_t_pars(&test, CHAR);
		test2 = set_pars_to_l_args(test);
		ft_print_t_l_args(&test2);
	}
	return (argc);
}

static t_bool	space_input(char *input)
{
	while (ft_is_whitespace(*input))
		input ++;
	if (!*input)
	{
		free(input);
		return (TRUE);
	}
	else
		return (FALSE);
}

static t_bool	stop_input(char *input)
{
	if (ft_strncmp(input, "exit", 5))
		return (FALSE);
	else
	{
		free(input);
		return (TRUE);
	}
}