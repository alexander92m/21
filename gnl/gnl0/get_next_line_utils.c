#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (&((char *)s)[i]);
		i++;
	}
	if (s[i] == c)
		return (&((char *)s)[i]);
	return (NULL);
}

char *ft_strjoi(char *s1, char *s2, size_t s2len)
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
	ft_memmove(s3, s1, ft_strlen(s1));
	ft_memmove(&(s3[ft_strlen(s1)]), s2, s2len);
	s3[ft_strlen(s1) + s2len] = '\0';
	free(s1);
	s1 = NULL;
	return (s3);
}

char	*ft_strdup (const char *s1)
{
	char	*s2;

	s2 = malloc(ft_strlen(s1) + 1, sizeof(char));
	if (NULL == s2)
		return (NULL);
	while (i < ft_strlen(s1) + 1)
		s2[i] = '\0';
	ft_memmove(s2, s1, ft_strlen(s1));
	return (s2);
}