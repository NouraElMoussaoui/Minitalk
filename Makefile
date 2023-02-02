# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/14 10:10:43 by nel-mous          #+#    #+#              #
#    Updated: 2023/01/14 10:10:52 by nel-mous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_CLIENT	= client.c

SRC_SERVER = server.c

SRC_CLIENT_BNS = client_bonus.c 

SRC_SERVER_BNS = server_bonus.c 

OBJ_CLIENT	= $(SRC_CLIENT:.c=.o)

OBJ_SERVER = $(SRC_SERVER:.c=.o)

OBJ_CLIENT_BNS = $(SRC_CLIENT_BNS:.c=.o)

OBJ_SERVER_BNS = $(SRC_SERVER_BNS:.c=.o)

NAME	= libft/libft.a ft_printf/libftprintf.a

NAME_CLIENT = client
NAME_SERVER = server

NAMEB_CLIENT = client_bonus
NAMEB_SERVER = server_bonus

CC	= cc

CFLAGS	= -Wall -Wextra -Werror

RM = rm -f

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME) $(NAME_CLIENT) $(NAME_SERVER)

$(NAME):
	make -C libft all
	make -C ft_printf all

$(NAME_SERVER): $(OBJ_SERVER)
	$(CC) $(CFLAGS) $< $(NAME) -o server

$(NAME_CLIENT) : $(OBJ_CLIENT)
	$(CC) $(CFLAGS) $< $(NAME) -o client

clean:
	make -C libft fclean
	make -C ft_printf fclean
	$(RM) $(OBJ_CLIENT) $(OBJ_SERVER)
	$(RM) $(OBJ_CLIENT_BNS) $(OBJ_SERVER_BNS)

fclean: clean
	$(RM) $(NAME_CLIENT) $(NAME_SERVER)
	$(RM) $(NAMEB_CLIENT) $(NAMEB_SERVER)

re: fclean all

$(NAMEB_SERVER): $(OBJ_SERVER_BNS)
	$(CC) $(CFLAGS) $< libft/libft.a ft_printf/libftprintf.a -o server_bonus 

$(NAMEB_CLIENT): $(OBJ_CLIENT_BNS)
	$(CC) $(CFLAGS) $< libft/libft.a ft_printf/libftprintf.a -o client_bonus

bonus: $(NAME) $(NAMEB_CLIENT) $(NAMEB_SERVER)
