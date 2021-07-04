#include "libftprintf.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);

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


t_print *ft_initialise_tab(t_print *tab)                       
{                       
      tab->wdt = 0;        //we set everything to 0, false        
      tab->prc = 0;                        
      tab->zero = 0;                        
      tab->pnt = 0;                        
      tab->sign = 0;                        
      tab->tl = 0;                        
      tab->is_zero = 0;                        
      tab->dash = 0;                        
      tab->perc = 0;                        
      tab->sp = 0;                        
      return (tab);                       
}
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void parse0(char c)
{
	if (c != '%')
		ft_putchar(c);
	else
	{
		
	}
}
int ft_printf(const char *format, ...)
{
	t_print *tab;
	int		i;

	i = 0;
	tab = (t_print *)malloc(sizeof(t_print));                        
	if (!tab)                         
		return (-1);
	tab = ft_initialise_tab(tab);
	

	while (format[i] != 0)
	{
		parse0(format[i++]);
	}
	// char *s = ft_strdup(format);
	// ft_putstr(s);

	va_list ap;
	va_start(ap, format);
	char *p = va_arg (ap, char *);
	ft_putstr(p);

	char *p2 = va_arg (ap, char *);
	ft_putstr(p2);

	va_end (ap);
	return (0);
}