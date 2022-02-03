#include "ft_strlib.h"

int	ft_strcmp(char *left, char *right)
{
	char	*l;
	char	*r;

	l = left;
	r = right;
	while (*l == *r++)
		if (*l++ == 0)
			return (0);
	return (*l - *(r - 1));
}

void	ft_puts(char *str)
{
	char	*s;

	s = str;
	while (*s)
		write(2, s++, 1);
	write(2, "\n", 1);
}

char	*ft_strcpy(char *dest, char *src)
{
	char	*d;
	char	*s;

	d = dest;
	s = src;
	while (*s)
		*d++ = *s++;
	*d = 0;
	return (dest);
}

int	ft_strlen(char *str)
{
	char	*s;

	s = str;
	while (*s)
		s++;
	return (s - str - 1);
}

void	ft_strrev(char *str)
{
	char	temp;
	int		i;
	int		length;

	i = 0;
	length = ft_strlen(str);
	while (i <= length / 2)
	{
		temp = str[i];
		str[i] = str[length - i];
		str[length - i] = temp;
		i++;
	}
}
