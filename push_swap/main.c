#include "push_swap.h"
/*
запись в массив А из аргументов
сортировка
вывод
*/
//make fclean && make && ./push_swap 324 23 3 546 6 8765

//create a
// int *create_a(int argc, char **argv)
// {
// 	int *a;
// 	a = ft_calloc(argc - 1, sizeof(int));
// 	if (a == NULL)
// 		return NULL;
// 	while (argc--)
// 	{
// 		a[argc] = ft_atoi(argv[argc]);
// 	}
// 	return a;
// }

static void show_array(int argc, int *x)
{
	int i = 0;
	while (i < argc)
	{
		printf("i=%d, x[i]=%d\n", i, x[i]);
		i++;
	}
}


static t_arrs	*initS(int argc, char **argv)
{
	t_arrs *arrs = NULL;
	
	arrs = malloc(sizeof(t_arrs));
	if (arrs == NULL)
	{
		return NULL;
	}
	
	arrs->argc = argc;
	
	arrs->a = ft_calloc(argc - 1, sizeof(int));
	
	if (arrs->a == NULL)
		return NULL;
	
	while (argc--)
	{
		arrs->a[argc] = ft_atoi(argv[argc]);
	}
	
	argc = arrs->argc;
	printf("argc=%d\n", argc);	
	arrs->b = ft_calloc(argc - 1, sizeof(int));
	printf("PRIVET\n");
	
	if (arrs->b == NULL)
		return NULL;
	while (argc--)
	{
		arrs->b[argc] = 0;
	}
	
	return arrs;
}

//main
int main(int argc, char **argv)
{
	t_arrs *arrs = NULL;
	int i;
	
	i = 0;
	
	
	arrs = initS(argc, argv);
	
	printf("\nA________________\n\n");
	show_array(argc, arrs->a);

	// sa(arrs->a);

	printf("\nA________________\n\n");
	show_array(argc, arrs->a);
	return (0);
}
