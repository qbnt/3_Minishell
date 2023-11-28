/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 21:56:05 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/28 14:33:20 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_path(char **dir, char *cmd);
static char	*find_dir(char *dir, char *cmd);

/*============================================================================*/

char	*get_cmd_path(char *cmd, t_env_elems *env)
{
	char	*val;
	char	**dir;
	char	*res;

	val = t_env_elems_find_value_of(env, "PATH");
	if (!val)
	{
		printf("No path in env\n");
		return (NULL);
	}
	dir = ft_split(val, ':');
	if (!dir)
		return (NULL);
	res = get_path(dir, cmd);
	free_dtab(dir);
	return (res);
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
