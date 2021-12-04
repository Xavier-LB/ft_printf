NAME =		libftprintf.a

SRCS =		ft_printf.c

OBJS =		$(SRCS:.c=.o)

.c.o:		
		gcc -Wall -Wextra -Werror -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			  ar -rc $(NAME) $(OBJS)

all:		$(NAME)

clean:		
		rm -rf $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
