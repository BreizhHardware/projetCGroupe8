#ifndef PROJETCGROUPE8_MAIN_CELL_H
#define PROJETCGROUPE8_MAIN_CELL_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

struct Cell{
    char* name;
    int time;
    char* categorie;
    struct Cell* next;
};

#endif //PROJETCGROUPE8_MAIN_CELL_H
