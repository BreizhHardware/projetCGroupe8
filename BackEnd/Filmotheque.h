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

char* toLower(char* name);

struct Filmotheque* createEmptyFilmo();

void initFilmo(char* nameFile,struct List* table,struct Filmotheque* filmo);

struct List* addMovieInTable(struct List* table[LENGTH],struct Movie* movie);

void addMovie(struct Filmotheque* filmotheque, struct Movie* movie);

struct List* searchByDirector(struct Filmotheque* filmotheque, char* director);

struct List* searchByTime(struct List* tableau[LENGTH], char* time);

struct List* searchByCategory(struct List* table[LENGTH], char* category);

struct List* searchByFilm(struct List* table[LENGTH], char* name);

void deleteFilmotheque(struct Filmotheque* filmotheque, struct List* table[LENGTH]);

int readRequest(char* request, struct List* tableau[LENGTH],struct Filmotheque* filmo);

void printResultInFile(struct List* result, double time);

void delay(int i);

void deleteFile();

#endif //PROJETCGROUPE8_MAIN_FILMOTHEQUE_H
