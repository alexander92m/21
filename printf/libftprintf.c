#include "libftprintf.h"

void	ft_putstr(char *str, int *len)
{
	while (*str)
	{
		write(1, str++, 1);
	(*len)++;
	}
}
char	*ft_strdup (const char *s1)
{
	char	*s2;

	s2 = ft_calloc(ft_strlen(s1) + 1, sizeof(char));
	if (NULL == s2)
		return (NULL);
	ft_memmove(s2, s1, ft_strlen(s1));
	return (s2);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (src > dst)
	{
		i = 0;
		while (i < len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	else if (src < dst)
	{
		while (len-- > 0)
			((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
	}
	return (dst);
}
void	*ft_calloc(size_t count, size_t size)
{
	void	*arr;

	arr = malloc(count * size);
	if (arr == NULL)
		return (arr);
	ft_bzero(arr, count * size);
	return (arr);
}
void	ft_bzero(void *s, size_t n)
{	
	ft_memset(s, 0, n);
}
void	*ft_memset(void *b, int c, size_t len)
{	
	unsigned int	i;

	i = 0;
	while (i < len)
		((unsigned char *)b)[i++] = c;
	return (b);
}

size_t	ft_strlen(const char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

void	ft_putchar(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

int ifc(va_list ap, int *len)
{
	char	c;

	c = va_arg(ap, int);
	ft_putchar(c, len);
	return 1;
}

int ifs(va_list ap, int *len)
{
	char	*s;

	s = va_arg(ap, char *);
	ft_putstr(s, len);
	return ft_strlen(s);
}

void ft_putnbr16(long int pA, int *len)
{
	long int	tmp;

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

void ifp(va_list ap, int *len)
{
	void		*p;
	long int	pA;

	p = va_arg(ap, void *);
	pA = (long int)p;
	ft_putstr("0x", len);
	ft_putnbr16(pA, len);
}
void ft_putnbr(long int d, int *len)
{
	long tmp;

	if (d < 0)
	{
		if (d == -2147483648)
		{
			ft_putstr("-2", len);
			d = 147483648;
		} else
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

void ifd(va_list ap, int *len)
{
	int	d;

	d = va_arg(ap, int);
	ft_putnbr(d, len);
}

void ifu(va_list ap, int *len)
{
	int	u;

	u = va_arg(ap, unsigned int);
	printf("ifu() u=%u\n", u);
	ft_putnbr(u, len);
}

int printT(char c, va_list ap, int *len)
{
	(void)c;
	(void)ap;
	if (c == 'c')
	{
		ifc(ap, len);
	} else if (c == 's')
	{
		ifs(ap, len);
	} else if (c == 'p')
	{
		ifp(ap, len);
	} else if (c == 'd' || c == 'i')
	{
		ifd(ap, len);
	} else if (c == 'u')
	{
		ifu(ap, len);
	}
	return 0;
}

int ft_printf(const char *format, ...)
{
	int		i;
	int		len;

	len = 0;
	i = -1;
	va_list ap;
	va_start(ap, format);
	while (format[++i] != 0)
	{
		if (format[i] != '%')
		{
			ft_putchar(format[i], &len);
		} else if (format[i + 1] == '%')
		{
			ft_putchar('%', &len);
			i++;
		} else
		{	
			printT(format[++i], ap, &len);
		}
	}
	va_end (ap);
	return (len);
}