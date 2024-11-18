# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/30 11:38:14 by asafrono          #+#    #+#              #
#    Updated: 2024/11/18 15:59:12 by asafrono         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line
CC = cc
CFLAGS = -Wall -Wextra -Werror 
AR = ar rcs
RM = rm -rf

SRCS = 	get_next_line.c get_next_line_utils.c
BONUS_SRCS = get_next_line_bonus.c get_next_line_utils_bonus.c

OBJ_DIR = obj
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)
BONUS_OBJS = $(BONUS_SRCS:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

bonus: .bonus

.bonus:$(OBJS) $(BONUS_OBJS)
	$(AR) $(NAME) $(OBJS) $(BONUS_OBJS)
	touch .bonus

$(OBJ_DIR)/%.o: %.c get_next_line.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: %.c get_next_line_bonus.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)
	$(RM) .bonus
	$(RM) $(OBJ_DIR)

run: $(NAME)
	$(CC) $(CFLAGS) -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o gnl
	./gnl test.txt

fclean: clean
	$(RM) $(NAME)
	
re: fclean all

.PHONY: all clean fclean re run