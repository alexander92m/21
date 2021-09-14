#include "push_swap.h"
/*
запись в массив А из аргументов
сортировка
вывод
*/
//make fclean && make && ./push_swap 5 4 7 6 9 8 3 2 1
//make fclean && make && ./push_swap 19 10 12 13 15 14 17 16 11 18


//show arrays, must delete before push
static void show_arrays(t_arrs *arrs)
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

// static void		*initCnts(t_arrs *arrs)
// {
// 	arrs->
// }

//create started stacks(arrays)
static t_arrs	*initS(int argc, char **argv)
{
	t_arrs *arrs = NULL;
	
	arrs = malloc(sizeof(t_arrs));
	if (arrs == NULL)
		return NULL;
	arrs->argc = argc;
	arrs->a = malloc((argc - 1) * sizeof(int));
	if (arrs->a == NULL)
		return NULL;
	printf("%d\n", argc);
	while (argc-- > 1)
		arrs->a[argc - 1] = ft_atoi(argv[argc]);
	arrs->lenA = arrs->argc - 1;
	arrs->lenB = 0;
	argc = arrs->argc;
	arrs->b = malloc((argc - 1) * sizeof(int));
	if (arrs->b == NULL)
		return NULL;
	while (argc--)
		arrs->b[argc] = 0;
	arrs->cnts = 0;
	return arrs;
}

//main
int main(int argc, char **argv)
{
	t_arrs *arrs = NULL;
	int i;
	
	i = 0;
	arrs = initS(argc, argv);
	show_arrays(arrs);
	
	printf("checksort %d\n", checkSort(arrs));
	// sortBubbles(arrs);
	sort(arrs);
	// sa(arrs);
	// ra(arrs);
	// sa(arrs);
	// ra(arrs);
	// sa(arrs);
	// ra(arrs);
	// sa(arrs);
	// ra(arrs);
	// show_arrays(arrs);
	printf("checksort %d\n", checkSort(arrs));
	return (0);
}
