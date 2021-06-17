#include "get_next_line.h"

int	main(int argc, char **argv)
{
	char	*line = NULL;
	int		fd;
	int		gnl;
	int		i;

	i = 1;
	printf("argc=%d, argv[0]=%s\n", argc, argv[0]);
	if (argc > 1)
	{
		while (i <= argc)
		{
			fd = 0;
			gnl = get_next_line(fd, &line);
			i++;
		}
		
	}
	else
	{
		
		gnl = 1;
		fd = open("normal.txt", O_RDONLY);
		while (gnl > 0)
		{
			gnl = get_next_line(fd, &line);
			printf("%d. line=|%s|, fd=%d, gnl=|%d|\n\n", i++, line, fd, gnl);
			/*if (line != NULL)
			{
				free(line);
				line = NULL;
			}*/
		}
		return (0);
	}
}
//clang -g -Wall -Werror -Wextra main.c get_next_line.c get_next_line.h get_next_line_utils.c -D BUFFER_SIZE=1 && ./a.out
