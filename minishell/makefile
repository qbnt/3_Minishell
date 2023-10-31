# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/23 16:19:15 by qbanet            #+#    #+#              #
#    Updated: 2023/10/31 11:54:49 by qbanet           ###   ########.fr        #
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
	@echo -e "$(GREEN)Compilation successful!$(RESET)"
	@echo -e ""
	@echo -e "$(RED) ████▒░▒████▒░██▒░███▒░  █▒░██▒░   ██▒░░▒██▒░██████▒░██▒░    ██▒░"
	@echo -e " ██▒██▒██▒██▒░██▒░█▒██▒░ █▒░██▒░   ██▒░░▒██▒░██▒░    ██▒░    ██▒░"
	@echo -e " ██▒░███▒░██▒░██▒░█▒░██▒░█▒░██▒░ S ████████▒░████▒░  ██▒░    ██▒░"
	@echo -e " ██▒░░█▒░ ██▒░██▒░█▒░ ██▒█▒░██▒░   ██▒░░▒██▒░██▒░    ██▒░    ██▒░"
	@echo -e " ██▒░░░   ██▒░██▒░█▒░  ███▒░██▒░   ██▒░░▒██▒░██████▒░██████▒░██████▒░"
	@echo -e " ▓▓▒░░     ▓░▒▓▓▒░    ░▒▓▓▒░▓▒░     ▓▒░░▒▓▒░░▒▓▓▒░░░░░░▒▓▓▒░░░▒▓▓▒░"
	@echo -e " ▓▒░░       ░▒▓▒░     ░▒▓▒░         ▒░   ▒░  ░▒▓▒░   ░░▒▓▒░  ░░▒▓▒░"
	@echo -e " ▒░░          ▒░        ▒░          ░    ░    ░▒░     ░▒▒░    ░▒▒░"
	@echo -e " ░░           ░         ░                      ░       ░░      ░░"
	@echo -e " ░                                                      ░       ░ $(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo -e "$(BLUE)Compiling: $<$(RESET)"

$(LIBFT):
	@$(MAKE) -s -C $(LIBFT_DIR)

clean:
	@$(MAKE) -s -C $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)
	@echo -e "$(YELLOW)Cleaning object files...$(RESET)"

fclean: clean
	@$(MAKE) -s -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)
	@echo -e "$(RED)Full clean completed!$(RESET)"

re: fclean all

.PHONY: all clean fclean re
