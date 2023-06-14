#define LENGTH 12600
#define NUMBER_OF_CHAR 500000

#include "Movie.h"
#include "Filmotheque.h"
#include "NodeTrie.h"
#include "List.h"

//Fonction qui créer une Filmotheque vide
struct Filmotheque* createEmptyFilmo(){
    struct Filmotheque* filmo = malloc(sizeof(struct Filmotheque));     //On alloue de la mémoire pour pouvoir la stocker
    if(filmo == NULL){
        printf("error malloc");
        return NULL;
    }
    //On initialise nos données au valeur par défaut
    filmo -> director = createEmptyNodeTrie();
    filmo -> maxMovies = 0;
    filmo -> directorMax = NULL;
    return filmo;
}

//Fonction qui ajoute un film à la filmotheque, plus particulierement dans le NodeTrie
void addMovie(struct Filmotheque* filmotheque, struct Movie* movie) {
    struct NodeTrie* node = filmotheque->director;      
    char* director = movie-> director;
    //On défini les caractères spéciaux, dans des places spécifiques pour chaque
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
        //On initialise les lettres basiques dans notre NodeTrie
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
    //Si le nom rentré éxiste déja on addFirst du film, dans la liste déja créée
    if (node->isName) {
        addFirst(node->movie,movie);
    }
    //Autrement on créer une liste et on ajoute le film dedans
    else {
        node->isName = true;
        node->movie = createEmptyList();
        addFirst(node->movie,movie);
    }
    //Initialise le directorMax et maxMovies
    if (node->movie->size > filmotheque->maxMovies) {
        filmotheque->maxMovies = node->movie->size;
        filmotheque->directorMax = node->movie->head->movie->director;
    }
}

//Fonction qui permet d'ajouter un film dans notre table
struct List* addMovieInTable(struct List* table[LENGTH],struct Movie* movie){
    //Pour pouvoir avoir la place dans la list il nous faut un int
    int realTime = atoi(movie->time);
    //Si c'est vide on créer une liste et on ajoute le film dedans
    if(table[realTime] == NULL){
        table[realTime] = createEmptyList();
        addFirst(table[realTime],movie);
    }
    //On ajoute juste dans la liste le film autrement
    else{
        addFirst(table[realTime],movie);
    }

    return table[realTime];
}

//Fonction qui nous permet d'initialiser notre Filmotheque ainsi que notre Tableau
void initFilmo(char* nameFile,struct List** table,struct Filmotheque* filmo){
    //Ouverture de la BDD
    FILE *fichier;
    fichier = fopen(nameFile, "r");
    //Vérification si on a bien ouvert la BDD
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier");
        exit(1);
    }
    //Contient la ligne ou l'on est rendu dans le fichier
    char line[NUMBER_OF_CHAR];
    //Boucle pour lire tout le fichier
    while(fgets(line,sizeof(line),fichier) != NULL){
        //Récupère la string avant le ;
        char* director = (strtok(line, ";"));
        //Mettre en minuscule pour pouvoir l'ajouter dans le NodeTrie
        toLowercase(director);
        char* name = strtok(NULL, ";");
        char* time = strtok(NULL, ";");
        char* category = strtok(NULL, ";");
        //Enlever le \n\r à la fin pour le remplacer par un \0
        category[strlen(category) - 2] = '\0';
        //On créer le film pour après l'ajouter dans les structures
        struct Movie* movie = createMovie(director, name, time,category);
        //Ajout dans la table
        addMovieInTable(table,movie);
        //Ajout dans le NodeTrie
        addMovie(filmo,movie);
    }
    fclose(fichier);
}

//Fonction qui filtre les film par leur réalisateur
struct List* searchByDirector(struct Filmotheque* filmotheque, char* director){
    //List que l'on va renvoyer
    struct List* copy = createEmptyList();
    //On rentre dans le NodeTrie
    struct NodeTrie* node = filmotheque->director;
    //On boucle pour trouver notre réalisateur
    for(int i = 0; i < strlen(director); i++){
        if(node->children[director[i] - 'a'] == NULL){
            return copy;
        }
        //On avance dans le NodeTrie
        node = node->children[director[i] - 'a'];
    }
    //Si on arrive au bout de son nom on copie sa liste pour la renvoyer
    if(node->isName){
        copy = copyList(node->movie);
        return copy;
    }
    return copy;
}

//Fonction qui filte par temps
struct List* searchByTime(struct List* table[LENGTH], char* time){
    //On prend le int et on renvoie juste la case correspondante
    int realTime = atoi(time);
    return table[realTime];
}

//Fonction qui filter par categorie
struct List* searchByCategory(struct List* table[LENGTH], char* category){
    //Liste que l'on va renvoyer
    struct List* result = createEmptyList();
    //On boucle pour trouver la categorie correspondante
    for(int i = 0;i<LENGTH;i++){
        if(table[i] != NULL){
            struct Cell* inter = table[i]->head;
            int length = table[i]->size;
            for(int j=0;j<length;j++){
                if(!strcmp(inter->movie->category,category)) {
                    addFirst(result,inter->movie);
                }
            }
        }
    }
    return result;
}

//Fonction qui recherche par le nom d'un film
struct List* searchByFilm(struct List* table[LENGTH], char* name){
    struct List* result = createEmptyList();
    //Allocation de la mémoire
    char *titleLower = calloc(sizeof(char), LENGTH);
    char *searchLower = calloc(sizeof(char), LENGTH);
    //On boucle pour trouver le film
    for(int i=0; i<LENGTH; i++){
        if(table[i] != NULL){
            struct Cell* inter = table[i]->head;
            int length = table[i]->size;
            while (length != 0) {
                strcpy(titleLower, inter->movie->name);
                strcpy(searchLower, name);
                toLowercase(searchLower);
                toLowercase(titleLower);
                if(strstr(titleLower, searchLower) != NULL){
                    addFirst(result,inter->movie);
                }
                inter = inter->next;
                --length;
            }
        }
    }
    free(titleLower);
    free(searchLower);
    return result;
}

//Fonction qui peremet de mettre un mot en minuscule
void toLowercase(char* str) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}

//Fonction qui renvoie le Director 
struct List* searchRealMostMovie(struct Filmotheque* filmo){
    char* directorMax = filmo->directorMax;
    struct List* result = searchByDirector(filmo,directorMax);
    return result;
}

//Fonction qui permet de lire les reqêtes éffectué par le client
int readRequest(char* request, struct List* tableau[LENGTH], struct Filmotheque* filmo) {
    //On ouvre la request
    FILE *fichier;
    fichier = fopen(request, "r");

    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier2");
        exit(1);
    }

    char line[NUMBER_OF_CHAR];

    char *fonction;
    char *argument;
    
    //On récupère la fonction + l'argument
    while (fgets(line, sizeof(line), fichier) != NULL) {
        fonction = strtok(line, ";");
        argument = strtok(NULL, ";");
    }

    //On vérifie qu'elle fonction est éxécuté
    if (strcmp(fonction, "searchByDirector") == 0) {
        //Pour avoir le temps d'éxec
        clock_t start;
        //En minuscule car dans notre NodeTrie tout est en minuscule
        toLowercase(argument);
        start = clock();
        struct List* result = searchByDirector(filmo, argument);
        start = clock() - start;
        double time_taken = ((double) start) / CLOCKS_PER_SEC;
        //On print le result dans le fichier result.txt
        printResultInFile(result, time_taken);
        //Pour être sure que le result est lis
        delay(2);
        //On supprime tout les fichiers request et result
        deleteFile();
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
        deleteFile();
        return 0;
    }
    else if (strcmp(fonction, "searchByFilm") == 0){
        clock_t start;
        start = clock();
        struct List* result = searchByFilm(tableau, argument);
        start = clock() - start;
        double time_taken = ((double) start) / CLOCKS_PER_SEC;
        printResultInFile(result, time_taken);
        delay(2);
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
        deleteFile();
        return 0;
    }
    else if (strcmp(fonction,"stopServer") == 0) {
        delay(2);
        deleteFile();
        return 8;
    }
    return 0;
}

//Fonction qui supprime la Filmotheque
void deleteFilmotheque(struct Filmotheque* filmotheque, struct List* table[LENGTH]){
    //On delete d'abord toutes les listes
    for(int i = 0; i < LENGTH; i++){
        deleteList(&table[i]);
    }
    //Après on delete le NodeTrie
    deleteNodeTrie(&filmotheque->director);
    //Et on peut après free notre structure
    free(filmotheque);
}

void printResultInFile(struct List* result, double time){
    //On ouvre le fichier result
    FILE *fichier;
    fichier = fopen("results.txt", "w");

    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier");
        exit(1);
    }
    
    //On vérifie si la liste est NULL
    fprintf(fichier,"%f\n",time);
    if(result ==NULL){
       fclose(fichier);
        FILE *fichier2;
        fichier2 = fopen("ready.txt", "w");
        if (fichier2 == NULL) {
            printf("Erreur lors de l'ouverture du fichier ready\n");
            exit(1);
        }
        fclose(fichier2);
        return;
    }
    struct Cell* inter = result->head;
    int length = result->size;
    for(int i=0; i<length; i++){
        //Pas supprimer le dernier caractere de categorie 
        int categoryLength = strlen(inter->movie->category);
        fprintf(fichier,"%s;%s;%s;%.*s\n",inter->movie->director,inter->movie->name,inter->movie->time,categoryLength,inter->movie->category);
        inter = inter->next;
    }
    fclose(fichier);
    //ecrit ready.txt pour dire que le fichier est pret a etre lu
    FILE *fichier2;
    fichier2 = fopen("ready.txt", "w");
    if(fichier2 == NULL){
        printf("Erreur lors de l'ouverture du fichier ready\n");
        exit(1);
    }
    fclose(fichier2);
}

//Fonction qui permet de delete tout les fichiers requests + results
void deleteFile(){
    char* ready_results = "ready.txt";
    char* results = "results.txt";
    remove(ready_results);
    remove(results);
    char* request = "requests.txt";
    remove(request);
    return;
}

//Fonction qui fait un délai
void delay(int i){
    clock_t start,end;
    start = clock();
    while(((end=clock())-start)<=i*CLOCKS_PER_SEC);
}
