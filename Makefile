# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: student <student@42barcelona.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/30 10:00:00 by student           #+#    #+#              #
#    Updated: 2025/01/30 10:00:00 by student          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cv

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I inc

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc

SRCS = main.c \
       utils.c \
       print.c \
       free.c

SRC_FILES = $(addprefix $(SRC_DIR)/, $(SRCS))
OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

HEADER = $(INC_DIR)/cv.h

# Colors
GREEN = \033[0;32m
BLUE = \033[0;34m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@echo "$(BLUE)Compilando $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) compilado con éxito!$(RESET)"
	@echo "$(GREEN)Ejecuta: ./$(NAME)$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)✗ Archivos objeto eliminados$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)✗ $(NAME) eliminado$(RESET)"

re: fclean all

run: all
	@echo "$(BLUE)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(RESET)"
	@echo "$(GREEN)          🚀 Ejecutando CV en C 🚀$(RESET)"
	@echo "$(BLUE)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(RESET)"
	@./$(NAME)

valgrind: all
	@echo "$(BLUE)Ejecutando Valgrind...$(RESET)"
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

.PHONY: all clean fclean re run valgrind
