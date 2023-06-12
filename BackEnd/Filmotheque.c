#define NUMBER_OF_CHAR 100

#include "Filmotheque.h"

struct Filmotheque* createEmptyFilmotheque(){
    struct Filmotheque* filmotheque = malloc(sizeof(struct Filmotheque));
    if(filmotheque == NULL){
        printf("error malloc");
        return NULL;
    }
    filmotheque->director = createEmptyNodeTrie();
    filmotheque->realMax = NULL;
    filmotheque->maxMovies = 0;
    return filmotheque;
}

void addMovie(struct Filmotheque* filmotheque, char* real, char* movie, char* time, char* category) {
    struct NodeTrie* node = filmotheque->director;
    for (int i = 0; i < strlen(real); i++) {
        if (real[i] == '-') {
            if (node->children[26] == NULL) {
                node->children[26] = createEmptyNodeTrie();
            }
            node = node->children[26];
        }
        else if (real[i] == '\'') {
            if (node->children[27] == NULL) {
                node->children[27] = createEmptyNodeTrie();
            }
            node = node->children[27];
        }
        else if (node->children[real[i] - 'a'] == NULL) {
            node->children[real[i] - 'a'] = createEmptyNodeTrie();
            node = node->children[real[i] - 'a'];
        }
        else {
            node = node->children[real[i] - 'a'];
        }
    }

    if (node->isName) {
        addFirst(node->movie, real, movie, time, category);
    }
    else {
        node->isName = true;
        node->movie = createEmptyList();
        addFirst(node->movie, real, movie, time, category);
    }
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
    }
    return copy;
}

void deleteFilmotheque(struct Filmotheque** filmotheque){
    deleteNodeTrie(&(*filmotheque)->director);
    free(*filmotheque);
    *filmotheque = NULL;
}

struct Filmotheque* recupInfo(char* nameFile){
    FILE* fichier;
    fichier = fopen(nameFile, "r");

    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier");
        exit(1);
    }

    char* real = malloc(sizeof(char));
    char* movie = malloc(sizeof(char));
    char* time = malloc(sizeof(char));
    char* category = malloc(sizeof(char));
    char line[NUMBER_OF_CHAR];

    struct Filmotheque* filmo = createEmptyFilmotheque();

    while(fgets(line,sizeof(line),fichier) != NULL){
        real = toLower((strtok(line, ";")));
        movie = strtok(NULL, ";");
        time = strtok(NULL, ";");
        category = strtok(NULL, ";");
        addMovie(filmo,real,movie,time,category);
    }

    fclose(fichier);

    return filmo;
}

char* toLower(char* name) {
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