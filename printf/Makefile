NAME = libftprintf.a

LH = libftprintf.h

SRC =	ft_printf.c\
		fun_c.c\
		fun_d_i.c\
		fun_p.c\
		fun_s.c\
		fun_u.c\
		fun_x.c\
		fun_XX.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra

CC = clang
AR = ar
ARFLAGS = -rcs

.PHONY : all clean fclean re bonus

all : $(NAME)

$(NAME) : $(OBJ)
	$(AR) $(ARFLAGS) $@ $?

%.o : %.c $(LH)
	$(CC) $(CFLAGS) -c $<

clean :
	rm -f $(OBJ) $(OBJ_B)

fclean : clean
	rm -f $(NAME)

re : fclean all
