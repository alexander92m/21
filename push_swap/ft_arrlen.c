#include "push_swap.h"

size_t	ft_arrlen(int *a)
{
	size_t	i;

	i = 0;
	while (a[i])
	{
		i++;
	}
	return (i - 1);
}