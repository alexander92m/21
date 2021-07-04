#include "libftprintf.h"

#include <stdio.h>

int	main(void)
{
	
	char *s = "|privet|";
	printf("printf %s\n", s);
	ft_printf("|ft_printf|", s, "|asdasd|");
	
}
//cspdiuxX%
// clang -Wall -Wextra -Werror -g main.c libftprintf.c && ./a.out