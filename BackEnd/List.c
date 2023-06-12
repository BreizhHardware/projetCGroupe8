//
// Created by felix on 27/01/23.
//

#include "List.h"

struct Cell* createCell(char* director, char* name, char* time, char* category){
    struct Cell* cell = malloc(sizeof(struct Cell));
    if(cell == NULL){
        printf("error malloc");
        return NULL;
    }
    cell->director = malloc(sizeof(char) * (strlen(director) + 1));
    cell->name = malloc(sizeof(char) * (strlen(name) + 1));
    cell->time = malloc(sizeof(char) * (strlen(time) + 1));
    cell->category = malloc(sizeof(char) * (strlen(category) + 1));
    strcpy(cell->director, director);
    strcpy(cell->name, name);
    strcpy(cell->time, time);
    strcpy(cell->category, category);
    cell->next = NULL;
    return cell;
}

struct List* createEmptyList(){
    struct List* list = malloc(sizeof(struct List));
    if(list == NULL){
        printf("error malloc");
        return NULL;
    }
    list->size = 0;
    list->head = NULL;
    return list;
}

void addFirst(struct List* l, char* director, char* name, char* time, char* category){
    struct Cell* cell = createCell(director, name, time, category);
    if(l->head == NULL){
        l->head = cell;
    }
    else{
        cell->next = l->head;
        l->head = cell;
    }
    l->size++;
}

bool isListEmpty(struct List* l){
    return l->size == 0;
}

void deleteFirst(struct List* l){
    if(l->head != NULL){
        struct Cell* tmp = l->head;
        l->head = l->head->next;
        free(tmp);
        l->size--;
    }
}

void deleteList(struct List** l){
    while(!isListEmpty(*l)){
        deleteFirst(*l);
    }
    free(*l);
    *l = NULL;
}

void printList(struct List* l){
    struct Cell* tmp = l->head;
    while(tmp != NULL){
        printf("%s %s %s %s\n", tmp->director, tmp->name, tmp->time, tmp->category);
        tmp = tmp->next;
    }
}