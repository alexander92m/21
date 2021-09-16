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
			if (i > arrs->lenA - i - 1)
			{
				return (-1);
			}
			else
			{
				return (1);
			}
		}
		i++;
	}
	return (0);
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

int rotate(t_arrs *arrs)
{
	int i;
	int b;
	int j;
	int min;
	int	optB = 0;
	
	min = 100500;
	j = 0;
	while (j < arrs->lenB)
	{
		i = 0;
		b = arrs->b[j];
		while (i < arrs->lenA)
		{
			if (b > arrs->a[i] && b < arrs->a[i + 1])
			{
				break ;
			}
			i++;
		}
		if (i < arrs->lenA - i - 1 && j < arrs->lenB - 1 - j && i + j < min)
		{
			min = i + j;
			optB = b;
			arrs->bRot = j;
			arrs->aRot = i + 1;
		}
		else if (i < arrs->lenA - i - 1 && j > arrs->lenB - j - 1 && i + arrs->lenB - j - 1 < min)
		{
			min = i + arrs->lenB - j - 1;
			optB = b;
			arrs->bRot = j - arrs->lenB - 1;
			if (arrs->lenB < 3)
				arrs->bRot = arrs->bRot + 3;
			arrs->aRot = i + 1;
		}
		else if (i > arrs->lenA - 1 - i && j > arrs->lenB - 1 - j && arrs->lenA - i - 1 + arrs->lenB - j - 1 < min)
		{
			min = arrs->lenA - i - 1 + arrs->lenB - j - 1;
			optB = b;
			arrs->bRot = j - 1 - arrs->lenB;
			arrs->aRot = i - 1 - arrs->lenA + 1;
		}
		else if (i > arrs->lenA - 1 - i && j < arrs->lenB - 1 - j && arrs->lenA - i - 1 + j < min)
		{
			min = arrs->lenA - i - 1 + j;
			optB = b;
			arrs->bRot = j;
			arrs->aRot = i - 1 - arrs->lenA + 1;
		}
		j++;
	}
	printf("da=%d, db=%d\n", arrs->aRot, arrs->bRot);
	while (arrs->aRot != 0 || arrs->bRot != 0)
	{
		if (arrs->aRot > 0 && arrs->bRot > 0)
		{
			rr(arrs);
			arrs->aRot--;
			arrs->bRot--;
		}
		else if (arrs->aRot > 0 && arrs->bRot < 0)
		{
			ra(arrs);
			rrb(arrs);
			arrs->aRot--;
			arrs->bRot++;
		}
		else if (arrs->aRot < 0 && arrs->bRot < 0)
		{
			rrr(arrs);
			arrs->aRot++;
			arrs->bRot++;
		}
		else if (arrs->aRot < 0 && arrs->bRot > 0)
		{
			rra(arrs);
			rb(arrs);
			arrs->aRot++;
			arrs->bRot--;
		}
		else if (arrs->aRot > 0 && arrs->bRot == 0)
		{
			ra(arrs);
			arrs->aRot--;
		}
		else if (arrs->aRot < 0 && arrs->bRot == 0)
		{
			rra(arrs);
			arrs->aRot++;
		}
		else if (arrs->aRot == 0 && arrs->bRot > 0)
		{
			rb(arrs);
			arrs->bRot--;
		}
		else if (arrs->aRot == 0 && arrs->bRot < 0)
		{
			rrb(arrs);
			arrs->bRot++;
		}
		
		
	}
	return	0;
}

int		LastB(t_arrs *arrs)
{
	int i;

	i = 0;
	while (i < arrs->lenA)
	{
		if (arrs->b[0] > arrs->a[i] && arrs->b[0] < arrs->a[i + 1])
		{
			if (i < arrs->lenA - i)
			{
				while (!(arrs->b[0] < arrs->a[0] && arrs->b[0] > arrs->a[arrs->lenA - 1]))
				{
					ra(arrs);
				}
				
			}
			else
			{
				while (!(arrs->b[0] < arrs->a[0] && arrs->b[0] > arrs->a[arrs->lenA - 1]))
				{
					rra(arrs);
				}
			}
			pa(arrs);
			break ;
		}
		i++;
	}
	return (0);
}

int		sort(t_arrs *arrs)
{	
	while (arrs->lenA > 2)
	{
		if (arrs->a[0] == maxA(arrs) || arrs->a[0] == minA(arrs))
			ra(arrs);
		else
			pb(arrs);
	}
	show_arrays(arrs);
	while (arrs->lenB != 1)
	{
		
		if (arrs->b[0] < arrs->a[0] && arrs->b[0] > arrs->a[arrs->lenA - 1])
			pa(arrs);
		else
			rotate(arrs);
	}

	show_arrays(arrs);

	LastB(arrs);

	show_arrays(arrs);
	
	while (checkSort(arrs) != 0)
	{
		// printf("QQ  %d\n", checkSort(arrs));
		if (checkSort(arrs) == 1)
			ra(arrs);
		else
			rra(arrs);
	}
	
	show_arrays(arrs);
	return (0);
}