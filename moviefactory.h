// ------------------------------ moviefactory.h ---------------------------------

// Design Group 4
// CSS 343
// Created:
// Last Modified:

// ----------------------------------------------------------------------------

// MovieFactory Class:

// ----------------------------------------------------------------------------

// Notes on specifications, special algorithms, and assumptions.

//
//
//

//

#ifndef MOVIEFACTORY_H
#define MOVIEFACTORY_H

#include <iostream>
#include <string> //used in createMovie method
#include "movie.h"
#include "comedy.h"
#include "drama.h"
#include "classics.h"

using namespace std;

class MovieFactory {
public:
    MovieFactory();
    ~MovieFactory();

    bool createMovie(Movie*& movie, string line);
};
#endif