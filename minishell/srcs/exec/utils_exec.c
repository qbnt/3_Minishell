/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:41:10 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/24 20:52:16 by qbanet           ###   ########.fr       */
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

t_bool	exec_simple_cmd(t_pars *cmd, t_env *env)
{
	t_bool	res;

	res = 0;
	if (ft_strcmp(cmd->str, "echo"))
		res = ft_echo(cmd);
	else if (ft_strcmp(cmd->str, "exit"))
		ft_exit();
	else if (ft_strcmp(cmd->str, "pwd"))
		res = ft_pwd();
	else if (ft_strcmp(cmd->str, "env"))
		ft_env(env);
	else if (ft_strcmp(cmd->str, "cd"))
		ft_env(env);
	else
		res = select_syst_cmd(cmd, env);
	return (res);
}

t_bool	select_syst_cmd(t_pars *cmd, t_env *env)
{
	char	*path;
	char	**tab_cmd;
	pid_t	pid;

	tab_cmd = NULL;
	pid = fork();
	if (pid < 0)
		return (printf("fork error\n"), FAIL);
	if (pid == 0)
	{
		path = get_cmd_path(cmd->str, env->env_elems);
		tab_cmd = get_dtab_cmd(cmd);
		if (!path)
			return (printf("%s not found\n", cmd->str), FAIL);
		execve(path, tab_cmd, env->env_cpy);
		return (free (tab_cmd), SUCCESS);
	}
	waitpid(pid, NULL, 0);
	return (SUCCESS);
}
