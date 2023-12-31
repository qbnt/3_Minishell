/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:12:59 by qbanet            #+#    #+#             */
/*   Updated: 2023/12/06 20:24:25 by qbanet           ###   ########.fr       */
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
	signaux(ms);
	readline_loop(ms);
	return (free_all(ms), 0);
}

void	free_all(t_mini *ms)
{
	int	i;

	if (ms->env)
	{
		i = -1;
		t_env_elems_free(ms->env->env_elems);
		while (ms->env->env_cpy[++i])
			free (ms->env->env_cpy[i]);
		free(ms->env->env_cpy);
		free(ms->env);
	}
	free (ms);
}
