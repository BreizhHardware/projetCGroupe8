#define MAX_LETTERS 29

#include "NodeTrie.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

//Fonction qui permet de créer un NodeTrie vide
struct NodeTrie* createEmptyNodeTrie(){
    struct NodeTrie* trie = malloc(sizeof(struct NodeTrie));
    if(trie == NULL){
        printf("error malloc");
        return NULL;
    }
    //MAX_LETTERS vaut 29 pour contenir tout l'alphabet + '\'' + '-' + ' '
    for(int i = 0; i < MAX_LETTERS; i++){
        trie -> children[i] = NULL;     //On remplie un node trie de c'est 29 enfant, qu'on initialise a NULL
    }
    trie -> isName = false;     //Ca ne correspond pas à un prénom donc on met a false
    return trie;
}

//Fonction qui permet de supprimer un NodeTrie
void deleteNodeTrie(struct NodeTrie** trie){
    //On boucle pour parcourir tout les enfant non NULL
    for(int i = 0; i<MAX_LETTERS; i++){
        if((*trie)->children[i]!=NULL){
            deleteNodeTrie(&(*trie)->children[i]);  //On opère de façon récursive 
        }
    }
    deleteList(&(*trie)->movie);    //Supprime les list contenu dans une node
    free(*trie);    //On libère la mémoire du trie, donc on le "supprime"
    *trie = NULL;   
}
