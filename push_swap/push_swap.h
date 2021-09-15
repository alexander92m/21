#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
#include <stdio.h>

typedef struct	s_arrs
{
	int		*a;
	int		lenA;
	int		argc;
	int		*b;
	int		lenB;
	int		cnts;
}				t_arrs;

void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *str);
size_t	ft_arrlen(int *a);
int		sa(t_arrs *arrs);
int		sb(t_arrs *arrs);
int		ss(t_arrs *arrs);
int		pb(t_arrs *arrs);
int		pa(t_arrs *arrs);
int		ra(t_arrs *arrs);
int		rb(t_arrs *arrs);
int		rr(t_arrs *arrs);
int		rra(t_arrs *arrs);
int		rrb(t_arrs *arrs);
int		rrr(t_arrs *arrs);
int		sort(t_arrs *arrs);
int		checkSort(t_arrs *arrs);
int		sortBubbles(t_arrs *arrs);
void	show_arrays(t_arrs *arrs);
int maxA(t_arrs *arrs);
int maxB(t_arrs *arrs);
int minA(t_arrs *arrs);
int minB(t_arrs *arrs);


#endif