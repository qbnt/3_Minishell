/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:07:07 by qbanet            #+#    #+#             */
/*   Updated: 2023/12/02 19:27:24 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*==================================Includes==================================*/

# include "minishell_define.h"
# include "minishell_struct.h"
# include "libft.h"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <dirent.h>

# include <readline/readline.h>
# include <readline/history.h>

# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>

# include <sys/stat.h>
# include <unistd.h>

# include <errno.h>
# include <dirent.h>
# include <string.h>

# include <termios.h>
# include <curses.h>
# include <term.h>

# include <sys/ioctl.h>

/*==================================Fonction==================================*/

void		free_all(t_mini *ms);

/*__________________________________Readline__________________________________*/

/*readline_loop.c*/
void		readline_loop(t_mini *ms);

/*__________________________________Parsing___________________________________*/

/*parsing.c*/
t_pars		**parsing(char *input, t_mini *ms);
t_elem_pars	*check_input(char *input);

/*make_clear_cmds.c*/
t_pars		**make_clear_cmds(t_elem_pars *elems, t_pars *pars, t_mini *ms);

/*ft_nodelen.c*/
size_t		ft_nodelen(t_in **in);

/*_________________________________Execution__________________________________*/

/*exec_cmds.c*/
int			exec_cmds(t_mini *ms);
void		exec_simple_cmd(t_pars *cmd, t_mini *ms, t_bool end);

/*exec_proces.c*/
void		exec_child(t_pars *cmd, t_bool end, t_mini *ms);
void		exec_parent(t_pars *cmd, t_bool end, t_mini *ms, int i);
void		ft_waitpid(t_mini *ms);

/*get_cmd_path.c*/
char		*get_cmd_path(char *cmd, t_env_elems *env);

/*utils_exec.c*/
char		**get_dtab_cmd(t_pars *cmd);
int			select_syst_cmd(t_pars *cmd, t_env *env);
t_pipes		*init_pipes(t_mini *ms);
void		free_pipes(t_pipes *pipes);

/*________________________________Redirections________________________________*/

/*redirections.c*/
void		redirections(t_mini *ms);

/*utils_redir.c*/
t_bool		redir_in_cmd(t_pars *cmd);

/*__________________________________Builtins__________________________________*/

/*builtins.c*/
int			ft_echo(t_pars *cmds);
int			ft_pwd(void);
void		ft_exit(void);
int			ft_env(t_env *env);
int			ft_cd(t_pars *cmds, t_env *env);
int			ft_export(t_pars *cmds, t_env *env);
void		ft_tri(t_env *env);
int			ft_envlen(t_env *env);
int			ft_strcmp_ex(char const *s1, char const *s2);

/*__________________________________Signals___________________________________*/

/*___________________________________Utils____________________________________*/

/*utils_parsing.c*/
t_in		*set_str_to_t_in(char *str);
t_pars		*set_in_to_t_pars(t_in *in);
void		pars_is_pipe(char **input, t_elem_pars **oui);
void		pars_is_and_op(char **input, t_elem_pars **oui);
void		pars_is_redir(char **input, t_elem_pars **oui);

/*utils_parsing_2.c*/
t_bool		empty_parenth(char *input);
void		select_opp(t_pars	*pars, t_pars **cmd);
size_t		count_cote(char *str, t_token token);
char		*clean_dol(char *str, t_mini *ms, t_token token);

/*utils_t_in.c*/
t_in		*t_in_first(t_in *first, char c, int group);
t_in		*t_in_add_back(t_in *in, char c, int group);
void		free_t_in(t_in *in);

/*utils_t_pars.c*/
t_pars		*t_pars_first(t_in **in);
void		t_pars_add_next(t_in **in, t_pars *full_cmd);
int			t_pars_pick_token(t_pars *arg);
void		free_t_pars(t_pars *pars);

/*utils_t_pars_2.c*/
void		t_pars_remove_node(t_pars **node);
void		t_pars_switch_node(t_pars **old_node, t_pars **new_list);
void		verif_wc(t_pars **cmd);

/*utils_t_pars_3.c*/
t_pars		*dir_lst_create(t_pars *cmd, t_bool start);
void		dir_lst_add(char *str, t_pars *dir_lst);
t_bool		star_ok(char *name, char *star);

/*utils_env.c*/
t_env		*ft_envcpy(char **system_env);

/*utils_t_env_elem.c*/
t_env_elems	*t_env_elems_first(char *key, char *value);
void		t_env_elems_next(t_env_elems *env_elems, char *key, char *value);
char		*t_env_elems_find_value_of(t_env_elems *env_elems, char *key);
void		t_env_elems_free(t_env_elems *first);

/*utils_t_env_elem_2.c*/
char		*ft_cpy_dol(char *dol_str);
size_t		ft_dol_len_in_str(char *str, t_mini *ms);

/*utils_1.c*/
t_bool		ft_is_whitespace(char c);
t_bool		ft_is_opp(char c);
t_bool		ft_strcmp(const char *s1, const char *s2);
size_t		ft_tablen(char **dtab);
void		free_cmds_tab(t_pars **cmds, int nb_cmds);

/*utils_2.c*/
void		free_dtab(char **str);
size_t		t_parslen(t_pars *cmd);
int			switch_res(char **str, t_mini *ms, int total_len, char *res_str);
int			ft_strnrcmp(char const *s1, char const *s2, size_t n);

/*utils_print.c*/
void		ft_print_t_in(t_in **oui, int arg);
void		ft_print_t_pars(t_pars *oui);
void		ft_print_dtab(char **dtab);
void		ft_print_t_env_elems(t_env_elems *elems);

#endif
