# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/02 12:04:16 by qbanet            #+#    #+#              #
#    Updated: 2023/10/31 11:51:52 by qbanet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

AR = ar
ARFLAGS = -crs

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

RM = rm
RMFLAG = -rf

INCLUDES = -I./includes
SRC_DIR = src
OBJ_DIR = obj

SRCS = 	ft_atoi.c ft_itoa.c ft_memcmp.c ft_putnbr_fd.c ft_strncmp.c\
		ft_bzero.c ft_lstadd_back.c ft_memcpy.c ft_putstr_fd.c ft_strncpy.c\
		ft_calloc.c ft_lstadd_front.c ft_memmove.c ft_split.c ft_strnstr.c\
		ft_convert_base.c ft_lstclear.c ft_memset.c ft_strchr.c ft_strrchr.c\
		ft_count_wrd_sep.c ft_lstiter.c ft_printf.c ft_strdup.c ft_substr.c\
		ft_convert_base_unsign.c ft_lstdelone.c ft_pow.c ft_strcpy.c\
		ft_strtrim.c ft_gnl.c ft_lstlast.c ft_printf_utils_adr.c ft_striteri.c\
		ft_tolower.c ft_isalnum.c ft_lstmap.c ft_printf_utils.c ft_strjoin.c\
		ft_toupper.c ft_isalpha.c ft_lstnew.c ft_printf_utils_hexa.c\
		ft_strlcat.c get_next_line.c ft_isascii.c ft_lstsize.c\
		ft_printf_utils_unsign.c ft_strlcpy.c get_next_line_utils.c\
		ft_isdigit.c ft_max.c ft_putchar_fd.c ft_strlen.c ft_isprint.c\
		ft_memchr.c ft_putendl_fd.c ft_strmapi.c ft_gnl_u.c ft_atoi_base.c\
		ft_isspace.c ft_verif_ext.c ft_min.c\

SRC = $(addprefix $(SRC_DIR)/,$(SRCS))
OBJ = $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

# Colors
GREEN = \033[0;32m
YELLOW = \033[0;33m
RESET = \033[0m

all : $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME) : $(OBJ)
	@$(AR) $(ARFLAGS) $@ $^
	@echo -e "$(GREEN)libft.a created!$(RESET)"

clean :
	@$(RM) $(RMFLAG) $(OBJ_DIR)
	@echo -e "$(YELLOW)Object files removed!$(RESET)"

fclean : clean
	@$(RM) $(RMFLAG) $(NAME)
	@echo -e "$(YELLOW)libft.a removed!$(RESET)"

re : fclean all

.PHONY: all clean fclean re
