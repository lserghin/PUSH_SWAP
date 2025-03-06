# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/05 09:08:50 by lserghin          #+#    #+#              #
#    Updated: 2025/03/05 23:26:10 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker

CC = cc
CFLAGS = -Wall -Werror -Wextra

INCLUDES = -Iinclude
INCLUDES_BONUS = -Iinclude_bonus

LDFLAGS = -Llibft -lft

SRCS_DIR = source
OBJS_DIR = object

SRCS_DIR_BONUS = source_bonus
OBJS_DIR_BONUS = object_bonus

SRC_FILES = main.c check_inputs.c \
			ops_swap.c ops_push.c ops_rotate.c ops_reverse_rotate.c \
			get_functions.c push_swap_utils.c push_swap.c

SRC_FILES_BONUS = main_bonus.c check_inputs1_bonus.c check_inputs2_bonus.c \
			ops_swap_bonus.c ops_push_bonus.c ops_rotate_bonus.c ops_reverse_rotate_bonus.c \

SRCS = $(addprefix $(SRCS_DIR)/, $(SRC_FILES))
OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

SRCS_BONUS = $(addprefix $(SRCS_DIR_BONUS)/, $(SRC_FILES_BONUS))
OBJS_BONUS = $(SRCS_BONUS:$(SRCS_DIR_BONUS)/%.c=$(OBJS_DIR_BONUS)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)
	@echo "Project successfully built!"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	@make -C libft
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LDFLAGS) -o $(NAME_BONUS)
	@echo "Bonus project successfully built!"

$(OBJS_DIR_BONUS)/%.o: $(SRCS_DIR_BONUS)/%.c
	@mkdir -p $(OBJS_DIR_BONUS)
	@$(CC) $(CFLAGS) $(INCLUDES_BONUS) -c $< -o $@

clean:
	@rm -rf $(OBJS_DIR) $(OBJS_DIR_BONUS)
	@make -C libft clean
	@echo "Object files removed."

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@make -C libft fclean
	@echo "Executable and libraries removed."

re: fclean all

.PHONY: all clean fclean re bonus