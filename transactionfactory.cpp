// ------------------------------ transactionFactory.cpp -------------------------------

// Implementation Group 13
// CSS 343
// Created: 8/12/2020
// Last Modified: 8/21/2020

// ----------------------------------------------------------------------------

// TransactionFactory Class:
// class used by class Store for the creaton of transaction objects

// ----------------------------------------------------------------------------

// Notes on specifications, special algorithms, and assumptions.

//
//
//

//
#include "transactionfactory.h"
#include <string>
#include <sstream>

TransactionFactory::TransactionFactory()
{

}

TransactionFactory::~TransactionFactory()
{
  
}

bool TransactionFactory::createTransaction(string line, Transaction& t, Store* s)
{
  //B 8000 D F You've Got Mail, 1998
  
  stringstream input(line);
  string first;
  input >> first;
  char type = first[0];
  char media, mType;
  string title, name, actor;
  int id, year, month, comma;

  switch(type)
  {
    // inventory
    case 'I' :
    t = Inventory();
    break;

    // history
    case 'H' :
    if (!(input >> id))
      return false;
    t = History(id);
    break;

    // borrow
    case 'B' :
    if (!(input >> id))
      return false;
      // this part could be turned into a helper method for convenience
    input >> first;
    media = first[0];
    if (media == 'D')
    {
      input >> first;
      mType = first[0];
      switch(mType)
      {
        // comedy
        case 'F' :
        comma = input.str().find(", ");
        name = input.str().substr(0, comma + 1);
        year = stoi(input.str().substr(comma + 2));
        for (int i = 0; i < s->getSize(); i++)
        {
          if (s->getInventory(i)->getType() == mType)
          {
            if (s->getInventory(i)->getTitle().compare(name) == 0 &&
            s->getInventory(i)->getYear() == year)
            {
              t = Borrow(s->getInventory(i), id);
              return true;
            }
          }
        }
        return false;
        break;

        // drama
        case 'D' :
        //B 1000 D D Barry Levinson, Good Morning Vietnam,
        comma = input.str().find(", ");
        actor = input.str().substr(0, comma + 1);
        name = input.str().substr(comma + 2, input.str().size() - comma + 1);
        for (int i = 0; i < s->getSize(); i++)
        {
          if (s->getInventory(i)->getType() == mType)
          {
            if (s->getInventory(i)->getTitle().compare(name) == 0 &&
            s->getInventory(i)->getDirector().compare(actor) == 0)
            {
              t = Borrow(s->getInventory(i), id);
              return true;
            }
          }
        }

        break;

        // classic
        case 'C' :
        input >> month;
        input >> year;
        actor = input.str();
        for (int i = 0; i < s->getSize(); i++)
        {
          if (s->getInventory(i)->getType() == mType)
          {
            if (s->getInventory(i)->getYear() == year &&
            s->getInventory(i)->getDirector().compare(actor) == 0)
            {
              t = Borrow(s->getInventory(i), id);
              return true;
            }
          }
        }

        break;
      }
    }
    else
      return false;
    break;

    // return
    case 'R' :
    if (!(input >> id))
      return false;
    input >> first;
    media = first[0];
    if (media == 'D')
    {
      input >> first;
      mType = first[0];
      switch(mType)
      {
        // comedy
        case 'F' :
        comma = input.str().find(", ");
        name = input.str().substr(0, comma + 1);
        year = stoi(input.str().substr(comma + 2));
        for (int i = 0; i < s->getSize(); i++)
        {
          if (s->getInventory(i)->getType() == mType)
          {
            if (s->getInventory(i)->getTitle().compare(name) == 0 &&
            s->getInventory(i)->getYear() == year)
            {
              t = Return(s->getInventory(i), id);
              return true;
            }
          }
        }
        return false;
        break;

        // drama
        case 'D' :
        comma = input.str().find(", ");
        actor = input.str().substr(0, comma + 1);
        name = input.str().substr(comma + 2, input.str().size() - comma + 1);
        for (int i = 0; i < s->getSize(); i++)
        {
          if (s->getInventory(i)->getType() == mType)
          {
            if (s->getInventory(i)->getTitle().compare(name) == 0 &&
            s->getInventory(i)->getDirector().compare(actor) == 0)
            {
              t = Return(s->getInventory(i), id);
              return true;
            }
          }
        }
        return false;
        break;

        // classic
        case 'C' :
        input >> month;
        input >> year;
        actor = input.str();
        for (int i = 0; i < s->getSize(); i++)
        {
          if (s->getInventory(i)->getType() == mType)
          {
            if (s->getInventory(i)->getYear() == year &&
            s->getInventory(i)->getDirector().compare(actor) == 0)
            {
              t = Return(s->getInventory(i), id);
              return true;
            }
          }
        }
        return false;
        break;
      }
    }
    else
      return false;
    break;
  }
  return true;
}

