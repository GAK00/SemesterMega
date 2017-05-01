/*
 * HashNode.hpp
 *
 *  Created on: May 1, 2017
 *      Author: gkun9931
 */

#ifndef MODEL_HASHNODE_HPP_
#define MODEL_HASHNODE_HPP_
template<class Type>
class HashNode
    {
    private:
	Type data;
	long key;
    public:
	HashNode();
	HashNode(Type data);


	Type getData();
	long getKey() const;
	void setData(Type data);
    };

template <class Type>
HashNode<Type> :: HashNode()
    {
	this-> key = rand();
    }
template<class Type>
HashNode<Type> :: HashNode(Type data)
    {
    this->key = rand();
     this->data = data;
    }
template <class Type>
Type HashNode<Type> :: getData()
    {
    return data;
    }
template <class Type>
long HashNode<Type> :: getKey() const
    {
    return key;
    }
template <class Type>
void HashNode<Type> :: setData(Type data)
    {
	this->data = data;
    }


#endif /* MODEL_HASHNODE_HPP_ */
