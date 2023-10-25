/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:51:00 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/10 15:15:44 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/********************************** INCLUDES **********************************/

# include<stdlib.h>
# include<unistd.h>
# include<stdarg.h>
# include<signal.h>
# include <fcntl.h>

/********************************** STRUCTS ***********************************/

typedef struct s_gnl
{
	int				fd;
	char			*text;
	char			*tempo;
	struct s_gnl	*next;
}	t_gnl;

typedef struct s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*********************************** TYPEDEF **********************************/

typedef unsigned long long	t_ull;
typedef long long			t_ll;
typedef unsigned long		t_ul;
typedef long				t_l;
typedef int					t_bool;

/*********************************** DEFINES **********************************/

/*********** BUFFER ***********/

# define BUFFER_SIZE 420

/*********** BOOL ***********/

# define TRUE 1
# define FALSE 0

/*********** COLORS ***********/

# define C_NOR "\x1b[m"

# define C_GRA "\x1b[30m"
# define C_RED "\x1b[38;5;196m"
# define C_RED_BOLD "\x1b[1m\x1b[38;5;196m"
# define C_GRE "\x1b[38;5;151m"
# define C_BLU "\x1b[34m"
# define C_MAG "\x1b[35m"
# define C_CYA "\x1b[36m"
# define C_WHI "\x1b[37m"
# define C_YEL "\x1b[38;5;222m"
# define C_PIN "\x1b[38;5;207m"

# define B_GRA "\x1b[40m"
# define B_RED "\x1b[41m"
# define B_GRE "\x1b[42m"
# define B_YEL "\x1b[43m"
# define B_BLU "\x1b[44m"
# define B_MAG "\x1b[45m"
# define B_CYA "\x1b[46m"
# define B_WHI "\x1b[47m"

# define S_BOLD "\x1b[1m"
# define S_UNDER "\x1b[4m"
# define S_REV "\x1b[7m"

/*********** MIN & MAX ***********/

# define _CHAR_MIN -127
# define _CHAR_MAX 127
# define _UCHAR_MAX 255

# define _SHORT_MIN -32768
# define _SHORT_MAX 32767
# define _USHORT_MAX 65535

# define _INT_MIN -2147483648
# define _INT_MAX 2147483647
# define _UINT_MAX 4294967295

# define _LONG_MIN -9223372036854775808
# define _LONG_MAX 9223372036854775807
# define _ULONG_MAX 18446744073709551615

# define _LLONG_MIN -9223372036854775808
# define _LLONG_MAX 9223372036854775807
# define _ULLONG_MAX 18446744073709551615

/********************************* FONCTIONS **********************************/

/*********** FT_IS ***********/

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);

/*********** FT _PRINTF ***********/

int			ft_printf(const char *str, ...);
int			ft_printstr(char *str);
int			ft_printnbr(int n);
int			ft_printpourcent(void);
int			ft_printunsigned(unsigned int n);
int			ft_printadr(unsigned long long adr);
int			ft_printhexa(int n, const char format);

/*********** FT_MEM ***********/

void		*ft_memset(void *s, int c, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
void		ft_bzero(void *s, size_t n);
int			ft_memcmp(const void *ptr1, const void *ptr2, size_t num);
int			ft_free_tab(void ***tab, int nb_line, int nb_colon);

/*********** FT_STR ***********/

int			ft_toupper(int c);
int			ft_tolower(int c);
int			ft_isspace(int c);
size_t		ft_strcpy(char *dest, const char *src);
char		*ft_strncpy(char *dest, char *src, unsigned int n);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
size_t		ft_strlcat(char *dest, const char *str, size_t size);
t_bool		ft_verif_ext(const char *s, const char *ext);

size_t		ft_strlen(const char *s);
char		*ft_strchr(const char *str, int c);
char		*ft_strrchr(const char *str, int c);

int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *big, const char *little, size_t len);
char		*ft_strncpy(char *dest, char *src, unsigned int n);

int			ft_atoi(const char *str);
int			ft_atoi_base(char *str, char *base);
char		*ft_strdup(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
int			ft_count_wrd_sep(char const *s, char c);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
char		*ft_convert_base(t_ll num, const char *base_set, int base);
char		*ft_convert_base_unsign(t_ull num, const char *base_set, int base);

/*********** FT_PUT ***********/

void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(long long n, int fd);

/*********** FT_LST ***********/

t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *n);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *n);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void*(*f)(void *), void (*del)(void *));

/*********** GNL ***********/

char		*ft_strdup_gnl(char *str, size_t c);
size_t		ft_strlen_gnl(char *s);
char		*ft_check_gnl(char *str, int c);
char		*ft_strjoin_gnl(char *s1, char *s2);
char		*get_next_line(int fd);
int			ft_gnl(int fd, char **line, int n);
int			ft_free_gnl(t_gnl **lst);
void		ft_list_add_last(t_gnl **save, t_gnl *elem);
t_gnl		*ft_create_list(int fd);

/*********** MATH ***********/

int			ft_max(int *tab, unsigned int len);
int			ft_min(int *tab, unsigned int len);
long double	ft_pow(long double nb, long double p);

#endif
