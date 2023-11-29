/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:41:10 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/29 17:26:47 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*============================================================================*/

char **get_dtab_cmd(t_pars *cmd)
{
	char **res;
	size_t parslen;
	size_t i;

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

void exec_simple_cmd(t_pars *cmd, t_mini *ms, t_bool end)
{
	int i;

	i = 0;
	if (ft_strcmp(cmd->str, "exit"))
		ft_exit();
	while (ms->pipes->pid[i])
		i++;
	ms->res = 42;
	ms->pipes->pid[i] = fork();
	printf("i = %d\n", i);
	if (ms->pipes->pid[i] < 0)
		return (printf("fork error\n"), (void)0);
	pipe(ms->pipes->pipes);
	if (ms->pipes->pid[i] == 0)
	{
		exec_child(cmd, end, ms);
		return;
	}
	if (!end)
	{
		dup2(ms->pipes->pipes[0], STDIN_FILENO);
	}
	else
	{
		dup2(ms->pipes->saved_fd_in, STDIN_FILENO);
		if (cmd->first->and_op || cmd->first->or_op)
		{
			waitpid(ms->pipes->pid[i], &(ms->pipes->status), 0);
			if (WIFEXITED(ms->pipes->status))
				ms->res = WEXITSTATUS(ms->pipes->status);
		}
		else
			ft_waitpid(ms);
	}
	close(ms->pipes->pipes[1]);
	close(ms->pipes->pipes[0]);
}

t_bool select_syst_cmd(t_pars *cmd, t_env *env)
{
	char *path;
	char **tab_cmd;

	tab_cmd = NULL;
	path = get_cmd_path(cmd->str, env->env_elems);
	tab_cmd = get_dtab_cmd(cmd);
	if (!path)
		return (printf("%s - command not found\n", cmd->str), FAIL);
	execve(path, tab_cmd, env->env_cpy);
	return (free(tab_cmd), SUCCESS);
}

t_pipes *init_pipes(t_mini *ms)
{
	t_pipes *oui;
	int i;

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
