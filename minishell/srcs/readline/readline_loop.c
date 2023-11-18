/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 20:33:50 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/18 20:42:11 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool	space_input(char *input);
static t_bool	stop_input(char *input);

/*============================================================================*/

void	readline_loop(t_mini *ms)
{
	char	*input;
	t_pars	*pars;

	rl_bind_key('\t', rl_complete);
	while (1)
	{
		input = readline("minishell v1.5 > ");
		if (space_input(input))
			continue ;
		if (stop_input(input))
			break ;
		add_history(input);
		ms->elem_pars = check_input(input);
		if (ms->elem_pars == NULL)
			continue ;
		pars = parsing(input);
		if (!pars)
			continue ;
		ms->cmds = make_clear_cmds(ms->elem_pars, pars->first);
	}
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

static t_bool	space_input(char *input)
{
	while (ft_is_whitespace(*input))
		input ++;
	if (!*input)
		return (TRUE);
	else
		return (FALSE);
}