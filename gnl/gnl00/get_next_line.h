#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlen(char *s);
char	*ft_strjoi(char *s1, char *s2, size_t s2len);
int		ft_index(char *s, char c);
void	zeroer(char **ptr);
void	freenator(char **ptr);
void	buf_change(char *ptr);
void	next_line(char *bf, char **line, int fd, int *ret);
int		get_next_line(int fd, char **line);
void	*ft_memset(void *b, int c, size_t len);

#endif