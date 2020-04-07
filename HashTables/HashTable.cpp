/*
	Vento, Jack
	
	April 11, 2020

	CS A200
	Lab 3: Quadratic Probing
*/

#include "HashTable.h"

// default constructor
HashTable::HashTable()
{
	capacity = CAPACITY;
	numOfElements = 0;

	table = new int[capacity] {-1};
}

// overloaded constructor
HashTable::HashTable(int newCap)
	: capacity(newCap)
{
	numOfElements = 0;
	table = new int[capacity] {-1};
}

// copy constructor


// move constructor


// insert


// overloaded assignment operator


// move assignment operator


// search


// getCapacity


// subscript operator


// emptyTable


// Destructor


// hashValue