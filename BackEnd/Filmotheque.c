#define NUMBER_OF_CHAR 100
#define LENGTH 12600

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
        else if (real[i] == ' ') {
            if (node->children[28] == NULL) {
                node->children[28] = createEmptyNodeTrie();
            }
            node = node->children[28];
        }
        else if (node->children[real[i] - 'a'] == NULL) {
            node->children[real[i] - 'a'] = createEmptyNodeTrie();
            node = node->children[real[i] - 'a'];
        }
        else {
            node = node->children[real[i] - 'a'];
        }
    }
    node->isName = true;
    if (node->movie == NULL) {
        node->movie = createEmptyList();
    }
    addFirst(node->movie, real, movie, time, category);
    //If the director has more movie than the max, we change the RealMax to the director and we change the maxMovies
    if (node->movie->size > filmotheque->maxMovies) {
        filmotheque->realMax = node->movie;
        filmotheque->maxMovies = node->movie->size;
    }
}

struct List* searchByDirector(struct Filmotheque* filmotheque, char* director){
    struct NodeTrie* node = filmotheque->director;
    for (int i = 0; i < strlen(director); i++) {
        if (director[i] == '-') {
            if (node->children[26] == NULL) {
                return NULL;
            }
            node = node->children[26];
        }
        else if (director[i] == '\'') {
            if (node->children[27] == NULL) {
                return NULL;
            }
            node = node->children[27];
        }
        else if (node->children[director[i] - 'a'] == NULL) {
            return NULL;
        }
        else {
            node = node->children[director[i] - 'a'];
        }
    }
    if (node->isName) {
        return node->movie;
    }
    else {
        return NULL;
    }
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

    struct Filmotheque* filmotheque = createEmptyFilmotheque();

    while(fgets(line,sizeof(line),fichier) != NULL){
        line[strcspn(line, "\r\n")] = '\0';
        real = toLower((strtok(line, ";")));
        movie = strtok(NULL, ";");
        time = strtok(NULL, ";");
        category = strtok(NULL, ";");
        addMovie(filmotheque,real,movie,time,category);
    }

    fclose(fichier);

    return filmotheque;
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

int stopServer(){
    return 8;
}

struct List* createTable(char* nameFile){
    FILE* fichier;
    fichier = fopen(nameFile, "r");

    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier");
        exit(1);
    }

    char* real = malloc(sizeof(char));
    if (real == NULL) {
        printf("error malloc");
        return NULL;
    }
    char* movie = malloc(sizeof(char));
    if (movie == NULL) {
        printf("error malloc");
        return NULL;
    }
    char* time = malloc(sizeof(char));
    if (time == NULL) {
        printf("error malloc");
        return NULL;
    }
    char* category = malloc(sizeof(char));
    if (category == NULL) {
        printf("error malloc");
        return NULL;
    }
    char line[NUMBER_OF_CHAR];

    struct List* tableau[LENGTH];
    for(int i = 0; i < LENGTH; i++){
        tableau[i] = NULL;
    }

    while(fgets(line,sizeof(line),fichier) != NULL){
        line[strcspn(line, "\r\n")] = '\0';
        real = toLower((strtok(line, ";")));
        movie = strtok(NULL, ";");
        time = strtok(NULL, ";");
        category = strtok(NULL, ";");
        addMovieInTable(tableau,real,movie,time,category);
    }

    fclose(fichier);

    return tableau;
}


void addMovieInTable(struct List** tableau, char* real, char* movie, char* time, char* category){
    int index = atoi(time);
    if(tableau[index] == NULL){
        tableau[index] = createEmptyList();
    }
    addFirst(tableau[index],real,movie,time,category);
}