// -------------------------------- return.cpp ----------------------------------

// Design Group 4
// CSS 343
// Created: 8/15/2020
// Last Modified: 8/19/2020

// ----------------------------------------------------------------------------

// Return Class:

// ----------------------------------------------------------------------------

// Notes on specifications, special algorithms, and assumptions.

//
//
//

//
#include "return.h"

Return::Return()
{

}

Return::Return(Movie * m, int ID)
{
  movie = m;
  int id = ID;
}

Return::~Return()
{
  delete movie;
}

void Return::executeTransaction(Store *s)
{
  if (s->getCustomerInfo().retrieve(id) == NULL)
  {
    cout << "Invalid customer ID for return command: " << id << endl;
    return;
  }
  for (int i = 0; i < s->getSize(); i++)
  {
    if (*movie == *s->getInventory(i))
    {
      s->getInventory(i)->addStock();
      s->getCustomerInfo().retrieve(id)->getTransactionHistory().push_back(this);
      return;
    }
  }
}

void Return::printInfo()
{
  cout << id << " ";
  movie->print();
}