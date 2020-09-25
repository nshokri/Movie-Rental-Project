// ------------------------------ hashtable.h ---------------------------------

// Design Group 4
// CSS 343
// Created:
// Last Modified:

// ----------------------------------------------------------------------------

// HashTable Class:

// ----------------------------------------------------------------------------

// Notes on specifications, special algorithms, and assumptions.

//
//
//

//

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>

using namespace std;

template <typename T>
class HashTable {
public:
    HashTable();
    ~HashTable();

    bool add(int key, T* item);
    T* retrieve(int key);
    bool remove(int key);

    T* find(T key);

private:

    class Node
    {
    public:
        T* data;
        int key;
        
        Node* next;
    };

    const static int TABLE_SIZE = 7919; //Can change size to any prime number
    Node* table[TABLE_SIZE]; 
        
    int getHash(int);

};
#endif