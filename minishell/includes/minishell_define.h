/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_define.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:07:12 by qbanet            #+#    #+#             */
/*   Updated: 2023/12/05 15:42:01 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_DEFINE_H
# define MINISHELL_DEFINE_H

/*----------debug define----------*/

# define TEST1			printf("_______________TEST_1_____________\n")
# define TEST2			printf("_______________TEST_2_____________\n")

/*---------t_pars tokents---------*/

# define ERR			-1

# define CMD			10
# define ARGS			11
# define STR			12
# define REDIR			13
# define RE_IN			14
# define RE_OUT			15
# define ALIAS			16
# define OPP			17
# define LIT_STR		18
# define AND			19
# define OR				20
# define NO_TOKEN		99

/*---------arg define fnct---------*/

/*general*/
# define SUCCESS		0
# define FAIL			1

/*ft_print_t_in*/
# define ID				1
# define CHAR			2

# define MS_NAME		"Minishell > "

#endif