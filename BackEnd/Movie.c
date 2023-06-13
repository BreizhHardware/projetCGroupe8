#include "Movie.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Movie* createMovie(char* director, char* name, char* time, char* category){
    struct Movie* movie = malloc(sizeof(struct Movie));
    if(movie == NULL){
        printf("error malloc");
        return NULL;
    }
    movie->director = malloc(sizeof(char) * (strlen(director) + 1));
    movie->name = malloc(sizeof(char) * (strlen(name) + 1));
    movie->time = malloc(sizeof(char) * (strlen(time) + 1));
    movie->category = malloc(sizeof(char) * (strlen(category) + 1));
    strcpy(movie->director, director);
    strcpy(movie->name, name);
    strcpy(movie->time, time);
    strcpy(movie->category, category);
    return movie;
}

void deleteMovie(struct Movie* movie){
    free(movie->director);
    free(movie->name);
    free(movie->time);
    free(movie->category);
    free(movie);
}