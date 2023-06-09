//
// Created by felix on 20/01/23.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "cell.h"

struct Cell* createCell(int val){
    struct Cell* cell = malloc(sizeof(struct Cell));
    cell->value = val;
    cell->next = NULL;
    return cell;
}

struct Cell* addFirst(struct Cell* head, int value){
    struct Cell* cell = createCell(value);
    cell->next = head;
    return cell;
}

bool isListEmpty(struct Cell* head){
    return head == NULL;
}

int getItemPos(struct Cell* head, unsigned int position, bool* valid){
    if(isListEmpty(head)){
        *valid = false;
        return 0;
    }
    if(position == 0){
        *valid = true;
        return head->value;
    }
    return getItemPos(head->next, position-1, valid);
}

struct Cell* deleteFirst(struct Cell* head){
    if(isListEmpty(head)){
        return NULL;
    }
    struct Cell* next = head->next;
    free(head);
    return next;
}

void printList(struct Cell* head){
    if(isListEmpty(head)){
        printf("Liste vide\n");
        return;
    }
    printf("%d", head->value);
    if(head->next != NULL){
        printf(" -> ");
        printList(head->next);
    }
    else{
        printf("\n");
    }
}

unsigned int listSize(struct Cell* head){
    if(isListEmpty(head)){
        return 0;
    }
    return 1 + listSize(head->next);
}

struct Cell* addItemPos(struct Cell* head, int val, unsigned int pos, bool* valid){
    if(pos == 0){
        *valid = true;
        return addFirst(head, val);
    }
    if(isListEmpty(head)){
        *valid = false;
        return NULL;
    }
    head->next = addItemPos(head->next, val, pos-1, valid);
    return head;
}

struct Cell* deleteItemPos(struct Cell* head, unsigned int pos, bool* valid){
    if(isListEmpty(head)){
        *valid = false;
        return NULL;
    }
    if(pos == 0){
        *valid = true;
        return deleteFirst(head);
    }
    head->next = deleteItemPos(head->next, pos-1, valid);
    return head;
}

void deleteAll(struct Cell** head){
    if(*head == NULL){
        free(*head);
        return;
    }
    if(listSize(*head) == 1){
        free(*head);
        *head = NULL;
        return;
    }
    if(isListEmpty(*head)){
        return;
    }
    deleteAll(&((*head)->next));
    free(*head);
    *head = NULL;
}

struct Cell* createListFromArray(int A[], unsigned int size){
    struct Cell* head = NULL;
    for(int i = size-1; i >= 0; i--){
        head = addFirst(head, A[i]);
    }
    return head;
}


struct Cell* belongs(struct Cell* head, int value){
    if(isListEmpty(head)){
        return NULL;
    }
    if(head->value == value){
        return head;
    }
    return belongs(head->next, value);
}