NAME = rush-02

SRC = main.c functions/*.c

HDR = include/

CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

${NAME}:
	gcc ${CFLAGS} -o ${NAME} -I ${HDR} ${SRC}

noflag:
	gcc -o ${NAME} -I ${HDR} ${SRC}

test: noflag
	./${NAME} 987654
	./${NAME} -4315
	./${NAME} "  	+100001"
	./${NAME} 0
	./${NAME} 4294967295
	./${NAME} aa45

clean:


fclean: clean
	rm -f ${NAME}

re: fclean all
