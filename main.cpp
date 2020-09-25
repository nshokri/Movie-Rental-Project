#include <iostream>
#include <fstream>
#include <string>

#include "store.h"
#include "customer.h"
#include "hashtable.h"

#include "movie.h"
#include "drama.h"
#include "comedy.h"
#include "classics.h"
#include "moviefactory.h"

#include "transaction.h"
#include "borrow.h"
#include "return.h"
#include "history.h"
#include "inventory.h"
#include "transactionfactory.h"

using namespace std;

// Other *Name removed for privacy*:
//  - transaction classes
//    - borrow
//    - return
//    - history
//    - inventory
//  - store class
// Nick:
//  - movie classes
//    - drama
//    - comedy
//    - classics
//  - MovieFactory
//  - TransactionFactory
//  - hash table
//  - customer class

int main() {

  ifstream infileM("data4movies.txt");
    if (!infileM) {
      cout << "File could not be opened." << endl;
      return 1;
  }
  ifstream infileC("data4customers.txt");
    if (!infileC) {
      cout << "File could not be opened." << endl;
      return 1;
  }
  ifstream infileT("data4commands.txt");
    if (!infileT) {
      cout << "File could not be opened." << endl;
      return 1;
  }
  
  Store s;
  cout << "building movies:" << endl;
  s.buildMovies(infileM);
  cout << "building customers:" << endl;
  s.buildCustomer(infileC);
  cout << "processing transactions:" << endl;
  s.processTransaction(infileT);

}
