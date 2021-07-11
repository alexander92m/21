#include "libftprintf.h"

void	ifp(va_list ap, int *len)
{
	void		*p;
	long int	pA;

	p = va_arg(ap, void *);
	pA = (unsigned long long)p;
	ft_putstr("0x", len);
	ft_putnbr16(pA, len);
}

void	ft_putnbr16(unsigned long long pA, int *len)
{
	unsigned long long	tmp;

	if (pA > 15)
	{
		ft_putnbr16(pA / 16, len);
	}
	tmp = pA % 16;
	if (tmp < 10)
		ft_putchar('0' + tmp, len);
	else
		ft_putchar('a' + tmp - 10, len);
}
