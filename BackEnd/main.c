#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "List.h"
#include "Filmotheque.h"
#include <time.h>

int main() {
    struct Filmotheque* filmotheque2 = recupInfo("../BD_small.txt");
    struct List* test3 = searchByDirector(filmotheque2, "fincher");
    printList(test3);
    printf("\n");
    struct List* test1456 = searchByDirector(filmotheque2, "johnson");
    printList(test1456);
    deleteList(&test1456);
    deleteList(&test3);
    struct List* test7854 = createTable("../BD_small.txt");
    printList(test7854);
    deleteFilmotheque(&filmotheque2);
    /*
    clock_t t2;
    t2 = clock();
    struct Filmotheque* filmotheque = recupInfo("../BD_big.txt");
    t2 = clock() - t2;
    double time_taken2 = ((double)t2)/CLOCKS_PER_SEC;
    clock_t t;
    t = clock();
    struct List* test = searchByDirector(filmotheque, "leonard");
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printList(test);
    deleteList(&test);
    deleteFilmotheque(&filmotheque);
    printf("recupInfo() took %f seconds to execute \n", time_taken2);
    printf("searchByDirector() took %f seconds to execute \n", time_taken);
     */
    return 0;
}