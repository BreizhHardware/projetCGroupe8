//
// Created by felix on 27/01/23.
//

#ifndef _LIST_H
#define _LIST_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct Cell{
    int value;
    struct Cell* next;
};
struct List{
    unsigned int size;
    struct Cell* head;
};

struct Cell* createCell(int val);
struct List* createEmptyList();
void addFirst(struct List* l, int value);
bool isListEmpty(struct List* l);
int getItemPos(struct List* l, unsigned int position, bool* valid);
void deleteFirst(struct List* l);
void printList(struct List* l);
unsigned int listSize(struct List* l);
void addItemPos(struct List* l, int value, unsigned int position, bool* valid);
void deleteItemPos(struct List* l, unsigned int position, bool* valid);
void deleteList(struct List** l);
struct List* createListFromArray(int A[], unsigned int size);
struct Cell* belongs(struct List* l, int value);
void reverse(struct List* l);
#endif //_LIST_H
