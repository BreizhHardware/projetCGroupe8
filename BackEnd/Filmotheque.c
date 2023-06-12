#include "Filmotheque.h"

struct Filmotheque* createEmptyFilmotheque(){
    struct Filmotheque* filmotheque = malloc(sizeof(struct Filmotheque));
    filmotheque->Real = createEmptyNodeTrie();
    filmotheque->realMax = NULL;
    filmotheque->maxMovies = 0;
    return filmotheque;
}

void addMovie(struct Filmotheque* filmotheque, char* real, char* movie, char* time, char* category){
    struct NodeTrie* node = filmotheque->Real;
    for(int i = 0; i < strlen(real); i++){
        if(node->children[real[i] - 'a'] == NULL){
            node->children[real[i] - 'a'] = createEmptyNodeTrie();
        }
        node = node->children[real[i] - 'a'];
    }
    if(node->isName){
        addFirst(node->movie, real, movie, time, category);
    }
    else{
        node->isName = true;
        node->movie = createEmptyList();
        addFirst(node->movie, real, movie, time, category);
    }
}

struct List* searchByDirector(struct Filmotheque* filmotheque, char* director){
    struct List* list = createEmptyList();
    struct NodeTrie* node = filmotheque->Real;
    for(int i = 0; i < strlen(director); i++){
        if(node->children[director[i] - 'a'] == NULL){
            return list;
        }
        node = node->children[director[i] - 'a'];
    }
    if(node->isName){
        for(int i = 0; i < listSize(node->movie); i++){
            addFirst(list, node->movie->head->director, node->movie->head->name, node->movie->head->time, node->movie->head->category);
            deleteFirst(node->movie);
        }
    }
    return list;
}

