#include "answer.h"

int	minPlusOne(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (a + 1);
	if (b <= a && b <= c)
		return (b + 1);
	if (c <= a && c <= b)
		return (c + 1);
	return (0);
}

void	findAnswer(t_map *current, t_answer *solut, int i, int j)
{
	int	result;

	if (current->map[i][j] == current->obstacle)
		result = 0;
	else
		result = minPlusOne(solut->temp, solut->range[j - 1], solut->range[j]);
	if (result > solut->max)
	{
		solut->x = j;
		solut->y = i;
		solut->max = result;
	}
	solut->range[j - 1] = solut->temp;
	solut->temp = result;
}

t_answer	*answerInit(t_map *current)
{
	t_answer	*this;

	this = (t_answer *) malloc(sizeof(*this));
	if (!this)
		return (NULL);
	this->size = current->width - 1;
	this->temp = 0;
	this->x = 0;
	this->y = 0;
	this->max = 0;
	this->range = (int *)malloc(sizeof(int) * this->size);
	if (!(this->range))
		return (NULL);
	return (this);
}

void	firstLine(t_map *current, t_answer *solut)
{
	int	i;

	i = 0;
	while (i < solut->size)
	{
		if (current->map[0][i] == current->empty)
		{
			solut->range[i] = 1;
			if (solut->range[i] > solut->max)
			{
				solut->max = 1;
				solut->x = i;
			}
		}
		else
			solut->range[i] = 0;
		i++;
	}
}
