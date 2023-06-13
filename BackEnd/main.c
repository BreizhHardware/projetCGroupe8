#define LENGTH 12600

#include "Filmotheque.h"
#include "List.h"
#include "Movie.h"
#include <time.h>

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
    clock_t start;
    start = clock();
    struct List* result2 = searchByTime(tableau,"94");
    start = clock() - start;
    double time_taken = ((double)start)/CLOCKS_PER_SEC;
    printList(result2);
    printResultInFile(result2,time_taken);

    printf("\n-------------------------------------------------------\n");
    struct List* result3 = searchByCategory(tableau,"Action");
    printList(result3);
    printf("\n-------------------------------------------------------\n");
    struct List* result4 = searchByFilm(tableau,"The");
    printList(result4);


    return 0;
}