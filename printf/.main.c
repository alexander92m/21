#include "libftprintf.h"

#include <stdio.h>

int	main(void)
{
	char			c = 'a';
	int				d = 2147;
	unsigned int	ui = 666;
	int				x = 123;
	int len1, len2;
	(void)c;
	(void)d;
	(void)ui;
	(void)x;

	char			*s = NULL;
	char	*s2 = NULL;
	// len1 = ft_printf("1 %% c=%c s=%s|s2=%s, p=%p, pN=%p, d=%d, i=%i, u=%u, x=%x, X=%X\n", c, s, s2, s2, s, d, -777, -1, -26564, -26);
	// len2 = printf("1 %% c=%c s=%s|s2=%s, p=%p, pN=%p, d=%d, i=%i, u=%u, x=%x, X=%X\n", c, s, s2, s2, s, d, -777, -1, -26564, -26);
	// ft_printf("len1=%d, len2=%d\n", len1, len2);
	// len1 = ft_printf("%a \n");
	// //len2 = printf("%a \n");
	// ft_printf("len1=%d, len2=%d\n", len1, len2);
	// len1 = ft_printf("fhfsh\n");
	// len2 = printf("fhfsh\n");
	// ft_printf("len1=%d, len2=%d\n", len1, len2);
	len1 = ft_printf("%s\n", s);
	len2 = printf("%s\n",s2);
	ft_printf("len1=%d, len2=%d\n", len1, len2);
	
	// len1 = ft_printf("p=%p\n", s);
	// len2 = printf("p=%p\n", s);
	// ft_printf("len1=%d, len2=%d\n", len1, len2);
	// len1 = ft_printf("p=%p\n", s);
	// len2 = printf("p=%p\n", s);
	// ft_printf("len1=%d, len2=%d\n", len1, len2);
	
}
// clang -Wall -Wextra -Werror -g main.c libftprintf.a && ./a.out