#include "./fileInit/fileInit.h"
#include "mapStruct.h"
#include "./solution/answer.h"

int	initStandartFirstLine(char buffer[128], int handle)
{
	int	iterator;
	int	bytesCurrent;

	bytesCurrent = 1;
	iterator = 0;
	while (bytesCurrent)
	{
		bytesCurrent = read(handle, &buffer[iterator], sizeof(char));
		if (bytesCurrent == -1)
		{
			ft_puts("map error");
			return (-1);
		}
		if (buffer[iterator] == '\n')
			break ;
		iterator++;
	}
	if (!bytesCurrent)
	{
		ft_puts("map error");
		return (-1);
	}
	return (1);
}

int	initStandartSecondLine(t_map *current, int handle)
{
	char	buffer[819200];
	int		bytesCurrent;
	int		iterator;

	bytesCurrent = 1;
	iterator = 0;
	while (bytesCurrent || bytesCurrent == -1)
	{
		bytesCurrent = read(handle, &buffer[iterator], sizeof(char));
		if (buffer[iterator] == '\n')
			break ;
		iterator++;
	}
	if (!bytesCurrent && bytesCurrent == -1)
	{
		ft_puts("map error");
		return (-1);
	}
	buffer[iterator] = 0;
	widthInit(current, ++iterator);
	if (copyBuffer(buffer, iterator, current, 0) == -1)
		return (-1);
	return (1);
}

int	mapStandartInit(t_map **current, char buffer[128])
{
	char	*i;
	char	empty;
	char	full;
	char	obstacle;
	int		height;

	i = buffer;
	while (*i != '\n')
		i++;
	empty = *(i - 3);
	full = *(i - 1);
	obstacle = *(i - 2);
	*(i - 3) = 0;
	height = ft_atoi(buffer);
	*current = createMap(empty, full, obstacle, height);
	if (!*current)
	{
		ft_puts("map error");
		return (-1);
	}
	return (1);
}

int	standartInputInit(t_map **current)
{
	char	buffer[128];

	if (initStandartFirstLine(buffer, 0) == -1)
		return (-1);
	if (mapStandartInit(current, buffer) == -1)
		return (-1);
	if (initStandartSecondLine(*current, 0) == -1)
	{
		freeMap(current);
		return (-1);
	}
	if (initTab(*current, 0) == -1)
	{
		freeMap(current);
		return (-1);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_map	*map;
	int		i;

	map = NULL;
	if (argc == 1)
	{
		standartInputInit(&map);
		if (map)
		{
			putFullCharacters(map);
			return (0);
		}
	}
	i = 1;
	while (i < argc)
	{
		if (fileInit(argv[i], &map) == -1)
			map = NULL;
		if (map)
			putFullCharacters(map);
		if (i != argc - 1)
			write(1, "\n", 1);
		i++;
	}
	return (0);
}
