# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djmekki < djmekki@student.42heilbronn.d    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 22:08:48 by djmekki           #+#    #+#              #
#    Updated: 2023/02/01 00:10:41 by djmekki          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BONUS_NAME = checker
CC = gcc
FLAGS = -Wall -Wextra -Werror
INCLUDES = -I./include

SRCS = ./src/chck_stack.c \
		./src/chck_utils.c \
		./src/functions_utils.c \
		./src/functions.c \
		./src/index.c \
		./src/initialize.c \
		./src/median_sort.c \
		./src/push_swap.c \
		./src/sort_small_DESC.c \
		./src/sort_small.c \
		./src/utils.c
	
BONUS_SRCS = ./src/chck_utils.c \
			./src/chck_stack.c \
			./src/functions_utils.c \
			./src/functions.c \
			./src/index.c \
			./src/initialize.c \
			./src/median_sort.c \
			./src/checker.c \
			./src/sort_small_DESC.c \
			./src/sort_small.c \
			./src/utils.c

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

LIBFTPRINTF = make -C ./ft_printf

$(NAME) :	$(OBJS)
			$(LIBFTPRINTF)
			$(CC) $(FLAGS) $(INCLUDES) $(SRCS) ./ft_printf/libftprintf.a -o $(NAME)

$(BONUS_NAME): $(BONUS_OBJS)
			$(LIBFTPRINTF)
			$(CC) $(FLAGS) $(INCLUDES) $(BONUS_SRCS) ./ft_printf/libftprintf.a -o $(BONUS_NAME)
			
all : $(NAME)

bonus : $(BONUS_NAME)

clean :
	make clean -C ./ft_printf/
	rm -f $(OBJS)
	rm -f $(BONUS_OBJS)

fclean : clean
	make fclean -C ./ft_printf/
	rm -f $(NAME)
	rm -f $(BONUS_NAME)

re : fclean all
	make re -C ./ft_printf/

.PHONY:
	all bonus clean fclean re