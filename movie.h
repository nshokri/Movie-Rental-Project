// --------------------------------- movie.h ----------------------------------

// Design Group 4
// CSS 343
// Created:
// Last Modified:

// ----------------------------------------------------------------------------

// Movie Class:

// ----------------------------------------------------------------------------

// Notes on specifications, special algorithms, and assumptions.

//
//
//

//

#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>

using namespace std;

class Movie {
public:
    Movie(char type, int stock, string director, string title, int year);
    virtual ~Movie();

    virtual void addStock();
    virtual void removeStock();

    virtual bool operator<(const Movie&) const;
    virtual bool operator==(const Movie&) const;

    virtual void print() const;

    virtual string getDirector() const;
    virtual string getTitle() const;
    virtual char getType() const;
    virtual int getStock() const;
    virtual int getYear() const;


protected:
    string director;   // director of the movie
    string title;      // title of the movie

    char type;         // type of movie 'F' = comedy; 'D' = drama; 'C' = classic

    int stock;         // current stock of movie type
    int year;          // year movie was released
};
#endif