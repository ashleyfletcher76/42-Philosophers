# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/04 07:56:38 by asfletch          #+#    #+#              #
#    Updated: 2024/03/12 11:22:01 by asfletch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

COLOUR_DEFAULT = \033[0m
COLOUR_BLACK = \033[0;30m
COLOUR_RED = \033[0;31m
COLOUR_GREEN = \033[0;32m
COLOUR_YELLOW = \033[0;33m
COLOUR_BLUE = \033[0;34m
COLOUR_MAGENTA = \033[0;35m
COLOUR_CYAN = \033[0;36m
COLOUR_WHITE = \033[0;37m
COLOUR_BOLD = \033[1m
COLOUR_UNDERLINE = \033[4m
COLOUR_END = \033[0m

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -I./includes/ -g -pthread

# CFLAGS += -Wall -Wextra -Werror -I./include/ -g3 -fsanitize=address -fsanitize=undefined
# LDFLAGS += -fsanitize=address -fsanitize=undefined

OBJ_DIR = obj
OBJ = $(OBJ_DIR)/main.o \
	$(patsubst src/%.c,$(OBJ_DIR)/%.o,$(wildcard src/utils/*.c)) \
	$(patsubst src/%.c,$(OBJ_DIR)/%.o,$(wildcard src/main_logic/*.c)) \
	$(patsubst src/%.c,$(OBJ_DIR)/%.o,$(wildcard src/action/*.c)) \

NAME = philo

$(NAME) : $(OBJ_DIR) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ)  $(LDFLAGS) -o $(NAME)
	echo "$(COLOUR_RED)Philo compiled successfully!$(COLOUR_END)"

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)/utils
	mkdir -p $(OBJ_DIR)/main_logic
	mkdir -p $(OBJ_DIR)/action

$(OBJ_DIR)/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

clean:
	$(RM) -rf $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)
	echo "$(COLOUR_MAGENTA)$(COLOUR_UNDERLINE)Philo cleaned successfully!$(COLOUR_END)"

re: fclean all

.PHONY: all clean fclean re
