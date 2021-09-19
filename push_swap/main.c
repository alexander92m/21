#include "push_swap.h"
/*
запись в массив А из аргументов
сортировка
вывод
*/
//make fclean && make && ./push_swap 5 4 7 6 9 8 3 2 1
//make fclean && make && ./push_swap 19 10 12 13 15 14 17 16 11 18

// arrs->a[0]=51319
// arrs->a[1]=76380
// arrs->a[2]=42958
// arrs->a[3]=53121
// arrs->a[4]=95039
// arrs->a[5]=99550
// arrs->a[6]=77792
// arrs->a[7]=61027
// arrs->a[8]=95008
// arrs->a[9]=51538
// arrs->a[10]=742
// arrs->a[11]=50099
// arrs->a[12]=61569
// arrs->a[13]=95626
// arrs->a[14]=34148
// arrs->a[15]=25638
// arrs->a[16]=54456
// arrs->a[17]=16406


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
	// arrs->a = malloc((argc - 1) * sizeof(int));
	// if (arrs->a == NULL)
	// 	return NULL;
	while (argc-- > 1)
		arrs->a[argc - 1] = ft_atoi(argv[argc]);
	arrs->lenA = arrs->argc - 1;
	arrs->lenB = 0;
	argc = arrs->argc;
	// arrs->b = malloc((argc - 1) * sizeof(int));
	// if (arrs->b == NULL)
	// 	return NULL;
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

//main
int main(int argc, char **argv)
{
	t_arrs *arrs = NULL;
	int i;
	
	i = 0;
	arrs = initS(argc, argv);
	sort(arrs);
	// show_arrays(arrs);
	// printf("if zero, that sorted %d\n", checkSort(arrs));
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