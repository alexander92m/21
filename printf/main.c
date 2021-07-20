#include "libftprintf.h"

#include <stdio.h>

int	main(void)
{
	char			c = 'Z';
	int				d = -777;
	int				*p = &d;
	unsigned int	ui = 666;
	int				x = 123;
	int len1, len2;
	(void)c;
	(void)d;
	(void)p;
	(void)ui;
	(void)x;

	char			*s = "privet1 ";
	//printf("len1=%d, len2=%d\n", ft_printf("1 %% c=%c s=%s p=%p, d=%d, i=%i\n", c, s, s, -228, -777), printf("1 %% c=%c s=%s p=%p, d=%d, i=%i\n", c, s, s, -228, -777));
	len1 = ft_printf("1 %% c=%c s=%s p=%p, d=%d, i=%i, u=%u, x=%x, X=%X\n", c, s, s, -228, -777, -658, 255, 255);
	len2 = printf("2 %% c=%c s=%s p=%p, d=%d, i=%i, u=%u, x=%x, X=%X\n", c, s, s, -228, -777, -658, 255, 255);
	printf("len1=%d, len2=%d\n", len1, len2);
}
//cspdiuxX%
// clang -Wall -Wextra -Werror -g main.c libftprintf.c && ./a.out
