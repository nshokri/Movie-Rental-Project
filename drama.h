// --------------------------------- drama.h ----------------------------------

// Design Group 4
// CSS 343
// Created:
// Last Modified:

// ----------------------------------------------------------------------------

// Drama Class:

// ----------------------------------------------------------------------------

// Notes on specifications, special algorithms, and assumptions.

//
//
//

//

#ifndef DRAMA_H
#define DRAMA_H

#include <iostream>
#include "movie.h"
using namespace std;

class Drama : public Movie {
public:
    Drama(char type, int stock, string director, string title, int year);
    ~Drama();

    virtual bool operator<(const Drama&) const;
    virtual bool operator==(const Drama&) const;
};
#endif
