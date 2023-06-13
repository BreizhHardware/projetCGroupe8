#define LENGTH 12600
#define NUMBER_OF_CHAR 500000

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Movie.h"
#include "Filmotheque.h"
#include "NodeTrie.h"
#include "List.h"




struct Filmotheque* createEmptyFilmo(){
    struct Filmotheque* filmo = malloc(sizeof(struct Filmotheque));
    if(filmo == NULL){
        printf("error malloc");
        return NULL;
    }
    filmo -> director = createEmptyNodeTrie();
    filmo -> maxMovies = 0;
    filmo -> directorMax = NULL;
    return filmo;
}

void addMovie(struct Filmotheque* filmotheque, struct Movie* movie) {
    struct NodeTrie* node = filmotheque->director;
    char* director = movie-> director;
    for (int i = 0; i < strlen(director); i++) {
        if (director[i] == '-') {
            if (node->children[26] == NULL) {
                node->children[26] = createEmptyNodeTrie();
            }
            node = node->children[26];
        }
        else if (director[i] == '\'') {
            if (node->children[27] == NULL) {
                node->children[27] = createEmptyNodeTrie();
            }
            node = node->children[27];
        }
        else if (director[i] == ' ') {
            if (node->children[28] == NULL) {
                node->children[28] = createEmptyNodeTrie();
            }
            node = node->children[28];
        }
        else if (node->children[director[i] - 'a'] == NULL) {
            node->children[director[i] - 'a'] = createEmptyNodeTrie();
            node = node->children[director[i] - 'a'];
        }
        else if (node->children[director[i] - 'a'] == NULL) {
            node->children[director[i] - 'a'] = createEmptyNodeTrie();
            node = node->children[director[i] - 'a'];
        }
        else {
            node = node->children[director[i] - 'a'];
        }
    }

    if (node->isName) {
        addFirst(node->movie,movie);
    }
    else {
        node->isName = true;
        node->movie = createEmptyList();
        addFirst(node->movie,movie);
    }
}

struct List* addMovieInTable(struct List* table[LENGTH],struct Movie* movie){
    int realTime = atoi(movie->time);
    if(table[realTime] == NULL){
        table[realTime] = createEmptyList();
        addFirst(table[realTime],movie);
    }
    else{
        addFirst(table[realTime],movie);
    }

    return table[realTime];
}

void createTable(char* nameFile,struct List* table,struct Filmotheque* filmo){
    FILE *fichier;
    fichier = fopen(nameFile, "r");

    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier");
        exit(1);
    }


    char line[NUMBER_OF_CHAR];

    while(fgets(line,sizeof(line),fichier) != NULL){
        char* director = toLower((strtok(line, ";")));
        char* name = strtok(NULL, ";");
        char* time = strtok(NULL, ";");
        char* category = strtok(NULL, ";");
        //Remove the \r\n at the end of the line
        category[strlen(category) - 2] = '\0';
        struct Movie* movie = createMovie(director, name, time,category);
        addMovieInTable(table,movie);
        addMovie(filmo,movie);
    }
    fclose(fichier);
}

struct List* searchByDirector(struct Filmotheque* filmotheque, char* director){
    struct List* copy = createEmptyList();
    struct NodeTrie* node = filmotheque->director;
    for(int i = 0; i < strlen(director); i++){
        if(node->children[director[i] - 'a'] == NULL){
            return copy;
        }
        node = node->children[director[i] - 'a'];
    }
    if(node->isName){
        copy = copyList(node->movie);
        return copy;
    }
    return copy;
}

struct List* searchByTime(struct List* table[LENGTH], char* time){
    int realTime = atoi(time);
    return table[realTime];
}


char* toLower(char* name){
    int length = strlen(name);
    char* lower = malloc(sizeof(char) * (length + 1));
    if (lower == NULL) {
        printf("error malloc");
        return NULL;
    }
    for (int i = 0; i < length; i++) {
        if (name[i] >= 'A' && name[i] <= 'Z') {
            lower[i] = name[i] + 32;
        } else {
            lower[i] = name[i];
        }
    }
    lower[length] = '\0';
    return lower;
}


/*void readRequest(char* request){
    FILE *fichier;
    fichier = fopen(request, "r");

    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier");
        exit(1);
    }

    char* fonction = malloc(sizeof(char) * 50);
    char* var = malloc(sizeof(char) * 50);

    while(fgets(line,sizeof(line),fichier) != NULL){
        fonction =  strtok(line, ";");
        var = strtok(NULL, ";");
    }

    if(fonction == 'searchByDirector'){
        return searchByDirector(var);
    }
    if(fonction == 'searchByDuree'){
        return searchByDuree(var);
    }
    if(fonction == 'searchByCategorie'){
        return searchByCategorie(var);
    }
    if(fonction == 'searchByFilm'){
        return searchByFilm(var);
    }
    if(fonction == 'searchRealMostMovie'){
        return searchRealMostMovie(var);
    }
    if(fonction == 'searchAll'){
        return searchAll(var);
    }
    if(fonction == 'stopServer'){
        return stopServer(var);
    }
}
*/
//verifier si le fichier est la faire une boucle et a l'aide d'un fopen() quand on y a acces le fichier est alors present

void deleteFilmotheque(struct Filmotheque* filmotheque, struct List* table[LENGTH]){
    //Delete all the sub tree from the trie filmotheque->director
    deleteNodeTrie(filmotheque->director);
    /*
    for(int i = 0; i < LENGTH; i++){
        if(table[i] != NULL){
            deleteList(table[i]);
        }
    }
     */
    free(filmotheque);
}