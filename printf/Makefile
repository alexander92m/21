NAME = libftprintf.a

LH = libftprintf.h

SRC = 

SRC_B = 

OBJ = $(SRC:.c=.o)

OBJ_B = $(SRC_B:.c=.o)

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

bonus : $(OBJ_B)
	$(AR) $(ARFLAGS) $(NAME) $?

re : fclean all
