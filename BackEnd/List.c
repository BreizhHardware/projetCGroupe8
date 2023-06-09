//
// Created by felix on 27/01/23.
//

#include "list.h"

struct Cell* createCell(int val){
    struct Cell* cell = malloc(sizeof(struct Cell));
    cell->value = val;
    cell->next = NULL;
    return cell;
}

struct List* createEmptyList(){
    struct List* l = malloc(sizeof(struct List));
    l->size = 0;
    l->head = NULL;
    return l;
}

void addFirst(struct List* l, int value){
    struct Cell* cell = createCell(value);
    cell->next = l->head;
    l->head = cell;
    l->size++;
}

bool isListEmpty(struct List* l){
    return l->head == NULL;
}

int getItemPos(struct List* l, unsigned int position, bool* valid){
    if(isListEmpty(l)){
        *valid = false;
        return 0;
    }
    if(position == 0){
        *valid = true;
        return l->head->value;
    }
    unsigned int n = listSize(l);
    struct Cell* head = l->head;
    for(int i = 0; i < n; i++){
        if(i == position){
            *valid = true;
            return head->value;
        }
        head = head->next;
    }
    *valid = false;
    return 0;
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

void printList(struct List* l){
    if(isListEmpty(l)){
        printf("Liste vide\n");
        return;
    }
    struct Cell* head = l->head;
    while(head != NULL){
        printf(" -> ");
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

unsigned int listSize(struct List* l){
    return l->size;
}

void addItemPos(struct List* l, int value, unsigned int position, bool* valid){
    if(position == 0){
        addFirst(l, value);
        *valid = true;
        return;
    }
    unsigned int n = listSize(l);
    if(position > n){
        *valid = false;
        return;
    }
    struct Cell* head = l->head;
    for(int i = 0; i < n; i++){
        if(i == position - 1){
            struct Cell* cell = createCell(value);
            cell->next = head->next;
            head->next = cell;
            l->size++;
            *valid = true;
            return;
        }
        head = head->next;
    }
}

void deleteItemPos(struct List* l, unsigned int position, bool* valid){
    if(position == 0){
        deleteFirst(l);
        *valid = true;
        return;
    }
    unsigned int n = listSize(l);
    if(position > n){
        *valid = false;
        return;
    }
    struct Cell* head = l->head;
    for(int i = 0; i < n; i++){
        if(i == position - 1){
            struct Cell* next = head->next->next;
            free(head->next);
            head->next = next;
            l->size--;
            *valid = true;
            return;
        }
        head = head->next;
    }
}

void deleteList(struct List** l){
    while(!isListEmpty(*l)){
        deleteFirst(*l);
    }
    free(*l);
    *l = NULL;
}

struct List* createListFromArray(int A[], unsigned int size){
    struct List* l = createEmptyList();
    for(int i = 0; i < size; i++){
        addFirst(l, A[i]);
    }
    return l;
}

struct Cell* belongs(struct List* l, int value){
    struct Cell* head = l->head;
    while(head != NULL){
        if(head->value == value){
            return head;
        }
        head = head->next;
    }
    return NULL;
}

void reverse(struct List* l){
    struct Cell* head = l->head;
    struct Cell* prev = NULL;
    struct Cell* next = NULL;
    while(head != NULL){
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    l->head = prev;
}