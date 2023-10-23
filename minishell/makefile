# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/23 16:19:15 by qbanet            #+#    #+#              #
#    Updated: 2023/10/23 16:30:58 by qbanet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Déclaration des variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror -lreadline -ltermcap -lm -lpthread
LDFLAGS = -Iincludes
SRC_DIR = srcs
OBJ_DIR = obj

# Liste de fichiers sources
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

# Compilation de l'exécutable minishell
all: minishell

minishell: $(OBJS)
	@echo "\033[32mLinking $@...\033[0m"
	@$(CC) -o $@ $^ $(LDFLAGS)
	@echo "\033[32mCompilation réussie.\033[0m"

# Compilation des fichiers objets
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "\033[33mCompiling $<...\033[0m"
	@$(CC) $(CFLAGS) $(LDFLAGS) -o $@ -c $<

$(OBJ_DIR):
	@echo "\033[34mCreating $(OBJ_DIR) directory...\033[0m"
	@mkdir -p $@

# Nettoyage des fichiers objets et de l'exécutable
clean:
	@echo "\033[31mCleaning...\033[0m"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "\033[31mFull Cleaning...\033[0m"
	@rm -f minishell

# Règle pour recompiler tout
re: fclean all

# Règles pour ne pas traiter les fichiers suivants
.PHONY: all clean fclean re
