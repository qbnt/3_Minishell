/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:07:09 by qbanet            #+#    #+#             */
/*   Updated: 2023/12/08 16:56:15 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_STRUCT_H
# define MINISHELL_STRUCT_H

# include <signal.h>
# include <dirent.h>
# include <stdio.h>

typedef int	t_token;
typedef int	t_bool;

typedef struct s_in
{
	char				c;
	int					id;
	int					group;
	struct s_in			*next;
	struct s_in			*prev;
	struct s_in			*first;
}	t_in;

typedef struct s_elem_pars
{
	int					nb_cmd;
	int					nb_pipe;
	int					tmp_pipes;
	int					nb_or_op;
	int					nb_and_op;
	int					nb_and_char;
	int					nb_scote;
	int					nb_dcote;
	int					nb_op_parenth;
	int					nb_cl_parenth;
	int					nb_redir;
	int					nb_dredir_in;
	int					nb_dredir_out;
	t_bool				error;
}	t_elem_pars;

typedef struct s_pipes
{
	int					pipes[2];
	pid_t				*pid;
	int					nb_pipes;
	int					saved_fd_out;
	int					saved_fd_in;
	int					status;
}	t_pipes;

typedef struct s_pars
{
	char				*str;
	int					group;
	t_token				token;
	t_bool				pipe_op;
	t_bool				and_op;
	t_bool				or_op;
	t_bool				cmd_ok;
	struct s_pars		*next;
	struct s_pars		*prev;
	struct s_pars		*first;
}	t_pars;

typedef struct s_dir
{
	t_pars				*dir_lst;
	DIR					*d;
	struct dirent		*dir;
	char				tmp[2048];
}	t_dir;

typedef struct s_env_elems
{
	char				*key;
	char				*value;
	unsigned int		key_len;
	unsigned int		value_len;
	struct s_env_elems	*next;
	struct s_env_elems	*prev;
	struct s_env_elems	*first;
}	t_env_elems;

typedef struct s_env
{
	char				**env_cpy;
	t_env_elems			*env_elems;
}	t_env;

typedef struct s_mini
{
	int					res;
	t_pipes				*pipes;
	t_pars				**cmds;
	t_elem_pars			*elem_pars;
	t_env				*env;
}	t_mini;

#endif
