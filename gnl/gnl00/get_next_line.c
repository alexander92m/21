#include "get_next_line.h"

void	zeroer(char **ptr)
{
	int	i;

	i = 0;
	while ((*ptr)[i])
	{
		(*ptr)[i++] = 0;
	}
}

void	freenator(char **ptr)
{
	int	i;

	i = 0;
	if (*ptr != NULL)
	{
		zeroer(ptr);
		//(*ptr)[0] = 0;
		free(*ptr);
		*ptr = NULL;
	}	
}

void	buf_change(char *ptr)
{
	int	ind;
	int	len;

	len = ft_strlen(ptr);
	ind = ft_index(ptr, '\n');
	if (ind != -1 && len > ind + 1)
	{
		ft_memmove(ptr, &((ptr)[ind + 1]), len - ind - 1);
		ptr[len - ind - 1] = 0;
	}
	else
		zeroer(&ptr);
}

void	next_line(char *bf, char **line, int fd, int *ret)
{
	while (*ret > 0)
	{
		if (ft_strlen(bf) == 0)
		{
			*ret = read(fd, bf, BUFFER_SIZE);
			bf[*ret] = 0;
			
		}
		*ret = ft_strlen(bf);
		if (*ret < 1)
		{
			
			*line = ft_strjoi(*line, bf, *ret);
			break ;
		}
		if (ft_index(bf, '\n') == -1)
		{
			
			*line = ft_strjoi(*line, bf, *ret);
			zeroer(&bf);
		}
		else
		{
			
			*line = ft_strjoi(*line, bf, ft_index(bf, '\n'));
			break ;
		}
	}
}

int	get_next_line(int fd, char **line)
{
	static char		buf[BUFFER_SIZE + 1];
	int				ret;

	//printf("p(line)=|%p|  ", *line);
	if (!line || fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (-1);
	freenator(line);
	//printf("p(line)=|%p|  ", *line);
	ret = 1;
	next_line(buf, line, fd, &ret);
	buf_change(buf);
	//printf("p(line)=|%p|  ", *line);
	if (ret == 0)
		return (0);
	return (1);
}
