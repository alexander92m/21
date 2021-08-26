#include "push_swap.h"
/*
запись в массив А из аргументов
сортировка
вывод
*/
//make fclean && make && ./push_swap 324 23 3 546 6 8765

//create a
int *create_a(int argc, char **argv)
{
	int *a;
	a = ft_calloc(argc - 1, sizeof(int));
	if (a == NULL)
		return NULL;
	while (argc--)
	{
		a[argc] = ft_atoi(argv[argc]);
	}
	return a;
}

static void show_array(int argc, int *x)
{
	int i = 0;
	while (i < argc)
	{
		printf("i=%d, x[i]=%d\n", i, x[i]);
		i++;
	}
}

//main
int main(int argc, char **argv)
{
	int *a;
	int *b;
	int i;

	i = 0;
	a = create_a(argc, argv);
	if (a == NULL)
		return (-1);

	b = NULL;
	//show a
	printf("\nA________________\n\n");
	show_array(argc, a);

	sa(a);
	// pb(&a, &b);
	// pa(&a, &b);
	printf("arrlen=%zu\n", ft_arrlen(a));
	//show a
	printf("\nA________________\n\n");
	show_array(argc, a);
	//show b
	// printf("\nB________________\n\n");
	// show_array(argc, b);

	return (0);
}
