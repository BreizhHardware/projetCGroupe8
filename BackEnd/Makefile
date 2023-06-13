CC=gcc
CFLAGS= -Wall
DEBUG=-fsanitize=address -g

SRC = Filmotheque.c main.c Movie.c NodeTrie.c List.c
OBJ = ${SRC:.c=.o}
DEP = ${SRC:.c=.d}

-include ${DEP}

all: ${OBJ}
	${CC} ${CFLAGS} ${OBJ} -o Filmotheque
	rm -f requests* results* ready*

debug: ${SRC}
	${CC} ${CFLAGS} ${DEBUG} ${SRC} -o Filmotheque
	rm -f requests* results* ready*

main: ${OBJ}


clean:
	rm -f ${OBJ} ${DEP} Filmotheque
