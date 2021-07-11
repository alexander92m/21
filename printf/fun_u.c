#include "libftprintf.h"

void	ft_putnbrU(unsigned int d, int *len)
{
	unsigned int	tmp;

	if (d > 9)
	{
		ft_putnbr(d / 10, len);
	}
	tmp = d % 10;
	ft_putchar('0' + tmp, len);
}

void	ifu(va_list ap, int *len)
{
	int	u;

	u = va_arg(ap, unsigned int);
	ft_putnbrU(u, len);
}
