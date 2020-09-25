// ------------------------------ store.cpp ---------------------------------

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

#include "store.h"

// default constructor
Store::Store()
{
  size = 0;
}

// destructor
Store::~Store()
{
  // todo: delete contents of inventory
}

void Store::buildMovies(ifstream &file)
{
  cout << "TEST";
  string line;
  MovieFactory mf;
  while (getline(file, line))
  {
    Movie * m;
    
    if (mf.createMovie(m, line))
    {
      inventory[size++] = m;
    }
    else
    {
      cout << "invalid movie: " << line << endl;
    }
  }
}

void Store::buildCustomer(ifstream &file)
{
  // line example:
  // 2000 Duck Donald
  string line;
  while (!file.eof())
  {
    int id;
    string first, last;
    file >> id;
    file >> last;
    file >> first;
    Customer * c = new Customer(id, first, last);
    customerInfo.add(id, c);
  }
}

// --------------- processTransaction ---------------
// takes transaction commands from a file and processes them
// preconditions: none
// postconditions: all valid commands from ifstream &file will
//  will be processed
void Store::processTransaction(ifstream &file)
{
  TransactionFactory fact;
  string line;
  while (getline(file, line))
  {
    Transaction t;
    if (fact.createTransaction(line, t, this))
    {
      t.executeTransaction(this);
    }
    else
    {
      cout << "invalid transaction: " << line << endl;
    }
  }
}

int Store::getSize()
{
  return size;
}

Movie* Store::getInventory(int i)
{
  if (i >= 0 && i < 1000)
    return inventory[i];
  return NULL;
}

HashTable<Customer> Store::getCustomerInfo()
{
  return customerInfo;
}
