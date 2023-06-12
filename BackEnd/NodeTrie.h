#ifndef PROJETCGROUPE8_MAIN_NODETRIE_H
#define PROJETCGROUPE8_MAIN_NODETRIE_H

#define MAX_LETTERS 29

#include "List.h"
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

struct NodeTrie{
    struct NodeTrie* children[MAX_LETTERS];
    bool isName;
    struct List* movie;
};

struct NodeTrie* createEmptyNodeTrie();

void deleteNodeTrie(struct NodeTrie** trie);

#endif //PROJETCGROUPE8_MAIN_NODETRIE_H
