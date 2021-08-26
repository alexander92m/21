#include "push_swap.h"

void	sa(int *a)
{
	int temp;
	if (ft_arrlen(a) >= 2)
	{
		temp = a[0];
		a[0] = a[1];
		a[1] = temp;
	}
}
void	sb(int *b)
{
	sa(b);
}

void	ss(int *a, int *b)
{
	sa(a);
	sa(b);
}

int	pa(int **a, int **b)
{
	size_t	i;
	int *temp;
	
	i = 0;
	temp = ft_calloc(ft_arrlen(*a) + 1, sizeof(int));
	if (temp == NULL)
		return (-1);
	while (i < ft_arrlen(temp))
	{
		if (i == 1)
			temp[i] = *b[i];
		else
			temp[i] = *a[i - 1];

		i++;
	}

	return (0);
}


int	pb(int **a, int **b)
{
	size_t	i;
	int *temp;
	
	
	i = 0;
	if (*b != NULL)
	{
		temp = ft_calloc(ft_arrlen(*b) + 1, sizeof(int));
		if (temp == NULL)
			return (-1);
	}
	else
	{
		temp = ft_calloc(1, sizeof(int));
		if (temp == NULL)
			return (-1);
	}
	temp[i] = *a[i];
	printf("PRIVET\n");
	while (i < ft_arrlen(temp))
	{
		temp[i + 1] = *b[i];
		
		i++;
	}

	return (0);
}

// void	ra(int *a, int *b)
// {
	
// }

// void	rb(int *a, int *b)
// {
	
// }

// void	rr(int *a, int *b)
// {
	
// }


// void	rra(int *a, int *b)
// {
	
// }


// void	rrb(int *a, int *b)
// {
	
// }


// void	rrr(int *a, int *b)
// {
	
// }