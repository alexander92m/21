#include "push_swap.h"
/*
запись в массив А из аргументов
сортировка
вывод
*/
//make fclean && make && ./push_swap 5 4 7 6 9 8 3 2 1
//make fclean && make && ./push_swap 19 10 12 13 15 14 17 16 11 18

//show arrays, must delete before push
void show_arrays(t_arrs *arrs)
{
	int i = 0;

	printf("----------lenA=%d\n", arrs->lenA);
	while (i < arrs->lenA)
	{
		printf("arrs->a[%d]=%d\n", i, (arrs->a)[i]);
		i++;
	}
	i = 0;
	printf("lenB=%d\n", arrs->lenB);
	while (i < arrs->lenB)
	{
		printf("arrs->b[%d]=%d\n", i, arrs->b[i]);
		i++;
	}
	printf("ОПЕРАЦИЙ: %d\n", arrs->cnts);
}
static void initC(t_arrs *arrs)
{
	int i;

	i = 0;
	while (i < arrs->lenA)
	{
		arrs->c[i] = arrs->a[i];
		i++;
	}
	arrs->lenC = arrs->lenA;
	sortBubblesC(arrs);
}

//create started stacks(arrays)
static t_arrs	*initS(int argc, char **argv)
{
	t_arrs *arrs = NULL;
	
	arrs = malloc(sizeof(t_arrs));
	if (arrs == NULL)
		return NULL;
	arrs->argc = argc;
	while (argc-- > 1)
		arrs->a[argc - 1] = ft_atoi(argv[argc]);
	arrs->lenA = arrs->argc - 1;
	arrs->lenB = 0;
	argc = arrs->argc;
	while (argc--)
		arrs->b[argc] = 0;
	arrs->cnts = 0;
	arrs->maxA = maxA(arrs);
	arrs->minA = minA(arrs);
	initC(arrs);
	return arrs;
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
				return (-1);
			else
				return (1);
		}
		i++;
	}
	return (0);
}

int	ft_isminus(int c)
{
	if (c == '-')
		return (1);
	return (0);
}

int ft_rangeInt(char *s)
{
	int i;

	i = -1;
	if (ft_strlen(s) > 11)
		return (0);
	else if (ft_strlen(s) < 10 || (ft_strlen(s) == 10 && ft_isminus(s[0]) == 1))
		return (1);
	else if (ft_strlen(s) == 10 && ft_isminus(s[0]) == 0)
	{
		while (s[++i])
			if (s[i] > "2147483647"[i])
				return (0);
	}
	else if (ft_strlen(s) == 11 && ft_isminus(s[0]) == 1)
	{
		while (s[++i])
			if (s[i] > "-2147483648"[i])
				return (0);
	}
	return (1);
}

//its int? in range int? is doubles? if norm -> return 0
int	errorCheck(int argc, char **argv, t_arrs *arrs)
{
	int	i;
	int	j;
	int	k;


	i = 1;
	while (i < argc)
	{
		j = -1;
		while (argv[i][++j])
			if (!(ft_isdigit(argv[i][j]) || ft_isminus(argv[i][j])))
				return (1);
		if (!ft_rangeInt(argv[i++]))
			return (1);
		j = -1;
		while (++j < arrs->lenA)
		{
			k = -1;
			while (++k < arrs->lenA)
				if (arrs->a[j] == arrs->a[k] && j != k)
					return (1);
		}
	}
	return (0);
}

// printf("PRIVET\n");
//main
int main(int argc, char **argv)
{
	t_arrs *arrs = NULL;
	int i;

	i = 0;
	arrs = initS(argc, argv);
	if (errorCheck(argc, argv, arrs))
	{
		write(1, "Error\n", 6);
	}
	else  if (argc != 1 && checkSort(arrs) != 0)
	{
		show_arrays(arrs);
		if (arrs->lenA > 10)
			sort(arrs);
		else
			altSort(arrs);
		printf("if zero, that sorted %d\n", checkSort(arrs));
		show_arrays(arrs);
	}
	
	free(arrs);
	arrs = NULL;
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

int		sortBubblesC(t_arrs *arrs)
{
	int *a;
	int i;
	int j;
	int temp = 0;

	i = 0;
	j = arrs->lenC - 1;
	a = arrs->c;
	while (j > 0)
	{
		i = 0;
		while (i < j)
		{
			if (a[i] > a[i + 1])
			{
				temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
			}
			i++;
		}
		j--;
	}
	arrs->midA =  arrs->c[arrs->lenC / 2];
	return (0);
}