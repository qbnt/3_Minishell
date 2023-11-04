/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:07:09 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/04 14:40:59 by qbanet           ###   ########.fr       */
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
}	t_pars;

typedef struct s_l_args
{
	char			*str;
	t_token			token;
	struct s_l_args	*next;
	struct s_l_args	*prev;
}	t_l_args;

typedef struct s_mini
{
	char		**splited_in;
	t_l_args	args;
}	t_mini;

#endif