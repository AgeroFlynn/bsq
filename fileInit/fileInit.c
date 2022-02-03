/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileInit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 18:38:53 by wbernard          #+#    #+#             */
/*   Updated: 2021/06/30 23:04:39 by wbernard         ###   ########.fr       */
/*   Updated: 2021/06/29 12:09:26 by kforge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fileInit.h"

int	ft_open(char *name)
{
	int	handle;

	handle = open(name, O_RDONLY);
	if (handle == -1)
		ft_puts("map error");
	return (handle);
}

int	initFirstLine(char **buffer, int handle, int first)
{
	int	bytesCurrent;

	*buffer = (char *) malloc(sizeof(char) * first);
	if (!*buffer)
	{
		ft_puts("map error");
		return (-1);
	}
	bytesCurrent = read(handle, *buffer, first);
	if (bytesCurrent == -1)
	{
		ft_puts("map error");
		free(buffer);
		return (-1);
	}
	return (1);
}

int	initSecondLine(t_map *current, int handle, int second)
{
	int		bytesCurrent;
	char	*buffer;

	buffer = (char *) malloc(sizeof(char) * second);
	if (!buffer)
	{
		ft_puts("map error");
		return (-1);
	}
	bytesCurrent = read(handle, buffer, second);
	buffer[second - 1] = 0;
	widthInit(current, second);
	if (checkLine(buffer, current->width, current) == -1)
	{
		free(buffer);
		return (-1);
	}
	if (pushLine(current, buffer, 0) == -1)
	{
		free(buffer);
		return (-1);
	}
	return (1);
}

int	mapInit(t_map **current, char *buffer)
{
	char	*i;
	char	empty;

	i = buffer;
	while (*i != '\n')
		i++;
	empty = *(i - 3);
	*(i - 3) = 0;
	if (!ft_str_is_numeric(buffer))
	{
		ft_puts("map error");
		free(buffer);
		return (-1);
	}
	*current = createMap(empty, *(i - 1), *(i - 2), ft_atoi(buffer));
	if (!*current)
	{
		ft_puts("map error");
		free(buffer);
		return (-1);
	}
	free(buffer);
	return (1);
}

int	fileInit(char *name, t_map **current)
{
	int		handle;
	char	*buffer;
	int		first;
	int		second;

	first = 0;
	if (getLineLength(&first, &second, name) == -1)
		return (-1);
	handle = ft_open(name);
	if (initFirstLine(&buffer, handle, first) == -1)
		return (-1);
	if (mapInit(current, buffer) == -1)
		return (-1);
	if (initSecondLine(*current, handle, second) == -1)
	{
		freeMap(current);
		return (-1);
	}
	if (initTab(*current, handle) == -1)
	{
		freeMap(current);
		return (-1);
	}
	close(handle);
	return (1);
}
