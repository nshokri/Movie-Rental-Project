// ------------------------------ transaction.h -------------------------------

// Implementation Group 13
// CSS 343
// Created:
// Last Modified: 8/12/2020

// ----------------------------------------------------------------------------

// Transaction Class:
// Parent class for transactions (inventory, history, borrow, return)

// ----------------------------------------------------------------------------

// Notes on specifications, special algorithms, and assumptions.

//
//
//

//

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
//#include "store.h"
class Store; // forward reference to avoid error C2061

using namespace std;

class Transaction {
public:
  Transaction();
  virtual ~Transaction();

  virtual void executeTransaction(Store* s);
  virtual void printInfo();
};
#endif