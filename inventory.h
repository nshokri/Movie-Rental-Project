// ------------------------------ inventory.h ---------------------------------

// Design Group 4
// CSS 343
// Created:
// Last Modified:

// ----------------------------------------------------------------------------

// Inventory Class:

// ----------------------------------------------------------------------------

// Notes on specifications, special algorithms, and assumptions.

//
//
//

//

#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include "movie.h"
#include "transaction.h"
#include "store.h"

using namespace std;

class Inventory : public Transaction {
public:
    Inventory();
    ~Inventory();

    void executeTransaction(Store* s);
    void printInfo();
};
#endif