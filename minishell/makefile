# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/23 16:19:15 by qbanet            #+#    #+#              #
#    Updated: 2023/10/25 14:37:23 by qbanet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -I includes -I $(LIBFT_DIR)/includes

SRC_DIR = srcs
SRC_FILES = main.c\
			utils/utils_1.c\
			utils/utils_parsing.c\
			utils/utils_t_pars.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ_DIR = obj
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJ = $(addprefix $(OBJ_DIR)/, $(OBJ_FILES))

# Couleurs
GREEN = \033[0;32m
YELLOW = \033[0;33m
RESET = \033[0m

# Emojis
CHECK = ✔️
ROCKET = 🚀︎

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)$(ROCKET) Compilation terminée avec succès ! $(ROCKET)$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(YELLOW)$(CHECK) $(notdir $@) compilé$(RESET)"

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)
	@echo "$(GREEN)$(CHECK) Nettoyage des fichiers objets terminé$(RESET)"

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)
	@echo "$(GREEN)$(CHECK) Nettoyage complet terminé$(RESET)"

save: fclean
	git add .
	git commit -m "make save"
	git push

re: fclean all

.PHONY: all clean fclean re