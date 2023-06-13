#define LENGTH 12600

#include "Filmotheque.h"
#include "List.h"
#include "Movie.h"

int main() {
    int stop = 0;

    char *fichier = "BD_big.txt";

    //Create a table of list named tableau
    struct List *tableau[LENGTH];
    for (int i = 0; i < LENGTH; i++) {
        tableau[i] = NULL;
    }
    struct Filmotheque *filmo = createEmptyFilmo();
    //Create the filmotheque with the file BD_small.txt
    initFilmo(fichier, tableau, filmo);

    while (stop != 8) {
        FILE *verif;
        verif = fopen("requests.txt", "r");
        if (verif != NULL) {
            printf("Verif passed");
            char *request = "requests.txt";
            stop = readRequest(request, tableau, filmo);
        }
    }
    return 0;
}

    /*
    struct List* result = searchByDirector(filmo,"allen");
    printList(result);
    printf("\n-------------------------------------------------------\n");
    struct List* result2 = searchByTime(tableau,"94");
    printList(result2);

    /*
    printf("\n-------------------------------------------------------\n");
    struct List* result3 = searchByCategory(tableau,"Action");
    printList(result3);
    printf("\n-------------------------------------------------------\n");
    struct List* result4 = searchByFilm(tableau,"the");
    printList(result4);
     */

