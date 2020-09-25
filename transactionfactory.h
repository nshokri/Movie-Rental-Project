// ------------------------------ transactionfactory.h ---------------------------------

// Design Group 4
// CSS 343
// Created:
// Last Modified:

// ----------------------------------------------------------------------------

// TransactionFactory Class:

// ----------------------------------------------------------------------------

// Notes on specifications, special algorithms, and assumptions.

//
//
//

//

#ifndef TRANSACTIONFACTORY_H
#define TRANSACTIONFACTORY_H

#include <iostream>
#include <string>
#include "transaction.h"
#include "borrow.h"
#include "return.h"
#include "history.h"
#include "inventory.h"


using namespace std;

class TransactionFactory {
public:
  TransactionFactory();
  ~TransactionFactory();
  
  bool createTransaction(string line, Transaction& t, Store* s);
private:
  
};
#endif