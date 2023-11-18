/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:12:59 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/18 21:00:50 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		free_all(t_mini *ms);

/*============================================================================*/

int	main(int argc, char **argv, char **envp)
{
	t_mini		*ms;

	if (argc > 1)
		return (perror("too much args\n"), 1);
	argv += 0;
	ms = malloc(sizeof(t_mini));
	ms->env = ft_envcpy(envp);
	readline_loop(ms);
	return (free_all(ms), 0);
}

static void	free_all(t_mini *ms)
{
	int	i;

	i = -1;
	if (ms->cmds)
	{
		while (++i < ms->elem_pars->nb_cmd)
			free_t_pars(ms->cmds[i]);
		free (ms->cmds);
	}
	if (ms->elem_pars)
		free (ms->elem_pars);
	free (ms);
}
