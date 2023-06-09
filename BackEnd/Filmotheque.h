#ifndef PROJETCGROUPE8_MAIN_FILMOTHEQUE_H
#define PROJETCGROUPE8_MAIN_FILMOTHEQUE_H

#include "NodeTrie.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

struct Filmotheque{
    char* realMax;
    int maxMovies;
    struct NodeTrie* Real;
};

#endif //PROJETCGROUPE8_MAIN_FILMOTHEQUE_H
