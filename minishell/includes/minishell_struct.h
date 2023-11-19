/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:07:09 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/19 12:07:22 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_STRUCT_H
# define MINISHELL_STRUCT_H

typedef int	t_token;
typedef int	t_bool;

typedef struct s_in{
	char				c;
	int					id;
	struct s_in			*next;
	struct s_in			*prev;
	struct s_in			*first;
}	t_in;

typedef struct s_elem_pars{
	int					nb_cmd;
	int					nb_pipe;
	int					nb_or_op;
	int					nb_and_op;
	int					nb_and_char;
	int					nb_scote;
	int					nb_dcote;
	int					nb_parenth;
	int					nb_redir;
	int					nb_dredir_in;
	int					nb_dredir_out;
	t_bool				error;
}	t_elem_pars;

typedef struct s_pars{
	char				*str;
	t_token				token;
	t_bool				pipe_op;
	t_bool				and_op;
	t_bool				or_op;
	struct s_pars		*next;
	struct s_pars		*prev;
	struct s_pars		*first;
}	t_pars;

typedef struct s_env_elems{
	char				*key;
	char				*value;
	struct s_env_elems	*next;
	struct s_env_elems	*prev;
	struct s_env_elems	*first;
}	t_env_elems;

typedef struct s_env{
	char				**env_cpy;
	t_env_elems			*env_elems;
}	t_env;

typedef struct s_mini{
	t_env				*env;
	t_pars				**cmds;
	t_elem_pars			*elem_pars;
}	t_mini;

#endif
