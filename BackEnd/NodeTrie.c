#define MAX_LETTERS 29

#include "NodeTrie.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct NodeTrie* createEmptyNodeTrie(){
    struct NodeTrie* trie = malloc(sizeof(struct NodeTrie));
    if(trie == NULL){
        printf("error malloc");
        return NULL;
    }
    for(int i = 0; i < MAX_LETTERS; i++){
        trie -> children[i] = NULL;
    }
    trie -> isName = false;
    return trie;
}


void deleteNodeTrie(struct NodeTrie** trie){
    for(int i = 0; i<MAX_LETTERS; i++){
        if((*trie)->children[i]!=NULL){
            deleteNodeTrie(&(*trie)->children[i]);
        }
    }
    deleteList(&(*trie)->movie);
    free(*trie);
    *trie = NULL;
}
