#include "libftprintf.h"

void	ifX(va_list ap, int *len)
{
	unsigned int	x;

	x = va_arg(ap, unsigned int);
	ft_putnbr16X(x, len);
}

void	ft_putnbr16X(unsigned int pA, int *len)
{
	unsigned int	tmp;

	if (pA > 15)
	{
		ft_putnbr16X(pA / 16, len);
	}
	tmp = pA % 16;
	if (tmp < 10)
		ft_putchar('0' + tmp, len);
	else
		ft_putchar('A' + tmp - 10, len);
}
