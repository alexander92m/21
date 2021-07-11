#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
void	ft_putchar(char c, int *len);
void	ft_putstr(char *str, int *len);
size_t	ft_strlen(const char *str);
void	ifc(va_list ap, int *len);
void	ifs(va_list ap, int *len);
void	ifp(va_list ap, int *len);
void	ft_putnbr16(unsigned long long pA, int *len);
void	ifd(va_list ap, int *len);
void	ft_putnbr(long int d, int *len);
void	ifu(va_list ap, int *len);
void	ft_putnbrU(unsigned int d, int *len);
void	ifx(va_list ap, int *len);
void	ft_putnbr16x(unsigned int pA, int *len);
void	ifX(va_list ap, int *len);
void	ft_putnbr16X(unsigned int pA, int *len);

#endif
