#include "push_swap.h"

void	*ft_memset(void *b, int c, size_t len)
{	
	unsigned int	i;

	i = 0;
	while (i < len)
		((int *)b)[i++] = c;
	return (b);
}
