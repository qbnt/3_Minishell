# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/23 16:19:15 by qbanet            #+#    #+#              #
#    Updated: 2023/11/01 10:35:24 by qbanet           ###   ########.fr        #
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
			utils/utils_1.c \
			utils/utils_parsing.c \
			utils/utils_t_pars.c\
			utils/utils_t_l_args.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Colors
RESET = \033[0m
GREEN = \033[32m
YELLOW = \033[33m
RED = \033[31m
BLUE = \033[34m

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)Compilation successful!$(RESET)"
	@sleep 0
	@clear
	@echo "$(RED) ████▒░▒████▒░██▒░███▒░  █▒░██▒░   ██▒░░▒██▒░██████▒░██▒░    ██▒░"
	@echo " ██▒██▒██▒██▒░██▒░█▒██▒░ █▒░██▒░   ██▒░░▒██▒░██▒░    ██▒░    ██▒░"
	@echo " ██▒░███▒░██▒░██▒░█▒░██▒░█▒░██▒░ S ████████▒░████▒░  ██▒░    ██▒░"
	@echo " ██▒░░█▒░ ██▒░██▒░█▒░ ██▒█▒░██▒░   ██▒░░▒██▒░██▒░    ██▒░    ██▒░"
	@echo " ██▒░░░   ██▒░██▒░█▒░  ███▒░██▒░   ██▒░░▒██▒░██████▒░██████▒░██████▒░"
	@echo " ▓▓▒░░     ▓░▒▓▓▒░    ░▒▓▓▒░▓▒░     ▓▒░░▒▓▒░░▒▓▓▒░░░░░░▒▓▓▒░░░▒▓▓▒░"
	@echo " ▓▒░░       ░▒▓▒░     ░▒▓▒░         ▒░   ▒░  ░▒▓▒░   ░░▒▓▒░  ░░▒▓▒░"
	@echo " ▒░░          ▒░        ▒░          ░    ░    ░▒░     ░▒▒░    ░▒▒░"
	@echo " ░░           ░         ░                      ░       ░░      ░░"
	@echo " ░                                                      ░       ░ $(RESET)"
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
