//
// Created by felix on 27/01/23.
//

#ifndef _LIST_H
#define _LIST_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct Cell{
    char* director;
    char* name;
    char* time;
    char* category;
    struct Cell* next;
};
struct List{
    unsigned int size;
    struct Cell* head;
};

struct Cell* createCell(char* director, char* name, char* time, char* category);
struct List* createEmptyList();
void addFirst(struct List* l, char* director, char* name, char* time, char* category);
bool isListEmpty(struct List* l);
void deleteFirst(struct List* l);
unsigned int listSize(struct List* l);
void deleteList(struct List** l);
void printList(struct List* l);
#endif //_LIST_H
