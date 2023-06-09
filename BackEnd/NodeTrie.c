#define MAX_LETTERS 26

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

void insertWord(struct NodeTrie* trie, char* word){
    int n = strlen(word);
    for(int i = 0; i<n; i++){
        if(trie -> children[word[i]-'a'] == NULL){
            trie -> children[word[i]-'a'] = createEmptyNodeTrie();
        }
        trie = trie -> children[word[i]-'a'];
    }
    trie -> isName = true;
}

void deleteWord(struct NodeTrie* trie, char* word){
    int n = strlen(word);
    for(int i = 0; i<n; i++){
        if(trie -> children[word[i]-'a']!=NULL){
            trie = trie -> children[word[i]-'a'];
        }
    }
    trie -> isName = false;
}

bool findWord(struct NodeTrie* trie, char* word){
    int n = strlen(word);
    for(int i = 0; i<n; i++){
        if(trie -> children[word[i]-'a'] == NULL){
            return false;
        }
    }
    return true;
}

void deleteNodeTrie(struct NodeTrie** trie){
    for(int i = 0; i<MAX_LETTERS; i++){
        if((*trie)->children[i]!=NULL){
            deleteNodeTrie(&(*trie)->children[i]);
        }
    }
    free(*trie);
    *trie = NULL;
}
