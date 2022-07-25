NAME	= libftprintf.a

SRCS	= ft_printf.c ft_util.c ft_printf_util2.c ft_snprintf.c \
	  print_char.c print_nbr.c print_str.c print_util.c 

OBJS	= $(SRCS:.c=.o)
INCS	= -I.
LIBC	= ar rc
CC	= gcc
CFLAGS	= -Wall -Wextra -Werror
RM	= rm -f

.PHONY: all bonus clean fclean re

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) $(INCS) -c $<

$(NAME) : $(OBJS)
	$(LIBC) $(NAME) $(OBJS)

bonus:
	make WITH_BONUS=1 all

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
