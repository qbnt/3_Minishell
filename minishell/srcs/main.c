/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:12:59 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/22 17:28:39 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*============================================================================*/

int	main(int argc, char **argv, char **envp)
{
	t_mini		*ms;

	if (argc > 1)
		return (perror("need no args\n"), 1);
	argv += 0;
	ms = ft_calloc(sizeof(t_mini), 1);
	ms->env = ft_envcpy(envp);
	readline_loop(ms);
	return (free_all(ms), 0);
}

void	free_all(t_mini *ms)
{
	int	i;

	i = -1;
	if (ms->elem_pars != NULL)
		free (ms->elem_pars);
	if (ms->env)
	{
		t_env_elems_free(ms->env->env_elems);
		while (ms->env->env_cpy[++i])
			free (ms->env->env_cpy[i]);
		free(ms->env->env_cpy);
		free(ms->env);
	}
	free (ms);
	printf("All is free\n");
}
