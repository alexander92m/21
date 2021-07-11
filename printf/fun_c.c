#include "libftprintf.h"

void	ifc(va_list ap, int *len)
{
	char	c;

	c = va_arg(ap, int);
	ft_putchar(c, len);
}
