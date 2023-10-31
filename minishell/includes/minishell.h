/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:07:07 by qbanet            #+#    #+#             */
/*   Updated: 2023/10/31 11:25:40 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*----------------------------------Includes----------------------------------*/

# include "minishell_define.h"
# include "minishell_struct.h"
# include "libft.h"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# include <readline/readline.h>
# include <readline/history.h>

# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>

# include <sys/stat.h>
# include <unistd.h>

# include <errno.h>
# include <string.h>

# include <termios.h>
# include <curses.h>
# include <term.h>

# include <sys/ioctl.h>

/*----------------------------------Fonction----------------------------------*/

/********parsing********/

/********builtins********/

/********signals********/

/********utils********/

/*utils_parsing.c*/
t_pars		*set_str_to_t_pars(char *str);
t_l_args	*set_pars_to_l_args(t_pars *pars);

/*utils_t_pars.c*/
t_pars		*t_pars_first(t_pars *first, char c);
t_pars		*t_pars_add_back(t_pars *pars, char c);
void		free_t_pars_prev(t_pars **pars);

/*utils_t_l_args.c*/
void		t_l_args_first(t_l_args *first);
void		t_l_args_add_next(t_pars *pars, t_l_args *full_cmd);

/*utils_1.c*/
t_bool		ft_is_whitespace(char c);
t_bool		ft_is_alpha(char c);
size_t		ft_ltrlen(t_pars **oui);
void		ft_print_t_pars(t_pars **oui);
void		ft_print_t_l_args(t_l_args **oui);

#endif