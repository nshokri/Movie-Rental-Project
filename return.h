// -------------------------------- return.h ----------------------------------

// Design Group 4
// CSS 343
// Created: 8/11/2020
// Last Modified: 8/19/2020

// ----------------------------------------------------------------------------

// Return Class:

// ----------------------------------------------------------------------------

// Notes on specifications, special algorithms, and assumptions.

//
//
//

//

#ifndef RETURN_H
#define RETURN_H

#include <iostream>
#include "transaction.h"
#include "store.h"
#include "movie.h"
#include "hashtable.h"

using namespace std;

class Return : public Transaction {
public:
  Return();
  Return(Movie * m, int ID);
  ~Return();

  void executeTransaction(Store* s);
  //void findMovie(Movie*& m, HashTable<Movie>& movies);
  void printInfo();
private:
  Movie* movie;
  int id;
};
#endif