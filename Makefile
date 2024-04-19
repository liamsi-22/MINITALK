# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iel-fagh <iel-fagh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/17 18:03:33 by pclaus            #+#    #+#              #
#    Updated: 2024/04/19 16:06:37 by iel-fagh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

SRC_CLIENT = client.c ft_atoi.c
SRC_CLIENT_BONUS = client_bonus.c ft_atoi.c
SRC_SERVER = server.c ft_putnbr.c ft_putchar.c
SRC_SERVER_BONUS = server_bonus.c ft_putnbr.c ft_putchar.c
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_CLIENT_BONUS = $(SRC_CLIENT_BONUS:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_SERVER_BONUS = $(SRC_SERVER_BONUS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

RV = rm

.o : .c
	$(CC) $(CFLAGS) -c $^ -o $@

all: $(NAME)

$(NAME): client server

client: $(OBJ_CLIENT)
	$(CC) $(CFLAGS) $^ -o $@

server: $(OBJ_SERVER)
	$(CC) $(CFLAGS) $^ -o $@

bonus: server_bonus client_bonus 

server_bonus: $(OBJ_SERVER_BONUS)
	$(CC) $(CFLAGS) $^ -o $@
	
client_bonus: $(OBJ_CLIENT_BONUS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RV) -f $(OBJ_CLIENT) $(OBJ_SERVER) $(OBJ_CLIENT_BONUS) $(OBJ_SERVER_BONUS)

fclean: clean
	$(RV) -f client server client_bonus server_bonus

re: fclean all

.PHONY: all clean fclean re
