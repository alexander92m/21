#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_index(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (src > dst)
	{
		i = 0;
		while (i < len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	else if (src < dst)
	{
		while (len-- > 0)
			((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
	}
	return (dst);
}

void ft_sch(char *s)
{
	s = ft_memmove(s, &(s[ft_index(s) + 1]), ft_strlen(s) - ft_index(s));
}

int	get_next_line(int fd, char **line)
{
	char		s[BUFF_SIZE + 1] = "";
	static char	*tmp = malloc(sizeof(char) * 1);
	int			ret;

	tmp[]
	ret = 1;
	while (ret > 0)
	{
		ret = read()




	}
	return (1);
}
