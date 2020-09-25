// --------------------------------- comedy.h ---------------------------------

// Design Group 4
// CSS 343
// Created:
// Last Modified:

// ----------------------------------------------------------------------------

// Comedy Class:

// ----------------------------------------------------------------------------

// Notes on specifications, special algorithms, and assumptions.

//
//
//

//

#ifndef COMEDY_H
#define COMEDY_H

#include <iostream>
#include "movie.h"
using namespace std;

class Comedy : public Movie {
public:
    Comedy(char type, int stock, string director, string title, int year);
    ~Comedy();

    virtual bool operator<(const Comedy&) const;
    virtual bool operator==(const Comedy&) const;
};
#endif