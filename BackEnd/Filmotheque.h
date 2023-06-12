#ifndef PROJETCGROUPE8_MAIN_FILMOTHEQUE_H
#define PROJETCGROUPE8_MAIN_FILMOTHEQUE_H

#include "NodeTrie.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

struct Filmotheque{
    char* realMax;
    int maxMovies;
    struct NodeTrie* director;
};

struct Filmotheque* createEmptyFilmotheque();
void addMovie(struct Filmotheque* filmotheque, char* real, char* movie, char* time, char* category);
struct List* searchByDirector(struct Filmotheque* filmotheque, char* director);

#endif //PROJETCGROUPE8_MAIN_FILMOTHEQUE_H
