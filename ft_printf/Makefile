# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pclaus <pclaus@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/17 18:03:33 by pclaus            #+#    #+#              #
#    Updated: 2024/04/15 18:14:08 by iel-fagh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c ft_putchar.c ft_strchr.c ft_putnbr.c ft_putstr.c 

OBJ = $(SRC:.c=.o)

CC = cc

RV = rm

CFLAGS = -Wall -Wextra -Werror

LIB = ar -rc

all : $(NAME)

$(NAME) : $(OBJ)
	$(LIB) $@ $^

.o : .c
	$(CC) $(CFALGS) -c $^ -o $@

clean:
	$(RV) -rf $(OBJ)

fclean: clean
	$(RV) -rf $(NAME)

re: fclean all
