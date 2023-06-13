#define LENGTH 12600

#include "Filmotheque.h"
#include "List.h"
#include "Movie.h"

int main(){

    char* fichier = "../BD_small.txt";

    //Create a table of list named tableau
    struct List* tableau[LENGTH];
    for(int i = 0; i < LENGTH; i++){
        tableau[i] = NULL;
    }

    struct Filmotheque* filmo = createEmptyFilmo();
    //Create the filmotheque with the file BD_small.txt
    createTable(fichier,tableau,filmo);

    struct List* result = searchByDirector(filmo,"allen");
    printList(result);
    printf("\n-------------------------------------------------------\n");
    struct List* result2 = searchByTime(tableau,"94");
    printList(result2);

    return 0;
}