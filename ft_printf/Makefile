SRCS	= ft_printf.c ft_putchar.c ft_putnbr.c ft_putstr.c nb_digits.c ft_putunb.c ft_puthexa.c ft_putptr.c

OBJS	=$(SRCS:.c=.o)

NAME	=libftprintf.a 

CC	= gcc

CFLAGS	= -Wall -Werror -Wextra 

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)
	ranlib $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
.PHONY: all bonus clean fclean re