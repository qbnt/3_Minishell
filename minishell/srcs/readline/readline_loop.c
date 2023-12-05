/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 20:33:50 by qbanet            #+#    #+#             */
/*   Updated: 2023/12/05 17:45:41 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool	space_input(char *input);
static t_bool	env_input(char *input);
static void		free_loop(char *input, t_mini *ms);

/*============================================================================*/

void	readline_loop(t_mini *ms)
{
	char	*input;

	rl_bind_key('\t', rl_complete);
	while (1)
	{
		input = readline(MS_NAME);
		if (!input)
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
		free_loop(input, ms);
	}
	rl_clear_history();
}

static void	free_loop(char *input, t_mini *ms)
{
	free (input);
	free_cmds_tab(ms->cmds, ms->elem_pars->nb_cmd);
	free_pipes(ms->pipes);
	free (ms->elem_pars);
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

static t_bool	space_input(char *input)
{
	while (ft_is_whitespace(*input))
		input ++;
	if (!*input)
		return (TRUE);
	else
		return (FALSE);
}
