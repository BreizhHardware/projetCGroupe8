//création include
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#include"List.h"
#include "Movie.h"

//Fonction qui créer une cellule, qui prend en argument un movie
struct Cell* createCell(struct Movie* movie) {
    struct Cell *cell = malloc(sizeof(struct Cell));    //Allocation de la mémoire pour stocker la cellule
    if (cell == NULL) {
        printf("error malloc");
        return NULL;
    }
    cell->movie = movie;    //On lie la struct movie, pour pouvoir y accéder après
    cell->next = NULL;  //On initialise la cellule suivante, à NULL
    return cell;
}

//Fonction qui créer une list vide, qui va être complétée par des cellules
struct List * createEmptyList(){
    struct List* l = malloc(sizeof(struct List));   //Allocation de la mémoire pour stocker la list
    l->size = 0;    //Taille de la liste à zéro car vide
    l->head = NULL;     //La head représente la première cellule, c'est elle qui nous permet d'accéder aux autres éléments de la liste
    return l;
}

//Fonction qui permet d'ajouter à la head d'une list une cellule
void addFirst(struct List* l,struct Movie* movie){
    struct Cell* cell = createCell(movie);  //Allocation de la mémoire pour stocker la cellule
    if(l->head == NULL){    //Si la liste est vide on ajoute juste la cellule à la head
        l->head = cell;
    }
    else{   //Autrement
        cell->next = l->head; //On lie le next (cellule qui suit) à la head actuel de la liste et on met la cellule à la head
        l->head = cell;
    }
    l->size++; //On ajoute une cellule donc la taille augmente de 1
}

//Fonction qui permet de supprimer la première cellule d'une liste
void deleteFirst(struct List* l) {
    struct Cell* CellToDelete = l->head;    //On créer une cellule intermédiaire pour la sauvegarder 
    l->head = l->head->next;    //On change la head pour "supprimer" la head actuel car on ne pourra la récupérer 
    l->size--;  //On enlève un élément donc la taille diminue de 1
    //deleteMovie(CellToDelete->movie);
    free(CellToDelete);     //On libère la mémoire et on supprime donc l'ancienne head
    CellToDelete = NULL;
}

//Fonction qui renvoie la taille d'une liste
unsigned int listSize(struct List* l){
    if(l == NULL){  //Si la liste est NULL, on renvoie 0
        return 0;
    }
    return l->size;     //Dans tout les autres cas on renvoie la taille de la liste
}

//Fonction qui permet de supprimer une liste 
void deleteList(struct List** l){
    if(*l == NULL){     //Si la liste est NULL, on ne fait rien
        return;
    }
    unsigned int size = listSize(*l);   //On récupère la taille de la liste, pour pouvoir boucler et supprimer la head jusqu'a arriver à NULL
    for(unsigned int i = 0; i < size; i++){
        deleteFirst(*l);
    }
    free(*l);   //On libère la mémoire, on supprime donc la structure liste
}

//Fonction qui vérifie si une cellule est vide
bool isCellEmpty(struct Cell* c){
    if(c -> movie == NULL){     //Si il n'y a pas de movie dans la cellule, elle est considéré comme vide
        return true;
    }
    return false;
}

//Fonction qui permet de copier une liste
struct List* copyList(struct List* l){
    struct List* copy = createEmptyList();  //Créer une liste vide copy que l'on va renvoyer
    struct Cell* current = l->head;     //On se place dans la première cellule de la liste l
    while(current != NULL){     //Tant que current ne vaut pas NULL,c'est à dire la liste n'est pas vide
        addFirst(copy,current->movie);  //On ajoute chaque cellule, à la copy
        current = current->next;    //On avance dans la liste 
    }
    return copy;    //On renvoie la copy
}

//Fonction qui permet d'afficher une liste dans la console 
void printList(struct List* l){
    if(l->size == 0){   //On vérifie si la liste est vide
        printf("List is empty\n");
        return;
    }
    struct Cell* tmp = l->head;   //On se place dans la première cellule de la liste l  
    while(tmp != NULL){     //Tant que current ne vaut pas NULL,c'est à dire la liste n'est pas vide
        printf("%s %s %s %s\n", tmp->movie->director,tmp->movie->name,tmp->movie->time,tmp->movie->category);   //On print dans la console chaque info dans la cellule(director,name,time,category)
        tmp = tmp->next;    //On avance dans la liste 
    }
}
