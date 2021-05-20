#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>

// NEED TO DELETE BEFORE CLOSE PROJECT
#include <stdio.h>
#include <fcntl.h>

int		get_next_line(int fd, char **line);
size_t	ft_strlen(char *s);
size_t	ft_slen(char *s);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	ft_sch(char *s);
char	*ft_strchr(const char *s, int c);
#endif
