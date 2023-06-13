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
    initFilmo(fichier, tableau, filmo);
    printf("Filmotheque initialized\n");
    while (stop != 8) {
        FILE *verif = fopen("requests.txt", "r");
        if (verif != NULL) {
            char *request = "requests.txt";
            stop = readRequest(request, tableau, filmo);
        }
    }

    deleteFilmotheque(filmo, tableau);
    return 0;
}

