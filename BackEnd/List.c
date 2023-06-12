//
// Created by felix on 27/01/23.
//

#include "list.h"

struct Cell* createCell(char *director, char *name, char *time, char *category) {
    printf("%s\n", name);
    struct Cell* cell = malloc(sizeof(struct Cell));
    cell->director = director;
    cell->name = name;
    cell->time = time;
    cell->category = category;
    cell->next = NULL;
    printf("%s\n", cell->name);
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
    printf("%s\n", l->head->name);
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
    while(l->head != NULL){
        printf("%s\n", l->head->name);
        printf("%s, %s, %s, %s\n", l->head->director, l->head->name, l->head->time, l->head->category);
        l->head = l->head->next;
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
