NAME = a.out

SRC = gnl.c

GCC = gcc -g -Wall -Werror -Wextra

RM = rm -f

#BUFFER_SIZE = BUFFER_SIZE=10

all: ${NAME}

#${GCC} -o ${NAME} ${SRC}
#${GCC} -o ${NAME} ${SRC} -D ${BUFFER_SIZE}
$(NAME):
	${GCC} -o ${NAME} ${SRC}
	#${GCC} -o ${NAME} ${SRC} -D ${BUFFER_SIZE}

clean:
	${RM} *.o

fclean: clean
	${RM} ${NAME}

re: fclean all