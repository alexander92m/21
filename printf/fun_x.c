#include "libftprintf.h"

void	ifx(va_list ap, int *len)
{
	unsigned int	x;

	x = va_arg(ap, unsigned int);
	ft_putnbr16x(x, len);
}

void	ft_putnbr16x(unsigned int pA, int *len)
{
	unsigned int	tmp;

	if (pA > 15)
	{
		ft_putnbr16x(pA / 16, len);
	}
	tmp = pA % 16;
	if (tmp < 10)
		ft_putchar('0' + tmp, len);
	else
		ft_putchar('a' + tmp - 10, len);
}
