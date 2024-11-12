# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/30 11:38:14 by asafrono          #+#    #+#              #
#    Updated: 2024/11/12 16:45:45 by asafrono         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror 
AR = ar rcs
RM = rm -f

SRCS = 	get_next_line.c get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

BONUS_SRCS = get_next_line_bonus.c get_next_line_utils_bonus.c

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

bonus: .bonus

.bonus:$(OBJS) $(BONUS_OBJS)
	$(AR) $(NAME) $(OBJS) $(BONUS_OBJS)
	touch .bonus

%.o: %.c get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_OBJS): %.o: %.c get_next_line_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)
	$(RM) .bonus

fclean: clean
	$(RM) $(NAME)
	
re: fclean all

.PHONY: all clean fclean re