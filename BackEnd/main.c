#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "list.h"
#include "Filmotheque.h"

int main() {
    /*
    FILE *fichier;
    fichier = fopen("../BD_small.txt", "r");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier");
        exit(1);
    }
    char* real = malloc(sizeof(char) * 50);
    char* movie = malloc(sizeof(char) * 50);
    char* time = malloc(sizeof(char) * 50);
    char* category = malloc(sizeof(char) * 50);
    int i = 0;
    int j = 0;
    char line[50];
    char* s = fgets(line, sizeof(line), fichier);
    real = strtok(s, ";");
    printf("%s\n", real);
    movie = strtok(NULL, ";");
    printf("%s\n", movie);
    time = strtok(NULL, ";");
    printf("%s\n", time);
    category = strtok(NULL, ";");
    printf("%s\n", category);

    fclose(fichier);
     */
    struct Filmotheque* filmotheque = createEmptyFilmotheque();
    addMovie(filmotheque, "real", "movie", "time", "category");
    addMovie(filmotheque, "real", "movie2", "69", "category");
    addMovie(filmotheque, "real", "movie3", "420", "category");
    addMovie(filmotheque, "real2", "movie4", "549", "category");
    struct List* test = searchByDirector(filmotheque, "real");
    printList(test);
    deleteList(&test);
    return 0;
}