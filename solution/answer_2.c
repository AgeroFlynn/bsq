#include "answer.h"

void	nextLine(t_map *current, t_answer *solut, int i)
{
	int	j;

	j = 1;
	if (current->map[i][0] == current->obstacle)
		solut->temp = 0;
	else
	{
		solut->temp = 1;
		if (solut->temp > solut->max)
		{
			solut->max = solut->temp;
			solut->y = i;
			solut->x = 0;
		}
	}
	while (j < solut->size)
		findAnswer(current, solut, i, j++);
	solut->range[--j] = solut->temp;
}

t_answer	*solve(t_map *current)
{
	t_answer	*solut;
	int			i;

	solut = answerInit(current);
	firstLine(current, solut);
	i = 1;
	while (i < current->height)
		nextLine(current, solut, i++);
	return (solut);
}

void	putFullCharacters(t_map *current)
{
	t_answer	*solut;
	int			i;
	int			j;

	solut = solve(current);
	if (!solut->max)
	{
		printMap(current);
		free(solut->range);
		free(solut);
		freeMap(&current);
		return ;
	}
	i = solut->y - solut->max + 1;
	while (i <= solut->y)
	{
		j = solut->x - solut->max + 1;
		while (j <= solut->x)
			current->map[i][j++] = current->full;
		i++;
	}
	free(solut->range);
	free(solut);
	printMap(current);
	freeMap(&current);
}
