# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rvan-duy <rvan-duy@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/06/04 15:34:09 by rvan-duy      #+#    #+#                  #
#    Updated: 2021/07/22 10:38:48 by rvan-duy      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		= pipex
NAME_BONUS	= pipex_bonus
CC			= gcc
FLAGS		= -Wall -Wextra -Werror -g -fsanitize=address
HEADER		= -I include
HEADER_BONUS= -I include/bonus

SRC			= main.c \
				read_and_error_check_command.c \
				handle_processes.c \
				find_absolute_path_to_command.c \
				execute_command.c \
				utilities_1.c \
				utilities_2.c

SRC_BONUS	= main_bonus.c \
				read_and_error_check_command_bonus.c \
				handle_processes_bonus.c \
				find_absolute_path_to_command_bonus.c \
				execute_command_bonus.c \
				utilities_1_bonus.c \
				utilities_2_bonus.c

LIBFT	= libft/libft.a

OBJ_DIR 		= obj
OBJ_DIR_BONUS	= obj/bonus

NOCOLOR	= \033[0m
COLOR	= \033[32m

SRCS 		= $(addprefix src/, $(SRC))
SRCS_BONUS	= $(addprefix src/bonus/, $(SRC_BONUS))
OBJS		= $(SRCS:src/%.c=obj/%.o)
OBJS_BONUS	= $(SRCS_BONUS:src/%.c=obj/%.o)

all: $(NAME)

bonus: $(NAME_BONUS)

obj/%.o: src/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) $(HEADER) -c $< -o $@

obj/bonus/%.o: src/bonus/%.c
	@mkdir -p $(OBJ_DIR_BONUS)
	@$(CC) $(FLAGS) $(HEADER_BONUS) -c $< -o $@

$(NAME): $(OBJS)
	@make -C libft
	@$(CC) $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(COLOR)Creating object files and the executable. ($(NAME))$(NOCOLOR)"

$(NAME_BONUS): $(OBJS_BONUS)
	@make -C libft
	@$(CC) $(FLAGS) $(OBJS_BONUS) $(LIBFT) -o $(NAME_BONUS)
	@echo "$(COLOR)Creating bonus object files and the executable. ($(NAME_BONUS))$(NOCOLOR)"

clean:
	@/bin/rm -f $(OBJ)
	@/bin/rm -f .DS_Store
	@/bin/rm -f a.out
	@echo "$(COLOR)Removing object files.$(NOCOLOR)"

fclean: clean
	@/bin/rm -f $(NAME) $(NAME_BONUS)
	@/bin/rm -rf $(OBJ_DIR)
	@echo "$(COLOR)Removing executable and object directories.$(NOCOLOR)"

re: fclean all

.PHONY:	all clean fclean re