#ifndef PROJETCGROUPE8_MAIN_FILMOTHEQUE_H
#define PROJETCGROUPE8_MAIN_FILMOTHEQUE_H
#define NUMBER_OF_CHAR 100


#include "NodeTrie.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>


struct Filmotheque{
    struct List* realMax;
    int maxMovies;
    struct NodeTrie* director;
};

struct Filmotheque* createEmptyFilmotheque();
void addMovie(struct Filmotheque* filmotheque, char* real, char* movie, char* time, char* category);
struct List* searchByDirector(struct Filmotheque* filmotheque, char* director);
void deleteFilmotheque(struct Filmotheque** filmotheque);
struct Filmotheque* recupInfo(char* nameFile);
char* toLower(char* name);

#endif //PROJETCGROUPE8_MAIN_FILMOTHEQUE_H
