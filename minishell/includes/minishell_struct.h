/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:07:09 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/10 11:37:58 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_STRUCT_H
# define MINISHELL_STRUCT_H

typedef int	t_token;
typedef int	t_bool;

typedef struct s_pars
{
	char			c;
	int				id;
	struct s_pars	*next;
	struct s_pars	*prev;
	struct s_pars	*first;
}	t_pars;

typedef struct s_l_args
{
	char			*str;
	t_token			token;
	struct s_l_args	*next;
	struct s_l_args	*prev;
	struct s_l_args	*first;
}	t_l_args;

typedef struct s_mini
{
	t_l_args	args;
}	t_mini;

#endif