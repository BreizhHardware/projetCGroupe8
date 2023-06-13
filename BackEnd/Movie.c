#include "Movie.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Fonction qui permet de créer un movie, avec toute les informations le concernant
struct Movie* createMovie(char* director, char* name, char* time, char* category){
    struct Movie* movie = malloc(sizeof(struct Movie));     //On alloue de la mémoire pour stocker notre structure
    if(movie == NULL){
        printf("error malloc");
        return NULL;
    }
    //On alloue de la mémoire pour stocker nos données
    movie->director = malloc(sizeof(char) * (strlen(director) + 1));    
    movie->name = malloc(sizeof(char) * (strlen(name) + 1));
    movie->time = malloc(sizeof(char) * (strlen(time) + 1));
    movie->category = malloc(sizeof(char) * (strlen(category) + 1));
    //On copie nos données pour pouvoir les stocker
    strcpy(movie->director, director);
    strcpy(movie->name, name);
    strcpy(movie->time, time);
    strcpy(movie->category, category);
    return movie;
}

//Fonction qui permet de supprimer un movie
void deleteMovie(struct Movie* movie){
    //Même fonctionnment à chaque fois on change juste de données donc d'emplacement
    if(movie->director != NULL){    //Si director est différent de NULL
        free(movie->director);      //On libère la mémoire donc on "supprime" director de notre struct
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
    free(movie);    //On libère la mémoire, pour supprimer la struct movie
}
