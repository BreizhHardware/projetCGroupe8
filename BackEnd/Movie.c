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
    if(movie->director != NULL){
        free(movie->director);
        movie -> director = NULL;
    }
    if(movie->name != NULL){
        free(movie->name);
        movie -> name = NULL;
    }
    if(movie->time != NULL){
        free(movie->time);
        movie -> time = NULL;
    }
    if(movie->category != NULL){
        free(movie->category);
        movie -> category = NULL;
    }
    free(movie);
}