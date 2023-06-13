#define LENGTH 12600
#define NUMBER_OF_CHAR 500000

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
    if (node->movie->size > filmotheque->maxMovies) {
        filmotheque->maxMovies = node->movie->size;
        filmotheque->directorMax = node->movie->head->movie->director;
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

void initFilmo(char* nameFile,struct List* table,struct Filmotheque* filmo){
    FILE *fichier;
    fichier = fopen(nameFile, "r");

    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier");
        exit(1);
    }


    char line[NUMBER_OF_CHAR];

    while(fgets(line,sizeof(line),fichier) != NULL){
        char* director = (strtok(line, ";"));
        toLowercase(director);
        char* name = strtok(NULL, ";");
        char* time = strtok(NULL, ";");
        char* category = strtok(NULL, ";");
        //Remove the \r\n at the end of the line
        category[strlen(category) - 2] = '\0';
        struct Movie* movie = createMovie(director, name, time,category);
        free(director);
        addMovieInTable(table,movie);
        addMovie(filmo,movie);
    }
    fclose(fichier);
}

struct List* searchByDirector(struct Filmotheque* filmotheque, char* director){
    printf("\nsearchByDirector\n");
    printf("director : %s\n",director);
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

struct List* searchByCategory(struct List* table[LENGTH], char* category){
    struct List* result = createEmptyList();
    for(int i = 0;i<LENGTH;i++){
        if(table[i]==NULL){
            return NULL;
        }
        else{
            struct Cell* inter = table[i]->head;
            int length = table[i]->size;
            for(int j = 0;j<length;j++){
                if(inter->movie->category == category){
                    addFirst(result,inter->movie);
                }
            }
        }
    }
    return result;
}

struct List* searchByFilm(struct List* table[LENGTH], char* name){
    struct List* result = createEmptyList();
    for(int i = 0;i<LENGTH;i++){
        if(table[i]==NULL){
            return NULL;
        }
        else{
            struct Cell* inter = table[i]->head;
            int length = table[i]->size;
            for(int j = 0;j<length;j++){
                if(inter->movie->name == name){
                    addFirst(result,inter->movie);
                }
            }
        }
    }
    return result;
}


void toLowercase(char* str) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}

struct List* searchRealMostMovie(struct Filmotheque* filmo){
    char* directorMax = filmo->directorMax;
    struct List* result = searchByDirector(filmo,directorMax);
    return result;
}


int readRequest(char* request, struct List* tableau[LENGTH], struct Filmotheque* filmo) {
    printf("\nreadRequest\n");
    FILE *fichier;
    fichier = fopen(request, "r");

    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier2");
        exit(1);
    }

    char line[NUMBER_OF_CHAR];

    char *fonction;
    char *argument;

    while (fgets(line, sizeof(line), fichier) != NULL) {
        fonction = strtok(line, ";");
        argument = strtok(NULL, ";");
    }
    printf("\nfonction : %s\n", fonction);
    printf("argument : %s\n", argument);
    if (strcmp(fonction, "searchByDirector") == 0) {
        clock_t start;
        toLowercase(argument);
        start = clock();
        struct List* result = searchByDirector(filmo, argument);
        start = clock() - start;
        double time_taken = ((double) start) / CLOCKS_PER_SEC;
        printList(result);
        printResultInFile(result, time_taken);
        printf("\nstart of the delay\n");
        delay(2);
        printf("\nend of the delay\n");
        deleteFile();
        free(argument);
        return 0;
    }
    else if (strcmp(fonction, "searchByTime") == 0) {
        clock_t start;
        start = clock();
        struct List* result = searchByTime(tableau, argument);
        start = clock() - start;
        double time_taken = ((double) start) / CLOCKS_PER_SEC;
        printResultInFile(result, time_taken);
        delay(2);
        printf("\nend of the delay\n");
        deleteFile();
        return 0;
    }
    else if (strcmp(fonction, "searchByCategory") == 0){
        clock_t start;
        start = clock();
        struct List* result = searchByCategory(tableau, argument);
        start = clock() - start;
        double time_taken = ((double) start) / CLOCKS_PER_SEC;
        printResultInFile(result, time_taken);
        delay(2);
        printf("\nend of the delay\n");
        deleteFile();
        return 0;
    }
    else if (strcmp(fonction,"searchRealMostMovie") == 0) {
        clock_t start;
        start = clock();
        struct List *result = searchRealMostMovie(filmo);
        start = clock() - start;
        double time_taken = ((double) start) / CLOCKS_PER_SEC;
        printResultInFile(result, time_taken);
        delay(2);
        printf("\nend of the delay\n");
        deleteFile();
        return 0;
    }
    else if (strcmp(fonction,"stopServer") == 0) {
        delay(2);
        printf("\nend of the delay\n");
        deleteFile();
        return 8;
    }
}

void deleteFilmotheque(struct Filmotheque* filmotheque, struct List* table[LENGTH]){

    free(filmotheque->directorMax);
    for(int i = 0; i < LENGTH; i++){
        deleteList(&table[i]);
    }
    deleteNodeTrie(&filmotheque->director);
    free(filmotheque);
}

void printResultInFile(struct List* result, double time){
    printf("\nprintResultInFile\n");
    FILE *fichier;
    fichier = fopen("results.txt", "w");

    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier");
        exit(1);
    }

    fprintf(fichier,"%f\n",time);
    struct Cell* inter = result->head;
    int length = result->size;
    for(int i=0; i<length; i++){
        //Don't supr the last charactere of the category
        int categoryLength = strlen(inter->movie->category);
        fprintf(fichier,"%s;%s;%s;%.*s\n",inter->movie->director,inter->movie->name,inter->movie->time,categoryLength,inter->movie->category);
        inter = inter->next;
    }
    fclose(fichier);
    //ecrit ready.txt pour dire que le fichier est pret a etre lu
    FILE *fichier2;
    fichier2 = fopen("ready.txt", "w");
    fclose(fichier2);
}

void deleteFile(){
    printf("\ndeleteFile\n");
    char* ready_results = "ready.txt";
    char* results = "results.txt";
    remove(ready_results);
    remove(results);
    char* request = "requests.txt";
    remove(request);
    return;
}

void delay(int i){
    clock_t start,end;
    start = clock();
    while(((end=clock())-start)<=i*CLOCKS_PER_SEC);
}