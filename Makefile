SRCS	=	fileInit/fileFunctions.c\
			fileInit/fileInit.c\
			main.c\
			mapStruct.c\
			mathLib/ft_atoi.c\
			print.c\
			stringLib/ft_strlib.c\
			stringLib/ft_strlib_2.c\
			solution/answer.c\
			solution/answer_2.c

OBJS	= ${SRCS:.c=.o}

RM		= rm -f

MAP		= mapGenerator.pl 250 250 3 > ./maps/200MAP

NAME	= bsq

GCC		= gcc

FLAGS	= -Wall -Werror -Wextra

all:		${NAME}

map:		
			${MAP}

${NAME}:	${OBJS}
			${GCC} ${FLAGS} -o ${NAME} ${OBJS}

%.o:		%.c
			${GCC} ${FLAGS} -c $< -o $@

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

.PHONY:		all clean fclean
