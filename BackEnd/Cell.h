//
// Created by felix on 20/01/23.
//

#ifndef _CELL_H
#define _CELL_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

//Structure à utiliser

struct Cell{
    int value;
    struct Cell* next;
};

struct Cell* createCell(int val);
struct Cell* addFirst(struct Cell* head, int value);
bool isListEmpty(struct Cell* head);
int getItemPos(struct Cell* head, unsigned int position, bool* valid);
struct Cell* deleteFirst(struct Cell* head);
void printList(struct Cell* head);
unsigned int listSize(struct Cell* head);
struct Cell* addItemPos(struct Cell* head, int val, unsigned int pos, bool* valid);
struct Cell* deleteItemPos(struct Cell* head, unsigned int pos, bool* valid);
void deleteAll(struct Cell** head);
struct Cell* createListFromArray(int A[], unsigned int size);
struct Cell* belongs(struct Cell* head, int value);

#endif //_CELL_H
