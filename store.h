// ------------------------------ store.h ---------------------------------

// Implementation Group 13
// CSS 343
// Created: 8/10/2020
// Last Modified: 8/20/2020

// ----------------------------------------------------------------------------

// Store Class:

// ----------------------------------------------------------------------------

// Notes on specifications, special algorithms, and assumptions.

//
//
//

//

#ifndef STORE_H
#define STORE_H

#include <iostream>
#include <fstream>
#include <queue>
#include "movie.h"
#include "drama.h"
#include "comedy.h"
#include "classics.h"
#include "moviefactory.h"
#include "customer.h"
#include "hashtable.cpp"
#include "transactionfactory.h"
#include "transaction.h"
#include "borrow.h"
#include "return.h"
#include "history.h"
#include "inventory.h"

using namespace std;

class Store {
public:
  Store();
  ~Store();

  void buildMovies(ifstream& file);
  void buildCustomer(ifstream& file);
  void processTransaction(ifstream& file);
  Movie* getInventory(int i);
  HashTable<Customer> getCustomerInfo();
  int getSize();

private:
  int size;
  Movie* inventory[1000];
  HashTable<Customer> customerInfo;

};
#endif