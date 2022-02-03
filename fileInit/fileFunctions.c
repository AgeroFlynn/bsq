#include "fileInit.h"

void	ft_close(int handle)
{
	ft_puts("map error");
	close(handle);
}

int	getLineLength(int *first, int *second, char *name)
{
	int		i;
	char	c;
	int		handle;
	int		bytes;

	handle = ft_open(name);
	if (handle == -1)
		return (-1);
	i = 0;
	bytes = 1;
	while (bytes != 0 && bytes != -1)
	{
		bytes = read(handle, &c, 1);
		if (c == '\n' && !*first)
			*first = i + 1;
		else if (c == '\n' && *first)
		{
			*second = i - *first + 1;
			close(handle);
			return (1);
		}
		i++;
	}
	ft_close(handle);
	return (-1);
}

int	checkLine(char *str, int length, t_map *this)
{
	char	*s;

	s = str;
	if (length != this->width)
	{
		ft_puts("map error");
		return (-1);
	}
	while (*s)
	{
		if (*s != this->empty && *s != this->obstacle)
		{
			ft_puts("map error");
			return (-1);
		}
		s++;
	}
	return (1);
}

int	copyBuffer(char *buffer, int length, t_map *current, int i)
{
	char	*line;

	line = (char *) malloc(sizeof(*line) * (length + 1));
	if (!line)
	{
		ft_puts("map error");
		return (-1);
	}
	ft_strcpy(line, buffer);
	if (checkLine(line, length, current) == -1)
	{
		free(line);
		return (-1);
	}
	if (pushLine(current, line, i) == -1)
	{
		free(line);
		return (-1);
	}
	return (1);
}

int	initTab(t_map *current, int handle)
{
	char	*buffer;
	int		bytes;
	int		i;

	buffer = (char *) malloc(sizeof(*buffer) * current->width);
	bytes = 1;
	i = 1;
	while (bytes)
	{
		bytes = read(handle, buffer, sizeof(char) * current->width);
		if ((i == current->height && bytes) || (i < current->height && !bytes))
		{
			ft_puts("map error");
			free(buffer);
			return (-1);
		}
		buffer[current->width - 1] = 0;
		if (bytes && (copyBuffer(buffer, current->width, current, i++) == -1))
		{
			free(buffer);
			return (-1);
		}
	}
	free(buffer);
	return (1);
}
