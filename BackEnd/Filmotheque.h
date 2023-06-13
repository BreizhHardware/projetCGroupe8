#ifndef PROJETCGROUPE8_MAIN_FILMOTHEQUE_H
#define PROJETCGROUPE8_MAIN_FILMOTHEQUE_H

#include "NodeTrie.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

struct Filmotheque{
    char* directorMax;
    int maxMovies;
    struct NodeTrie* director;
};

struct Filmotheque* createEmptyFilmo();

void createTable(char* nameFile,struct List* table,struct Filmotheque* filmo);

void addMovie(struct Filmotheque* filmotheque, struct Movie* movie);

char* toLower(char* name);

struct List* searchByDirector(struct Filmotheque* filmotheque, char* director);

struct List* searchByTime(struct List* tableau[LENGTH], char* time);

struct List* searchByCategory(struct List* table[], char* category);

struct List* searchByFilm(struct List* table[LENGTH], char* name);

struct List* addMovieInTable(struct List* table[LENGTH],struct Movie* movie);

void deleteFilmotheque(struct Filmotheque* filmotheque, struct List* table[LENGTH]);

void printResultInFile(struct List* result, double time);

#endif //PROJETCGROUPE8_MAIN_FILMOTHEQUE_H
