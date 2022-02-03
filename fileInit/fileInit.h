#ifndef FILEINIT_H
# define FILEINIT_H

# include <fcntl.h>
# include "../stringLib/ft_strlib.h"
# include "../mapStruct.h"
# include "../mathLib/mathLib.h"
# include <stdio.h>

int		getLineLength(int *first, int *second, char *name);

int		initTab(t_map *current, int handle);

int		checkLine(char *str, int length, t_map *this);

int		copyBuffer(char *buffer, int length, t_map *current, int i);

int		fileInit(char *name, t_map **current);

int		mapInit(t_map **current, char buffer[128]);

int		initSecondLine(t_map *current, int handle, int second);

int		initFirstLine(char **buffer, int handle, int first);

int		ft_open(char *name);

#endif
