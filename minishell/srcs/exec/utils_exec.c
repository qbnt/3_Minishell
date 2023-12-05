/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:41:10 by qbanet            #+#    #+#             */
/*   Updated: 2023/12/05 17:45:03 by qbanet           ###   ########.fr       */
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
		i++;
	}
	return (res);
}

void	exec_simple_cmd(t_pars *cmd, t_mini *ms, t_bool end)
{
	int	i;

	i = 0;
	while (ms->pipes->pid[i])
		i++;
	ms->res = 42;
	pipe(ms->pipes->pipes);
	if (is_builtin(cmd->str) == TRUE)
		return (make_builtin(cmd, ms, end));
	ms->pipes->pid[i] = fork();
	if (ms->pipes->pid[i] < 0)
		return (printf("fork error\n"), (void)0);
	if (ms->pipes->pid[i] == 0)
	{
		exec_child(cmd, end, ms);
		return ;
	}
	exec_parent(cmd, end, ms, i);
	close(ms->pipes->pipes[1]);
	close(ms->pipes->pipes[0]);
}

t_bool	select_syst_cmd(t_pars *cmd, t_env *env)
{
	char	*path;
	char	**tab_cmd;

	tab_cmd = NULL;
	path = get_cmd_path(cmd->str, env->env_elems);
	if (!path)
		return (printf("%s - command not found\n", cmd->str), FAIL);
	tab_cmd = get_dtab_cmd(cmd);
	execve(path, tab_cmd, env->env_cpy);
	return (free(tab_cmd), SUCCESS);
}

t_pipes	*init_pipes(t_mini *ms)
{
	t_pipes	*oui;
	int		i;

	oui = ft_calloc(1, sizeof(t_pipes));
	oui->nb_pipes = ms->elem_pars->tmp_pipes;
	oui->pid = malloc((ms->elem_pars->nb_cmd + 1) * sizeof(pid_t));
	i = 0;
	while (i < ms->elem_pars->nb_cmd + 1)
	{
		oui->pid[i] = 0;
		i++;
	}
	oui->saved_fd_out = dup(STDOUT_FILENO);
	oui->saved_fd_in = dup(STDIN_FILENO);
	return (oui);
}

void	free_pipes(t_pipes *pipes)
{
	free(pipes->pid);
	free(pipes);
}
