CC =		gcc

FLAGS =		-Wall -Wextra -Werror

NAME =		libftprintf.a

SRCS =		ft_printf.c \
		srcs/ft_putchar_len.c \
		srcs/ft_putstr_len.c \
		srcs/ft_putnbr_len.c \
		srcs/ft_put_lower_hexa.c \
		srcs/ft_put_upper_hexa.c \
		srcs/ft_put_unint_nbr_len.c \
		srcs/ft_putptr_len.c

OBJS =		$(SRCS:.c=.o)

.c.o:		
		$(CC) $(FLAGS) -I./includes -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			  ar -rc $(NAME) $(OBJS)

all:		$(NAME)

clean:		
		rm -rf $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
