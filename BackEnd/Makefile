CC=gcc -fsanitize=address
CPPFLAGS= -MMD -D_XOPEN_SOURCE=500
CFLAGS= -Wall -std=c11 -O2
DEBUG=-fsanitize=address -g

SRC = Filmotheque.c main.c Movie.c NodeTrie.c List.c
OBJ = ${SRC:.c=.o}
DEP = ${SRC:.c=.d}

-include ${DEP}

all: ${OBJ}
	${CC} ${CFLAGS} ${OBJ} -o Filmotheque

debug: ${SRC}
	${CC} ${CFLAGS} ${DEBUG} ${SRC} -o Filmotheque

main: ${OBJ}


clean:
	rm -f ${OBJ} ${DEP} Filmotheque
