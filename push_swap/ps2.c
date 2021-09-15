#include "push_swap.h"



// swap first two elems of A
int		sa(t_arrs *arrs)
{
	int temp;

	arrs->cnts++;
	if (arrs->lenA > 1)
	{
		temp = arrs->a[0];
		arrs->a[0] = arrs->a[1];
		arrs->a[1] = temp;
		return (0);
	}
	else
		return (-1);
}

// swap first two elems of B
int		sb(t_arrs *arrs)
{
	int temp;

	arrs->cnts++;
	if (arrs->lenB > 1)
	{
		temp = arrs->b[0];
		arrs->b[0] = arrs->b[1];
		arrs->b[1] = temp;
		return (0);
	}
	else
		return (-1);
}

//sa && sb
int		ss(t_arrs *arrs)
{
	int	resA;
	int	resB;

	arrs->cnts++;
	resA = sa(arrs);
	resB = sb(arrs);
	if (resA == -1 || resB == -1)
	{
		return (-1);
	}
	else
	{
		return (0);
	}
}

//push first elem of A to top of B
int	pb(t_arrs *arrs)
{
	int		i;
	
	arrs->cnts++;
	if (arrs->lenA == 0)
		return (-1);
	i = arrs->lenB - 1;
	while (i > -1)
	{
		arrs->b[i + 1] = arrs->b[i];
		i--;
	}
	arrs->b[0] = arrs->a[0];
	arrs->lenB++;
	i = 0;
	while (i < arrs->lenA - 1)
	{
		arrs->a[i] = arrs->a[i + 1];
		i++;
	}
	arrs->lenA--; 
	return (0);
}

//push first elem of B to top of A
int		pa(t_arrs *arrs)
{
	int		i;
	
	arrs->cnts++;
	if (arrs->lenB == 0)
		return (-1);
	i = arrs->lenA - 1;
	while (i > -1)
	{
		arrs->a[i + 1] = arrs->a[i];
		i--;
	}
	arrs->a[0] = arrs->b[0];
	arrs->lenA++;
	i = 0;
	while (i < arrs->lenB - 1)
	{
		arrs->b[i] = arrs->b[i + 1];
		i++;
	}
	arrs->lenB--; 
	return (0);
}

/*rotate a - shift up all elements of stack a by 1. The first element becomes
the last one.*/
int		ra(t_arrs *arrs)
{
	int	temp;
	int	i;

	arrs->cnts++;
	i = 0;
	temp = arrs->a[0];
	while (i < arrs->lenA - 1)
	{
		arrs->a[i] = arrs->a[i + 1];
		i++;
	}
	arrs->a[arrs->lenA - 1] = temp;
	return 0;
}

/*rotate b - shift up all elements of stack a by 1. The first element becomes
the last one.*/
int		rb(t_arrs *arrs)
{
	int	temp;
	int	i;

	arrs->cnts++;
	i = 0;
	temp = arrs->b[0];
	while (i < arrs->lenB - 1)
	{
		arrs->b[i] = arrs->b[i + 1];
		i++;
	}
	arrs->b[arrs->lenB - 1] = temp;
	return 0;
}

// ra && rb
int		rr(t_arrs *arrs)
{
	int	resA;
	int	resB;

	arrs->cnts++;
	resA = ra(arrs);
	resB = rb(arrs);
	if (resA == -1 || resB == -1)
	{
		return (-1);
	}
	else
	{
		return (0);
	}
}

/*reverse rotate a - shift down all elements of stack a by 1. The last element
becomes the first one.*/
int		rra(t_arrs *arrs)
{
	int	temp;
	int	i;

	arrs->cnts++;
	i = arrs->lenA - 1;
	temp = arrs->a[arrs->lenA - 1];
	while (i > 0)
	{
		arrs->a[i] = arrs->a[i - 1];
		i--;
	}
	arrs->a[0] = temp;
	return 0;
}

/*reverse rotate a - shift down all elements of stack a by 1. The last element
becomes the first one.*/
int		rrb(t_arrs *arrs)
{
	int	temp;
	int	i;

	arrs->cnts++;
	i = arrs->lenB - 1;
	temp = arrs->b[arrs->lenB - 1];
	while (i > 0)
	{
		arrs->b[i] = arrs->b[i - 1];
		i--;
	}
	arrs->b[0] = temp;
	return 0;
}

// rra && rrb
int		rrr(t_arrs *arrs)
{
	int	resA;
	int	resB;

	arrs->cnts++;
	resA = rra(arrs);
	resB = rrb(arrs);
	if (resA == -1 || resB == -1)
	{
		return (-1);
	}
	else
	{
		return (0);
	}
}

int checkSort(t_arrs *arrs)
{
	int i;

	i = 0;
	while (i < arrs->lenA - 1)
	{
		if (arrs->a[i] > arrs->a[i + 1])
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int maxA(t_arrs *arrs)
{
	int	i;
	int max;
	int iMax;


	iMax = -1;
	max = -2147483648;
	i = 0;
	while (i < arrs->lenA)
	{
		if (arrs->a[i] > max)
		{
			max = arrs->a[i];
			iMax = i;
		}
		i++;
	}
	return max;
}

int minA(t_arrs *arrs)
{
	int	i;
	int min;
	int iMin;


	iMin = -1;
	min = 2147483647;
	i = 0;
	while (i < arrs->lenA)
	{
		if (arrs->a[i] < min)
		{
			min = arrs->a[i];
			iMin = i;
		}
		i++;
	}
	return (min);
}

int		sort(t_arrs *arrs)
{
	int max;
	int min;

	max = maxA(arrs);
	min = minA(arrs);
	
	while (arrs->lenA > 2)
	{
		if (arrs->a[0] == max || arrs->a[0] == min)
			ra(arrs);
		else
			pb(arrs);
	}
	show_arrays(arrs);
	
	while (arrs->lenB != 0)
	{
		if (arrs->b[0] < arrs->a[0] && arrs->b[0] > arrs->a[arrs->lenA - 1])
			pa(arrs);
		else
			rra(arrs);
	}
	printf("%d, %d\n", max, min);
	show_arrays(arrs);
	while (checkSort(arrs) != 1)
	{
		rra(arrs);
	}
	show_arrays(arrs);
	return (0);
}

int		sortBubbles(t_arrs *arrs)
{
	int *a;
	int i;
	int j;
	int temp = 0;

	i = 0;
	j = arrs->lenA - 1;
	a = arrs->a;
	
	while (j > 0)
	{
		i = 0;
		while (i < j)
		{
			if (a[i] > a[i + 1])
			{
				arrs->cnts++;
				temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
			}
			i++;
		}
		j--;
	}
	return (0);
}