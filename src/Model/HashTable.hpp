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
    long nextPrime(long current);
    long findPosition(HashNode<Type> * data);
    long handleCollision(HashNode<Type> * data, long currentPosition);

    int getNextPrime();
public:
    HashTable();
    ~HashTable();
    void add(Type data);
    bool remove(Type data);
    void displayContenets();

    };

template<class Type>
HashTable<Type>::HashTable()
    {
    this->capacity = 101;
    this->efficiencyPercentage = 0.667;
    this->size = 0;
storage= HashNode<Type>* [capacity];
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
int HashTable<Type>::getNextPrime()
{
int nextPrime = (this->capacity * 2) + 1;
while (!isPrime(nextPrime))
    {
    nextPrime++;
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
    if (position > capacity)
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
#endif /* MODEL_HASHTABLE_HPP_ */
