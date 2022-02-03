#ifndef MAPSTRUCT_H
# define MAPSTRUCT_H
# include <stdlib.h>
# include "./stringLib/ft_strlib.h"
# include <stdio.h>

typedef struct s_map
{
	char	empty;
	char	full;
	char	obstacle;
	int		height;
	int		width;
	char	**map;
}	t_map;

void	putLine(char *line);

void	printMap(t_map *current);

int		pushLine(t_map *current, char *line, int i);

int		widthInit(t_map *current, int width);

t_map	*createMap(char empty, char full, char obstacle, int height);

int		freeLine(t_map *current, int i);

int		freeMap(t_map **current);

#endif
