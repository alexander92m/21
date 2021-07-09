# ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>


int				ft_printf(const char *, ...);

void			ft_putstr(char *str, int *len);
char			*ft_strdup (const char *s1);
void			*ft_memmove(void *dst, const void *src, size_t len);

void			*ft_calloc(size_t count, size_t size);
size_t			ft_strlen(const char *str);
void			ft_bzero(void *s, size_t n);
void			*ft_memset(void *b, int c, size_t len);
void			ft_putchar(char c, int *len);
int				printT(char c, va_list ap, int *len);
# endif
