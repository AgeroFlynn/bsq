#include "ft_strlib.h"

int	ft_is_numeric(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_is_printable(char c)
{
	if (c <= '~' && c >= ' ')
		return (1);
	return (0);
}

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\v')
		return (1);
	if (c == '\f' || c == '\r' || c == '\t')
		return (1);
	return (0);
}

int	ft_str_is_numeric(char *str)
{
	char	*s;

	s = str;
	while (*s)
		if (!ft_is_numeric(*s++))
			return (0);
	return (1);
}
