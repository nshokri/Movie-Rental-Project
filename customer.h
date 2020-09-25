// -------------------------------- customer.h --------------------------------

// Design Group 4
// CSS 343
// Created:
// Last Modified:

// ----------------------------------------------------------------------------

// Customer Class:

// ----------------------------------------------------------------------------

// Notes on specifications, special algorithms, and assumptions.

//
//
//

//

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <vector>
#include "transaction.h"

using namespace std;

class Customer {
public:
    Customer(int id, string firstName, string lastName);
    virtual ~Customer();

    int getID() const;
    string getName() const;

    vector<Transaction*> getTransactionHistory();

private:
    int id;
    string firstName;
    string lastName;
    vector<Transaction*> transactionHistory;
};
#endif