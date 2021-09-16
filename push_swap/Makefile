NAME = push_swap

LH = push_swap.h

LA = push_swap.a

SRC =	main.c\
		ft_arrlen.c\
		ft_bzero.c\
		ft_calloc.c\
		ft_isdigit.c\
		ft_atoi.c\
		ft_memmove.c\
		ft_memset.c\
		ft_putchar_fd.c\
		ft_putendl_fd.c\
		ft_putstr_fd.c\
		ft_putnbr_fd.c\
		ft_strlen.c\
		ps2.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra -g

CC = clang
AR = ar
ARFLAGS = -rcs

.PHONY : all clean fclean re bonus

all : $(NAME)

$(NAME) : $(LA)
	$(CC) $? -o $@

$(LA) : $(OBJ)
	$(AR) $(ARFLAGS) $@ $?

%.o : %.c $(LH)
	$(CC) $(CFLAGS) -c $<

clean :
	rm -f $(OBJ)
	rm -f $(LA)
fclean : clean
	rm -f $(NAME)

re : fclean all
