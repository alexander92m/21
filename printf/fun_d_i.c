#include "libftprintf.h"

void	ifd(va_list ap, int *len)
{
	int	d;

	d = va_arg(ap, int);
	ft_putnbr(d, len);
}

void	ft_putnbr(long int d, int *len)
{
	long	tmp;

	if (d < 0)
	{
		if (d == -2147483648)
		{
			ft_putstr("-2", len);
			d = 147483648;
		}
		else
		{
			ft_putchar('-', len);
			d = -d;
		}
	}
	if (d > 9)
	{
		ft_putnbr(d / 10, len);
	}
	tmp = d % 10;
	ft_putchar('0' + tmp, len);
}
