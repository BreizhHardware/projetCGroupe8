#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "List.h"
#include "Filmotheque.h"

int main() {
    struct Filmotheque* filmotheque2 = recupInfo("../BD_small.txt");
    struct List* test3 = searchByDirector(filmotheque2, "fincher");
    printList(test3);
    struct List* test1456 = searchByDirector(filmotheque2, "johnson");
    printList(test1456);
    deleteList(&test1456);
    deleteList(&test3);
    deleteFilmotheque(&filmotheque2);
    return 0;
}