#include "get_next_line.h"

int	main()
{
	char	*line;
	int		fd = 0;
	int		gnl;

	fd = open("1", O_RDONLY);
	gnl = get_next_line(fd, &line);
	close(fd);
	printf("ss=|%s|\n", line);
	return (0);
}