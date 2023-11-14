/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:12:59 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/14 21:57:27 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool	space_input(char *input);

/*----------------------------------------------------------------------------*/

int	main(int argc, char **argv, char **envp)
{
	t_mini		*ms;
	char		*input;

	argv += 0;
	envp += 0;
	ms = malloc(sizeof(t_mini));
	rl_bind_key('\t', rl_complete);
	while (1)
	{
		input = readline("minishell v1.0 > ");
		if (space_input(input))
			continue ;
		add_history(input);
		ms->elem_pars = check_input(input);
		if (ms->elem_pars == NULL)
			continue ;
		ms->args = parsing(input);
		ft_print_t_pars(&ms->args);
	}
	return (argc);
}

static t_bool	space_input(char *input)
{
	while (ft_is_whitespace(*input))
		input ++;
	if (!*input)
		return (TRUE);
	else
		return (FALSE);
}
