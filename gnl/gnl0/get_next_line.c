#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*tmp = NULL;
	int			byte;

	byte = 1;
	while (byte > 0)
	{
		byte = read(fd, buf, BUFFER_SIZE);
		tmp = ft_strjoi(tmp, buf, BUFFER_SIZE);

	}
	*line = ft_strdup(tmp);
	return (1);
}