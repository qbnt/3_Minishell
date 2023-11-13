/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:07:09 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/13 11:28:25 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_STRUCT_H
# define MINISHELL_STRUCT_H

typedef int	t_token;
typedef int	t_bool;

typedef struct s_in{
	char			c;
	int				id;
	struct s_in		*next;
	struct s_in		*prev;
	struct s_in		*first;
}	t_in;

typedef struct s_elem_pars{
	int				nb_dcote;
	int				nb_pipe;
	int				nb_cmd;
}	t_elem_pars;

typedef struct s_pars{
	char			*str;
	t_token			token;
	struct s_pars	*next;
	struct s_pars	*prev;
	struct s_pars	*first;
}	t_pars;

typedef struct s_mini{
	t_pars		*args;
	t_elem_pars	elem_pars;
}	t_mini;

#endif
