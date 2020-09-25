// ------------------------------- history.cpp ----------------------------------

// Design Group 4
// CSS 343
// Created: 8/11/2020
// Last Modified: 8/20/2020

// ----------------------------------------------------------------------------

// History Class:

// ----------------------------------------------------------------------------

// Notes on specifications, special algorithms, and assumptions.

//
//
//

//
#include "history.h"

History::History()
{

}

History::History(int ID)
{
  id = ID;
}

History::~History()
{

}

void History::executeTransaction(Store *s)
{
  Customer * c = s->getCustomerInfo().retrieve(id);
  if (c != NULL)
  {
    for (int i = 0; i < c->getTransactionHistory().size(); i++)
    {
      c->getTransactionHistory().at(i)->printInfo();
    }
  }
  else
  {
    cout << "Invalid customer ID for history command: " << id << endl;
  }
}

void History::printInfo()
{
  
}