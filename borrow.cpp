// -------------------------------- borrow.cpp ----------------------------------

// Design Group 4
// CSS 343
// Created: 8/15/2020
// Last Modified: 8/19/2020

// ----------------------------------------------------------------------------

// Borrow Class:

// ----------------------------------------------------------------------------

// Notes on specifications, special algorithms, and assumptions.

//
//
//

//
#include "borrow.h"

Borrow::Borrow()
{

}

Borrow::Borrow(Movie * m, int ID)
{
  movie = m;
  id = ID;
}

Borrow::~Borrow()
{
  // we do need to delete the movie
  delete movie;
}

void Borrow::executeTransaction(Store *s)
{
  if (s->getCustomerInfo().retrieve(id) == NULL)
  {
    cout << "Invalid customer ID for borrow command: " << id << endl;
    return;
  }
  for (int i = 0; i < s->getSize(); i++)
  {
    if (*movie == *s->getInventory(i))
    {
      s->getInventory(i)->removeStock();
      s->getCustomerInfo().retrieve(id)->getTransactionHistory().push_back(this);
      return;
    }
  }
}

void Borrow::printInfo()
{
  cout << id << " ";
  movie->print();
}