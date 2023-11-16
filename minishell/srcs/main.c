/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:12:59 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/16 14:52:54 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool	space_input(char *input);

/*----------------------------------------------------------------------------*/

int	main(int argc, char **argv, char **envp)
{
	t_mini		*ms;
	t_pars		*pars;
	char		*input;

	argv += 0;
	envp += 0;
	ms = malloc(sizeof(t_mini));
	rl_bind_key('\t', rl_complete);
	while (1)
	{
		input = readline("minishell v1.5 > ");
		if (space_input(input))
			continue ;
		add_history(input);
		ms->elem_pars = check_input(input);
		if (ms->elem_pars == NULL)
			continue ;
		pars = parsing(input);
		if (!pars)
			continue ;
		ms->cmds = make_clear_cmds(ms->elem_pars, pars->first);
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
