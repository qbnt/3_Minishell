/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:41:10 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/23 15:04:17 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*============================================================================*/

char	**get_dtab_cmd(t_pars *cmd)
{
	char	**res;
	size_t	parslen;
	size_t	i;

	parslen = t_parslen(cmd);
	res = ft_calloc(parslen + 1, sizeof(char *));
	i = 0;
	while (i < parslen)
	{
		res[i] = ft_strdup(cmd->str);
		cmd = cmd->next;
		i ++;
	}
	return (res);
}

t_bool	select_syst_cmd(t_pars *cmd, t_env *env)
{
	char	*path;
	char	**tab_cmd;

	path = get_cmd_path(cmd->str, env->env_elems);
	tab_cmd = get_dtab_cmd(cmd);
	if (!path)
		return (printf("%s not found\n", cmd->str), FAIL);
	exec_syst_cmd(path, tab_cmd, env->env_cpy);
	return (free (tab_cmd), SUCCESS);
}

t_bool	exec_syst_cmd(char *path, char **tab_cmd, char **tab_env)
{
	int	pid;

	pid = fork();
	if (pid == 0)
		execve(path, tab_cmd, tab_env);
	else if (pid == -1)
		return (printf("error during forking\n"), FAIL);
	else
		waitpid(pid, NULL, 0);
	return (SUCCESS);
}
