# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djmekki < djmekki@student.42heilbronn.d    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/16 09:49:31 by djmekki           #+#    #+#              #
#    Updated: 2022/05/16 13:24:49 by djmekki          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a
INCLUDES = -I./includes

SRCS = ft_printf.c ./src/ft_ltoa.c ./src/ft_printf_c.c ./src/ft_printf_s.c\
		./src/ft_printf_pxcapx.c ./src/ft_printf_diu.c ./src/ft_printf_percentage.c


OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	make -C ./libft
	cp $(LIBFT) $(NAME)
	$(CC) -c $(CFLAGS) $(INCLUDES) $(SRCS)
	ar -rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	make clean -C ./libft/
	rm -f *.o ./src/*.o

fclean: clean
	make fclean -C ./libft/
	rm -f $(NAME)

re: fclean all
	make re -C ./libft/

.PHONY:
	all clean fclean re