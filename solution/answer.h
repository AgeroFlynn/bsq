#ifndef ANSWER_H
# define ANSWER_H
# include "../mapStruct.h"
# include <stdio.h>

typedef struct s_answer
{
	int	temp;
	int	size;
	int	*range;
	int	x;
	int	y;
	int	max;
}	t_answer;

int			minPlusOne(int a, int b, int c);

void		findAnswer(t_map *current, t_answer *solut, int i, int j);

void		firstLine(t_map *current, t_answer *solut);

t_answer	*answerInit(t_map *current);

t_answer	*solve(t_map *current);

void		putFullCharacters(t_map *current);

void		nextLine(t_map *current, t_answer *solut, int i);

#endif
