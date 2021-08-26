#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
#include <stdio.h>

void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
int		*create_a(int argc, char **argv);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *str);
size_t	ft_arrlen(int *a);
void	sa(int *a);
void	sb(int *b);
void	ss(int *a, int *b);
int		pa(int **a, int **b);
int		pb(int **a, int **b);

#endif