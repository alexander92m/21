#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

size_t	ft_slen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != '\n')
	{
		i++;
	}
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
	s = ft_memmove(s, &(s[ft_slen(s) + 1]), ft_strlen(s) - ft_slen(s));
}

int	get_next_line(int fd, char **line)
{
	static char	s[BUFF_SIZE + 1];
	int			ret;

	(void)(*line);
	while (ft_strchr(s, ))
	{


	}
	ret = read(fd, s, BUFF_SIZE);
	s[ret] = '\0';
	printf("i=|%zu|\n", ft_strlen(s));
	printf("i=|%zu|\n", ft_slen(s));
	printf("|%s|\n", s);
	ft_sch(s);
	printf("i=|%zu|\n", ft_slen(s));
	printf("|%s|\n", s);
	
	
	return (0);
}
