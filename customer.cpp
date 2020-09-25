#include "customer.h"

Customer::Customer(int id, string firstName, string lastName)
{
	this->id = id;
	this->firstName = firstName;
	this->lastName = lastName;
}

Customer::~Customer()
{
	for (Transaction* n : transactionHistory)
	{
		delete n;
	}
}

int Customer::getID() const
{
	return id;
}

string Customer::getName() const
{
	return firstName + " " + lastName;
}

//Since it returns a pointer, you can change the history directly
vector<Transaction*> Customer::getTransactionHistory()
{
	return transactionHistory;
}
