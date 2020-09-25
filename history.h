// ------------------------------- history.h ----------------------------------

// Design Group 4
// CSS 343
// Created: 8/11/2020
// Last Modified: 8/19/2020

// ----------------------------------------------------------------------------

// History Class:

// ----------------------------------------------------------------------------

// Notes on specifications, special algorithms, and assumptions.

//
//
//

//

#ifndef HISTORY_H
#define HISTORY_H

#include <iostream>
#include "transaction.h"
#include "store.h"

using namespace std;

class History : public Transaction {
public:
    History();
    History(int ID);
    ~History();

    void executeTransaction(Store* s);
    void printInfo();
private:
    int id;
};

#endif