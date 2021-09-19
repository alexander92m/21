#include "push_swap.h"



// swap first two elems of A
int		sa(t_arrs *arrs)
{
	int temp;

	
	if (arrs->lenA > 1)
	{
		temp = arrs->a[0];
		arrs->a[0] = arrs->a[1];
		arrs->a[1] = temp;
		arrs->cnts++;
	
		
	}
	write(1, "sa\n", 3);
	return (0);
}

// swap first two elems of B
int		sb(t_arrs *arrs)
{
	int temp;

	if (arrs->lenB > 1)
	{
		temp = arrs->b[0];
		arrs->b[0] = arrs->b[1];
		arrs->b[1] = temp;
		arrs->cnts++;
		write(1, "sa\n", 3);
		return (0);
	}
	else
		return (-1);
}

//sa && sb
// int		ss(t_arrs *arrs)
// {
// 	int	resA;
// 	int	resB;

// 	arrs->cnts++;
// 	resA = sa(arrs);
// 	resB = sb(arrs);
// 	if (resA == -1 || resB == -1)
// 	{
// 		return (-1);
// 	}
// 	else
// 	{
// 		return (0);
// 	}
// }

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
	write(1, "pb\n", 3);
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
	write(1, "pa\n", 3);
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
	write(1, "ra\n", 3);
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
	write(1, "rb\n", 3);
	return 0;
}

// ra && rb
int		rr(t_arrs *arrs)
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

	i = 0;
	temp = arrs->b[0];
	while (i < arrs->lenB - 1)
	{
		arrs->b[i] = arrs->b[i + 1];
		i++;
	}
	arrs->b[arrs->lenB - 1] = temp;
	write(1, "rr\n", 3);
	return (0);
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
	write(1, "rra\n", 4);
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
	write(1, "rrb\n", 4);
	return 0;
}

// rra && rrb
int		rrr(t_arrs *arrs)
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
	i = arrs->lenB - 1;
	temp = arrs->b[arrs->lenB - 1];
	while (i > 0)
	{
		arrs->b[i] = arrs->b[i - 1];
		i--;
	}
	arrs->b[0] = temp;
	write(1, "rrr\n", 4);

	return 0;
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
			if (arrs->b[j] > arrs->a[i] && arrs->b[j] < arrs->a[i + 1])
			{
				break ;
			}
			
			
			i++;
		}
		if (i < arrs->lenA - i && j < arrs->lenB - j && i + j < min)
		{
			min = i + j;
			optB = b;
			arrs->bRot = j;
			arrs->aRot = i + 1;
		}
		else if (i < arrs->lenA - i && j > arrs->lenB - j && i + arrs->lenB - j < min)
		{
			min = i + arrs->lenB - j;
			optB = b;
			arrs->bRot = j - arrs->lenB;
			if (arrs->lenB < 3)
				arrs->bRot = arrs->bRot + 3;
			arrs->aRot = i + 1;
		}
		else if (i > arrs->lenA - i && j > arrs->lenB - j && arrs->lenA - i + arrs->lenB - j < min)
		{
			min = arrs->lenA - i + arrs->lenB - j;
			optB = b;
			arrs->bRot = j - 1 - arrs->lenB;
			arrs->aRot = i - 1 - arrs->lenA + 1;
		}
		else if (i > arrs->lenA - i && j < arrs->lenB  - j && arrs->lenA - i + j < min)
		{
			min = arrs->lenA - i + j;
			optB = b;
			arrs->bRot = j;
			arrs->aRot = i - 1 - arrs->lenA + 1;
		}
		j++;
	}
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

int semiSort(t_arrs *arrs)
{
	int i;

	i = 0;
	while (i < arrs->lenA - 1)
	{
		if (arrs->a[i] == arrs->maxA && arrs->a[i + 1] == arrs->minA)
		{

		}
		else if (arrs->a[i] > arrs->a[i + 1])
		{
			return (1);
		}
		i++;
	}
	return (0);

}

//  min <  числа < mid отсутствуют
int done1(t_arrs *arrs)
{
	int i;
	int flag;

	flag = 0;
	i = 0;
	while (!flag && i < arrs->lenA)
	{
		if (arrs->a[i] > arrs->minA && arrs->a[i] < arrs->midA)
		{
			flag = 1;
			break ;
		}
		i++;
	}
	return flag;
	
}

int		sort(t_arrs *arrs)
{	
	// while (semiSort(arrs) != 0)
	// {		
	// 	if (arrs->a[0] == maxA(arrs))
	// 	{
	// 		ra(arrs);
	// 		while (arrs->a[0] != arrs->minA)
	// 		{
	// 			pb(arrs);
	// 		}			
	// 	}
	// 	else if (arrs->a[0] == minA(arrs))
	// 	{
	// 		ra(arrs);
	// 		while (arrs->a[0] != arrs->maxA)
	// 		{
	// 			if (arrs->a[0] > arrs->a[1])
	// 			{
	// 				pb(arrs);
	// 			}
	// 			else
	// 			{
	// 				ra(arrs);
	// 			}
	// 		}	
	// 	}
	// 	else
	// 	{
	// 		ra(arrs);
	// 	}
	// }

	while (done1(arrs))
	{
		
		if (arrs->a[0] > arrs->minA && arrs->a[0] < arrs->midA)
		{
			pb(arrs);
		}
		else
		{
			ra(arrs);
		}
	}
	while (arrs->lenA != 3)
	{
	
		if (arrs->a[0] > arrs->midA && arrs->a[0] < arrs->maxA)
		{
			pb(arrs);
		}
		else
		{
			ra(arrs);
		}
	}	
	while (1 == 1)
	{
		if (arrs->a[0] == arrs->midA)
		{
			if (arrs->a[1] != arrs->maxA)
			{
				sa(arrs);
				break ;
			}
			else
			{
				break ;
			}
		}
		else
		{
			ra(arrs);
		}
	}
	while (arrs->lenB != 1)
	{	
		if (arrs->b[0] < arrs->a[0] && arrs->b[0] > arrs->a[arrs->lenA - 1])
			pa(arrs);
		else
			rotate(arrs);	
	}
	LastB(arrs);
	while (checkSort(arrs) != 0)
	{
		if (checkSort(arrs) == 1)
			ra(arrs);
		else
			rra(arrs);
	}
	return (0);
}