/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 21:56:05 by qbanet            #+#    #+#             */
/*   Updated: 2023/12/08 17:25:45 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		*get_path(char **dir, char *cmd);
static char		*find_dir(char *dir, char *cmd);
static t_bool	not_path_need(char *cmd);
static char		*verif_cmd_np(char *cmd, t_mini **ms);

/*============================================================================*/

char	*get_cmd_path(char *cmd, t_env_elems *env, t_mini **ms)
{
	char	*val;
	char	**dir;
	char	*res;

	if (not_path_need(cmd))
		return (verif_cmd_np(cmd, ms));
	val = t_env_elems_find_value_of(env, "PATH");
	if (!val)
	{
		printf("No path in env\n");
		return (free(val), NULL);
	}
	dir = ft_split(val, ':');
	if (!dir)
		return (NULL);
	res = get_path(dir, cmd);
	free_dtab(dir);
	free (val);
	return (res);
}

static char	*verif_cmd_np(char *cmd, t_mini **ms)
{
	int	fd;

	fd = open(cmd, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("%s: No such file or directory\n", cmd);
		return ((*ms)->res = 127, close(fd), NULL);
	}
	if (access(cmd, X_OK))
	{
		ft_printf("%s: Permission denied\n", cmd);
		return ((*ms)->res = 127, close(fd), NULL);
	}
	close(fd);
	return (cmd);
}

static t_bool	not_path_need(char *cmd)
{
	t_bool	res;
	int		i;

	i = -1;
	res = 0;
	while (cmd[++i])
		if (cmd[i] == '.')
			res += 1;
	i = -1;
	while (cmd[++i])
		if (cmd[i] == '/')
			res += 1;
	if (res == 0)
		return (FALSE);
	else
		return (TRUE);
}

static char	*get_path(char **dir, char *cmd)
{
	int		i;
	char	*abs_path;
	char	*tmp;

	i = -1;
	abs_path = NULL;
	while (dir[++i] && abs_path == NULL)
		abs_path = find_dir(dir[i], cmd);
	if (abs_path)
	{
		tmp = ft_strjoin(abs_path, "/");
		abs_path = ft_strjoin(tmp, cmd);
		free (tmp);
	}
	return (abs_path);
}

static char	*find_dir(char *dir, char *cmd)
{
	DIR				*d;
	struct dirent	*dir_enter;

	d = opendir(dir);
	if (!d)
		return (closedir(d), NULL);
	dir_enter = readdir(d);
	while (dir_enter)
	{
		if (ft_strcmp(dir_enter->d_name, cmd) == TRUE)
		{
			closedir(d);
			return (dir);
		}
		dir_enter = readdir(d);
	}
	closedir(d);
	return (NULL);
}
