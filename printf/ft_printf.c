#include "libftprintf.h"

void	ft_putchar(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

void	ft_putstr(char *str, int *len)
{
	while (*str)
	{
		write(1, str++, 1);
		(*len)++;
	}
}

size_t	ft_strlen(const char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

int	printT(char c, va_list ap, int *len)
{
	(void)c;
	(void)ap;
	if (c == 'c')
		ifc(ap, len);
	else if (c == 's')
		ifs(ap, len);
	else if (c == 'p')
		ifp(ap, len);
	else if (c == 'd' || c == 'i')
		ifd(ap, len);
	else if (c == 'u')
		ifu(ap, len);
	else if (c == 'x')
		ifx(ap, len);
	else if (c == 'X')
		ifX(ap, len);
	else if (c == '%')
		ft_putchar('%', len);
	else
		return (-1);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	int		ret;
	va_list	ap;

	ret = 0;
	len = 0;
	i = -1;
	va_start(ap, format);
	while (format[++i] != 0)
	{
		if (format[i] != '%')
			ft_putchar(format[i], &len);
		else
		{
			ret = printT(format[++i], ap, &len);
			if (ret != 0)
				return (ret);
		}
	}
	va_end (ap);
	return (len);
}
