/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:07:07 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/13 15:35:23 by qbanet           ###   ########.fr       */
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
t_in		*set_str_to_t_in(char *str);
t_pars		*set_in_to_t_pars(t_in *in);

/*utils_t_in.c*/
t_in		*t_in_first(t_in *first, char c);
t_in		*t_in_add_back(t_in *in, char c);
void		free_t_in(t_in *in);

/*utils_t_pars.c*/
t_pars		*t_pars_first(t_in **in);
void		t_pars_add_next(t_in **in, t_pars *full_cmd);
int			t_pars_pick_token(t_pars *arg);

/*utils_1.c*/
t_bool		ft_is_whitespace(char c);
size_t		ft_nodelen(t_in **in);

/*utils_print.c*/
void		ft_print_t_in(t_in **oui, int arg);
void		ft_print_t_pars(t_pars **oui);

#endif
