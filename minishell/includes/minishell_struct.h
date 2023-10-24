/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:07:09 by qbanet            #+#    #+#             */
/*   Updated: 2023/10/24 10:29:19 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_STRUCT_H
# define MINISHELL_STRUCT_H

typedef int	t_token;
typedef int	t_bool;

typedef struct s_pars
{
	char			c;
	t_token			token;
	struct s_pars	*next;
	struct s_pars	*prev;
}	t_pars;

typedef struct s_l_args
{
	char			*content;
	t_token			token;
	struct s_l_args	*next;
	struct s_l_args	*prev;
}	t_l_args;

typedef struct s_mini
{
	t_l_args	args;
}	t_mini;

#endif