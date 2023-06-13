//création include
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include"List.h"
#include "Movie.h"

//opération sur la struct
struct Cell* createCell(struct Movie* movie) {
    struct Cell *cell = malloc(sizeof(struct Cell));
    if (cell == NULL) {
        printf("error malloc");
        return NULL;
    }
    cell->movie = movie;
    cell->next = NULL;
    return cell;
}

struct List * createEmptyList(){
    struct List* l = malloc(sizeof(struct List));
    l->size = 0;
    l->head = NULL;
    return l;
}

void addFirst(struct List* l,struct Movie* movie){
    struct Cell* cell = createCell(movie);
    if(l->head == NULL){
        l->head = cell;
    }
    else{
        cell->next = l->head;
        l->head = cell;
    }
    l->size++;
}


void deleteFirst(struct List* l) {
    if (isCellEmpty(l->head)) {
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
    //Use isCellEmpty to check if the cell is empty
    while(!isCellEmpty((*l)->head)){
        deleteFirst(*l);
    }
    free(*l);
    *l = NULL;
}

bool isCellEmpty(struct Cell* c){
    if(c -> movie == NULL){
        return true;
    }
    return false;
}

struct List* copyList(struct List* l){
    struct List* copy = createEmptyList();
    struct Cell* current = l->head;
    while(current != NULL){
        addFirst(copy,current->movie);
        current = current->next;
    }
    return copy;
}

void printList(struct List* l){
    struct Cell* tmp = l->head;
    while(tmp != NULL){
        printf("%s %s %s %s\n", tmp->movie->director,tmp->movie->name,tmp->movie->time,tmp->movie->category);
        tmp = tmp->next;
    }
}
