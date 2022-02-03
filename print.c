#include "mapStruct.h"

void	printMap(t_map *current)
{
	int	i;

	i = 0;
	while (current->map[i])
	{
		write(1, current->map[i++], sizeof(char) * (current->width - 1));
		write(1, "\n", 1);
	}
}
