#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>

// NEED TO DELETE BEFORE CLOSE PROJECT
#include <stdio.h>
#include <fcntl.h>

int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *s);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoi(char *s1, char *s2, size_t s2len);
char	*ft_strdup(const char *s1);


#endif
