# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/23 16:19:15 by qbanet            #+#    #+#              #
#    Updated: 2023/11/20 12:21:09 by qbanet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

LIBFT = libft/libft.a
LIBFT_DIR = libft
LIBFT_INC = -I$(LIBFT_DIR)/includes
INC_DIR = includes
SRC_DIR = srcs
OBJ_DIR = obj

INCLUDES = -I$(INC_DIR) $(LIBFT_INC)

SRC_FILES = main.c \
			readline/readline_loop.c \
			parsing/parsing.c\
			parsing/make_clear_cmds.c \
			parsing/set_str_to_t_in.c \
			parsing/set_in_to_t_pars.c \
			parsing/utils_parsing.c \
			parsing/utils_parsing_1.c \
			exec/exec_cmds.c \
			utils/utils_t_in.c \
			utils/utils_t_pars.c \
			utils/utils_t_env_elem.c \
			utils/utils_env.c \
			utils/utils_print.c \
			utils/ft_nodelen.c \
			utils/utils_1.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Colors
RESET = \033[0m
GREEN = \033[32m
ORANGE_Q = \033[38;2;230;126;34m
GREEN_Q = \033[38;2;80;150;60m
YELLOW = \033[33m
RED = \033[31m
BLUE = \033[34m

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) -lreadline
	@echo "$(GREEN)Compilation successful!$(RESET)"
	@sleep 0
	@clear
	@echo "$(ORANGE_Q) ████▒░▒████▒░██▒░███▒░  █▒░██▒░ ██$(GREEN_Q)██▒░ ██▒░░▒██▒░██████▒░██▒░    ██▒░		$(RESET)"
	@echo "$(ORANGE_Q) ██▒██▒██▒██▒░██▒░█▒██▒░ █▒░██▒░█▒░$(GREEN_Q) ██▒░██▒░░▒██▒░██▒░    ██▒░    ██▒░		$(RESET)"
	@echo "$(ORANGE_Q) ██▒░███▒░██▒░██▒░█▒░██▒░█▒░██▒░  █$(GREEN_Q)█▒░  ████████▒░████▒░  ██▒░    ██▒░		$(RESET)"
	@echo "$(ORANGE_Q) ██▒░░█▒░ ██▒░██▒░█▒░ ██▒█▒░██▒░██▒$(GREEN_Q)░ █▒░██▒░░▒██▒░██▒░    ██▒░    ██▒░		$(RESET)"
	@echo "$(ORANGE_Q) ██▒░░░   ██▒░██▒░█▒░  ███▒░██▒░ ██$(GREEN_Q)██▒░ ██▒░░▒██▒░██████▒░██████▒░██████▒░	$(RESET)"
	@echo ""

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(BLUE)Compiling: $<$(RESET)"

$(LIBFT):
	@$(MAKE) -s -C $(LIBFT_DIR)

clean:
	@$(MAKE) -s -C $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)
	@echo "$(YELLOW)Cleaning object files...$(RESET)"

fclean:
	@$(MAKE) -s -C $(LIBFT_DIR) fclean
	@rm -rf $(OBJ_DIR)
	@echo "$(YELLOW)Cleaning object files...$(RESET)"
	@rm -f $(NAME)
	@echo "$(RED)Full clean completed!$(RESET)"

re: fclean all

.PHONY: all clean fclean re
