# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/04 07:56:38 by asfletch          #+#    #+#              #
#    Updated: 2024/03/15 10:18:44 by asfletch         ###   ########.fr        #
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
SRCS = philo.c utils/print_and_exit.c utils/cleaner.c utils/check_args.c \
	utils/atoi_isdigit.c main_logic/start_monitor.c main_logic/routine.c \
	action/init.c action/forks_and_eat.c action/action_utils.c \

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

NAME = philo

$(NAME) : $(OBJ_DIR) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
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
