#ifndef UNTITLED_MOVIE_H
#define UNTITLED_MOVIE_H

struct Movie{
    char* director;
    char* name;
    char* time;
    char* category;
};

struct Movie* createMovie(char* director, char* name, char* time, char* category);

void deleteMovie(struct Movie* movie);



#endif //UNTITLED_MOVIE_H
