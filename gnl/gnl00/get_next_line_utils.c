#include "get_next_line.h"

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

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

char	*ft_strjoi(char *s1, char *s2, size_t s2len)
{
	char	*s3;
	
	if (!s1)
	{
		s1 = malloc(1 * sizeof(char));
		s1[ft_strlen(s1)] = '\0';
	}
	s3 = malloc(sizeof(char) * (ft_strlen(s1) + s2len + 1));
	if (s3 == NULL)
		return (NULL);
	ft_memset(s3, 0, ft_strlen(s1) + s2len + 1);
	ft_memmove(s3, s1, ft_strlen(s1));
	ft_memmove(&(s3[ft_strlen(s1)]), s2, s2len);
	s3[ft_strlen(s1) + s2len] = '\0';
	free(s1);
	s1 = NULL;
	return (s3);
}

int	ft_index(char *s, char c)
{
	int		i;
	int		len;

	len = ft_strlen(s);
	i = 0;
	while (i < len)
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

void	*ft_memset(void *b, int c, size_t len)
{	
	unsigned int	i;

	i = 0;
	while (i < len)
		((unsigned char *)b)[i++] = c;
	return (b);
}