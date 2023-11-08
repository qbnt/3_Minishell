/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_define.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:07:12 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/07 11:17:51 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_DEFINE_H
# define MINISHELL_DEFINE_H

/*----------debug define----------*/

# define TEST1			printf("_______________TEST_1_____________\n")
# define TEST2			printf("_______________TEST_2_____________\n")

/*---------t_pars tokents---------*/

# define ERR			-1
# define LTR			0
# define PIPE			1
# define SQUOTE			2
# define DQUOTE			3
# define SUP			4
# define INF			5
# define DOL			6
# define NO_TOKEN		99

/*---------t_l_args tokents---------*/

# define CMD			10
# define ARGS			11
# define STR			12
# define REDIR			13
# define RE_IN			14
# define RE_OUT			15
# define ALIAS			16
# define OPP			17


#endif