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
    struct Cell* CellToDelete = l->head;
    l->head = l->head->next;
    l->size--;
    //deleteMovie(CellToDelete->movie);
    free(CellToDelete);
    CellToDelete = NULL;
}

unsigned int listSize(struct List* l){
    if(l == NULL){
        return 0;
    }
    return l->size;
}

void deleteList(struct List** l){
    if(*l == NULL){
        return;
    }
    unsigned int size = listSize(*l);
    for(unsigned int i = 0; i < size; i++){
        deleteFirst(*l);
    }
    free(*l);
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
    if(l->size == 0){
        printf("List is empty\n");
        return;
    }
    struct Cell* tmp = l->head;
    while(tmp != NULL){
        printf("%s %s %s %s\n", tmp->movie->director,tmp->movie->name,tmp->movie->time,tmp->movie->category);
        tmp = tmp->next;
    }
}
