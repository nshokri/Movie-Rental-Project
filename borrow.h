// -------------------------------- borrow.h ----------------------------------

// Design Group 4
// CSS 343
// Created: 8/11/2020
// Last Modified: 8/19/2020

// ----------------------------------------------------------------------------

// Borrow Class:

// ----------------------------------------------------------------------------

// Notes on specifications, special algorithms, and assumptions.

//
//
//

//

#ifndef BORROW_H
#define BORROW_H

#include <iostream>
#include "transaction.h"
#include "movie.h"
#include "store.h"
#include "hashtable.h"

using namespace std;

class Borrow : public Transaction {
public:
    Borrow();
    Borrow(Movie* m, int ID);
    ~Borrow();

    void executeTransaction(Store* s);
    //void findMovie(Movie*& m, HashTable<Movie>& movies);
    void printInfo();
private:
    Movie* movie;
    int id;
};
#endif