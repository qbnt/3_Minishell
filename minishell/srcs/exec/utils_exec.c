/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:41:10 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/28 16:15:26 by qbanet           ###   ########.fr       */
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

void	exec_simple_cmd(t_pars *cmd, t_mini *ms, t_bool end)
{
	int		i;

	i = 0;
	if (ft_strcmp(cmd->str, "exit"))
		ft_exit();
	while (ms->pipes->pid[i])
		i ++;
	ms->pipes->pid[i] = fork();
	ms->res = 42;
	if (ms->pipes->pid[i] < 0)
		return (printf("fork error\n"), (void) 0);
	if (ms->pipes->pid[i] == 0)
	{
		exec_child(cmd, end, ms);
		return ;
	}
	if (!end)
	{
		dup2(ms->pipes->pipes[0], STDIN_FILENO);
		close(ms->pipes->pipes[0]);
		close(ms->pipes->pipes[1]);
	}
	else
	{
		dup2(ms->pipes->saved_fd_in, STDIN_FILENO);
		close(ms->pipes->pipes[0]);
		close(ms->pipes->pipes[1]);
		ft_waitpid(ms);
	}
}

t_bool	select_syst_cmd(t_pars *cmd, t_env *env)
{
	char	*path;
	char	**tab_cmd;

	tab_cmd = NULL;
	path = get_cmd_path(cmd->str, env->env_elems);
	tab_cmd = get_dtab_cmd(cmd);
	if (!path)
		return (printf("%s - command not found\n", cmd->str), FAIL);
	execve(path, tab_cmd, env->env_cpy);
	return (free(tab_cmd), SUCCESS);
}

t_pipes	*init_pipes(t_mini *ms)
{
	t_pipes	*oui;

	oui = ft_calloc(1, sizeof(t_pipes));
	oui->nb_pipes = ms->elem_pars->tmp_pipes;
	oui->pid = ft_calloc(ms->elem_pars->nb_cmd, sizeof(int));
	oui->pipes = ft_calloc(2, sizeof(int));
	pipe(oui->pipes);
	oui->saved_fd_out = dup(STDOUT_FILENO);
	oui->saved_fd_in = dup(STDIN_FILENO);
	return (oui);
}
