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

	table = new int[capacity];
	for (int i = 0; i < capacity; ++i)
		table[i] = -1;
}

// overloaded constructor
HashTable::HashTable(int newCap)
	: capacity(newCap)
{
	numOfElements = 0;

	table = new int[capacity];
	for (int i = 0; i < capacity; ++i)
		table[i] = -1;
}

// copy constructor
HashTable::HashTable(const HashTable& other)
{
	capacity = other.capacity;
	numOfElements = other.numOfElements;

	table = new int[capacity];
	for (int i = 0; i < capacity; ++i)
		table[i] = other.table[i];
}

// move constructor
HashTable::HashTable(HashTable&& other)
{
	capacity = other.capacity;
	numOfElements = other.numOfElements;
	table = other.table;

	other.capacity = 0;
	other.numOfElements = 0;
	other.table = nullptr;
}

// insert
void HashTable::insert(int key)
{
	if (numOfElements != capacity)
	{
		auto j = 0, cycle = (capacity + 1) / 2;
		auto inserted = false;

		while (!inserted)
		{
			auto hash = hashValue(j, key);
			if (table[hash] == -1)
			{
				table[hash] = key;
				++numOfElements;
				inserted = true;
			}
			else
				++j;

			if (j == cycle)
			{
				cerr << "Could not insert key. Need to rehash." << endl;
				inserted = true;
			}
		}
	}
	else
		cerr << "Table is full. Cannot insert." << endl;
}

// overloaded assignment operator
HashTable& HashTable::operator=(const HashTable& rhs)
{
	if (this != &rhs)
	{
		numOfElements = rhs.numOfElements;

		if (capacity != rhs.capacity)
		{
			capacity = rhs.capacity;

			delete[] table;
			table = new int[capacity];
		}

		for (int i = 0; i < capacity; ++i)
		{
			table[i] = rhs.table[i];
		}
	}
	else
		cerr << "Cannot self assign.";

	return *this;
}

// move assignment operator
HashTable& HashTable::operator=(HashTable&& rhs)
{
	if (this != &rhs)
	{
		capacity = rhs.capacity;
		numOfElements = rhs.numOfElements;

		delete[] table;
		table = rhs.table;

		rhs.capacity = 0;
		rhs.numOfElements = 0;
		rhs.table = nullptr;

	}
	else
		cerr << "Cannot self assign.";

	return *this;
}

// search
bool HashTable::search(int key) const
{
	if (numOfElements != 0)
	{
		auto j = 0, cycle = (capacity + 1) / 2;
		auto found = false;

		while (j != cycle)
		{
			auto hash = hashValue(j, key);
			auto currKey = table[hash];

			if (currKey == key)
				return true;
			else if (currKey == -1)
				return false;
			else
				++j;
		}

		return false;
	}
	else
	{
		cerr << "Hash table is empty.";
		return false;
	}
}

// getCapacity
int HashTable::getCapacity() const
{
	return capacity;
}

// subscript operator
int& HashTable::operator[](int idx) const
{
	return table[idx];
}

// emptyTable
void HashTable::emptyTable()
{
	for (int i = 0; i < capacity; ++i)
		table[i] = -1;

	numOfElements = 0;
}

// Destructor
HashTable::~HashTable()
{
	delete[] table;
	table = nullptr;
}

// hashValue
int HashTable::hashValue(int j, int key) const
{
	return ((2 * key + 5) + (j * j)) % capacity;
}