/*
	Vento, Jack

	April 11, 2020

	CS A200
	Lab 3: Quadratic Probing
*/

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
using namespace std;

class HashTable
{
public:
	// default constructor
	HashTable();

	// overloaded constructor
	HashTable(int newCap);

	// copy constructor
	HashTable(const HashTable& other);

	// move constructor
	HashTable(const HashTable&& other);

	// insert
	void insert(int key);

	// overloaded assignment operator
	HashTable& operator=(const HashTable& rhs);

	// move assignment operator
	HashTable& operator=(const HashTable&& rhs);

	// search
	bool search(int key) const;

	// getCapacity
	int getCapacity() const;

	// subscript operator
	int& operator[](int key);

	// emptyTable
	void emptyTable();

	// Destructor
	~HashTable();

private:
	// hashValue
	int hashValue(int j, int key);
	
	int *table;							//pointer to the hash table
    int numOfElements;					//number of items in the hash table
	int capacity;						//maximum length of the hash table	
    const static int CAPACITY = 11;		//maximum length of the hash table	
										
};

#endif
