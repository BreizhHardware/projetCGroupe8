#ifndef PROJETCGROUPE8_MAIN_LIST_H
#define PROJETCGROUPE8_MAIN_LIST_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

struct Cell{
    struct Movie* movie;
    struct Cell* next;
};

struct List{
    int size;
    struct Cell* head;
};

struct Cell* createCell(struct Movie* movie);

struct List* createEmptyList();

void addFirst(struct List* l,struct Movie* movie);

bool isCellEmpty(struct Cell* c);

void deleteFirst(struct List* l);

unsigned int listSize(struct List* l);

void deleteList(struct List** l);

struct List* copyList(struct List* l);

void printList(struct List* l);


#endif //PROJETCGROUPE8_MAIN_LIST_H