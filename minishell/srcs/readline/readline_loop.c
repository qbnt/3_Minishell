/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 20:33:50 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/20 11:42:57 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool	space_input(char *input);
static t_bool	stop_input(char *input);
static t_bool	env_input(char *input);		//fonction provisoire

/*============================================================================*/

void	readline_loop(t_mini *ms)
{
	char	*input;

	rl_bind_key('\t', rl_complete);
	while (1)
	{
		input = readline("minishell v1.5 > ");
		if (stop_input(input))
			break ;
		if (space_input(input))
			continue ;
		if (env_input(input))
		{
			ft_print_t_env_elems(ms->env->env_elems);
			continue ;
		}
		add_history(input);
		ms->cmds = parsing(input, ms);
		if (!ms->cmds)
			continue ;
		exec_cmds(ms);
	}
}

static t_bool	env_input(char *input)
{
	if (ft_strncmp(input, "#env", 4))
		return (FALSE);
	else
	{
		free(input);
		return (TRUE);
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