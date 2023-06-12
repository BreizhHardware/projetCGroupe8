//
// Created by felix on 27/01/23.
//

#include "list.h"

struct Cell* createCell(char *director, char *name, char *time, char *category) {
    struct Cell* cell = malloc(sizeof(struct Cell));
    cell->director = director;
    cell->name = name;
    cell->time = time;
    cell->category = category;
    cell->next = NULL;
    return cell;
}

struct List* createEmptyList(){
    struct List* l = malloc(sizeof(struct List));
    l->size = 0;
    l->head = NULL;
    return l;
}

void addFirst(struct List* l, char* director, char* name, char* time, char* category){
    struct Cell* cell = createCell(director, name, time, category);
    cell->next = l->head;
    l->head = cell;
    l->size++;
}

bool isListEmpty(struct List* l){
    return l->head == NULL;
}
void deleteFirst(struct List* l) {
    if (isListEmpty(l)) {
        return;
    }
    struct Cell *next = l->head->next;
    free(l->head);
    l->head = next;
    l->size--;
}

unsigned int listSize(struct List* l){
    return l->size;
}

void deleteList(struct List** l){
    while(!isListEmpty(*l)){
        deleteFirst(*l);
    }
    free(*l);
    *l = NULL;
}

void printList(struct List* l){
    if(isListEmpty(l)){
        printf("Liste vide\n");
        return;
    }
    struct Cell* current = l->head;
    while(current != NULL){
        printf("%s, %s, %s, %s\n", current->director, current->name, current->time, current->category);
        current = current->next;
    }
    printf("\n");
}

struct List* copyList(struct List* l){
    struct List* copy = createEmptyList();
    struct Cell* current = l->head;
    while(current != NULL){
        addFirst(copy, current->director, current->name, current->time, current->category);
        current = current->next;
    }
    return copy;
}