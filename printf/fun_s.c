#include "libftprintf.h"

void	ifs(va_list ap, int *len)
{
	char	*s;

	s = va_arg(ap, char *);
	if (s == NULL)
		ft_putstr("(null)", len);
	else
		ft_putstr(s, len);
}
