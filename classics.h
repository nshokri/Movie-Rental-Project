// ------------------------------- classics.h ----------------------------------

// Design Group 4
// CSS 343
// Created:
// Last Modified:

// ----------------------------------------------------------------------------

// Classic Class:

// ----------------------------------------------------------------------------

// Notes on specifications, special algorithms, and assumptions.

//
//
//

//

#ifndef CLASSICS_H
#define CLASSICS_H

#include <iostream>
#include "movie.h"
using namespace std;

class Classics : public Movie {
public:
    Classics(char type, int stock, string director, string title, string majorActor, int releaseMonth, int releaseYear);
    ~Classics();

    virtual void print() const;

    virtual string getMajorActor() const;
    virtual int getMonth() const;
    virtual int getYear() const;

    virtual bool operator<(const Classics&) const;
    virtual bool operator==(const Classics&) const;

private:
    string majorActor;
    int releaseMonth;
    int releaseYear;

};
#endif