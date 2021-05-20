#include "get_next_line.h"

int	main()
{
	char	*s;
	int		fd = 0;
	int		gnl;

	fd = open("1", O_RDONLY);
	gnl = get_next_line(fd, &s);
	close(fd);
	printf("|%s|", s);
	return (0);
}