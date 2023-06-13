#define LENGTH 12600

#include "Filmotheque.h"
#include "List.h"
#include "Movie.h"

int main() {
    int stop = 0;

    char *fichier = "BD_small.txt";

    //Create a table of list named tableau
    struct List *tableau[LENGTH];
    for (int i = 0; i < LENGTH; i++) {
        tableau[i] = NULL;
    }
    struct Filmotheque *filmo = createEmptyFilmo();
    initFilmo(fichier, tableau, filmo);

    while (stop != 8) {
        //check if requests.txt exist but don't create it if it doesn't exist
        FILE *verif = fopen("requests.txt", "r");
        if (verif != NULL) {
            printf("%d\n", stop);
            printf("Verif passed");
            char *request = "requests.txt";
            stop = readRequest(request, tableau, filmo);
            printf("%d\n", stop);
        }
    }
    printf("stop = 8\n");
    deleteFilmotheque(filmo, tableau);
    return 0;
}

