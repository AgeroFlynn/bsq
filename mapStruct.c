#include "mapStruct.h"

t_map	*createMap(char empty, char full, char obstacle, int height)
{
	t_map	*current;

	if (!ft_is_printable(empty))
		return (NULL);
	if (!ft_is_printable(full))
		return (NULL);
	if (!ft_is_printable(obstacle))
		return (NULL);
	if (height <= 0)
		return (NULL);
	if (empty == full)
		return (NULL);
	if (full == obstacle)
		return (NULL);
	if (empty == obstacle)
		return (NULL);
	current = (t_map *) malloc(sizeof(*current));
	current->empty = empty;
	current->full = full;
	current->obstacle = obstacle;
	current->height = height;
	current->map = (char **) malloc(sizeof(char **) * (height + 1));
	return (current);
}

int	widthInit(t_map *current, int width)
{
	if (!current)
		return (-1);
	if (width <= 0)
		return (-1);
	current->width = width;
	return (1);
}

int	pushLine(t_map *current, char *line, int i)
{
	if (!current || !line)
		return (-1);
	current->map[i] = line;
	current->map[i + 1] = NULL;
	return (1);
}

int	freeMap(t_map **current)
{
	int	i;

	i = 0;
	while ((*current)->map[i])
		free((*current)->map[i++]);
	free((*current)->map);
	free(*current);
	*current = NULL;
	return (1);
}
