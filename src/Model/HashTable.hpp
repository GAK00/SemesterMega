/*
 * HashTable.hpp
 *
 *  Created on: May 1, 2017
 *      Author: gkun9931
 */

#ifndef MODEL_HASHTABLE_HPP_
#define MODEL_HASHTABLE_HPP_
#include<cmath>
#include<assert.h>
#include"HashNode.hpp"
using namespace std;
template<class Type>
class HashTable
    {
private:
    long capacity;
    long size;
    double efficiencyPercentage;
    Type * * storage;
    bool isPrime(long sampleNumber);
    void resize();
    long nextPrime();
    long findPosition(HashNode<Type> * data);
    long handleCollision(HashNode<Type> * data, long currentPosition);
public:
    HashTable();
    ~HashTable();
    void add(Type data);
    bool remove(Type data);
    void displayContents();
    long getSize();

    };
template<class Type>
long HashTable<Type> ::getSize()
	    {
    return size;
	    }
template<class Type>
HashTable<Type>::HashTable()
    {
    this->capacity = 101;
    this->efficiencyPercentage = 0.667;
    this->size = 0;
storage= new HashNode<Type>* [capacity];
    fill_n(storage,capacity,nullptr);

}
template<class Type>
HashTable<Type>::~HashTable()
{
delete[] storage;
}
template<class Type>
bool HashTable<Type>::isPrime(long canidate)
{
if (canidate <= 1)
    {
    return false;
    }
else if (canidate == 2 || canidate == 3)
    {
    return true;
    }
else if (canidate % 2 == 0)
    {
    return false;
    }
else
    {
    for (int next = 3; next <= sqrt(canidate) + 1; next += 2)
	{
	if (canidate % next == 0)
	    {
	    return false;
	    }
	}
    return true;
    }

}

template<class Type>
long HashTable<Type>::nextPrime()
{
long nextPrime = (this->capacity * 2) + 1;
while (!isPrime(nextPrime))
    {
    nextPrime += 2;
    }
return nextPrime;
}

template<class Type>
long HashTable<Type>::findPosition(HashNode<Type> * data)
{
long insertPosition = data->getKey() % this->capacity;
return insertPosition;
}
template<class Type>
long HashTable<Type>::handleCollision(HashNode<Type>*data, long currentPosition)
{
long shift = 17;
for (long position = currentPosition + shift; position != currentPosition; position += shift)
    {
    if (position >= capacity)
	{
	position = position % capacity;

	if (storage[currentPosition] == nullptr)
	    {
	    return position;
	    }
	}
    }
return -1;

}
template<class Type>
bool HashTable<Type>::remove(Type data)
{
bool removed = false;
//    for(long index = 0; index < capacity; index++)
//	{
//	    if(storage[index] != nullptr && storage[index]->getData() == data)
//		{
//		    storage[index] = nullptr;
//		    removed = true;
//		}
//	}
HashNode<Type> * find(data);
long hashIndex = findPosition(find);
if (storage[hashIndex] != nullptr)
    {
    storage[hashIndex] = nullptr;
    removed = true;
    this->size--;
    }
return removed;
}
template<class Type>
void HashTable<Type>::displayContents()
{
for (long index = 0; index < capacity; index++)
    {
    if (storage[index] != nullptr)
	{
	cout << index << ":" << storage[index];
	}
    }
}
template<class Type>
void HashTable<Type>::resize()
{
long updatedSize = nextPrime();
HashNode<Type> ** tempStorage = new HashNode<Type> *[updatedSize];
fill_n(tempStorage, updatedSize, nullptr);
long oldCapacity = this->capacity;
this->capacity = updatedSize;
for (long index = 0; index < oldCapacity; index++)
    {
    if (storage[index] != nullptr)
	{
	HashNode<Type> * temp = storage[index];
	long pos = findPosition(temp);
	if (tempStorage[pos] == nullptr)
	    {
	    tempStorage[pos] = temp;
	    }
	else
	    {
		long updatedPosition = handleCollision(temp, pos);
		tempStorage[updatedPosition] = temp;
	    }
	}
    }
storage = tempStorage;
}
template<class Type>
void HashTable<Type> :: add(Type toAdd)
    {
    this -> size++;
    if(((size*1.000)/capacity)>efficiencyPercentage)
	    {
		resize();
	    }
    HashNode<Type>  * temp;
    int pos = findPosition(temp);
    if(storage[pos] == nullptr)
	{
	storage[pos] = temp;
	}
    else
	{
	storage[hadleCollision(temp,pos)] = temp;
	}
    }
#endif /* MODEL_HASHTABLE_HPP_ */
