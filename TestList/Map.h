#define MAP_H_
#ifdef MAP_H_

#pragma once
#include "stdafx.h"
using namespace std;

template<class _Type> 
class Node
{
	string _Info;
	Simple_Array<_Type*> _connections;	
	Node* _next;
};

template<class _Type>
class Map
{
public:
	Map();
	explicit Map(float _size);
	~Map();

	float getSize() const { return _size; }
	void addNode(Node<_Type>*);

private:
	Node<_Type>* _front_Ptr;
	float _size;
	const float _max_Size;
};

template <class _Type>
Map<_Type>::Map()
	: _size(0), _max_Size(0)
{ }
template <class _Type>
Map<_Type>::Map(float _size)
	: _size(0), _max_Size(_size)
{ }
template <class _Type>
Map<_Type>::~Map()
{ }

template <class _Type>
void Map<_Type>::addNode(Node<_Type>* _Node)
{
	if(_front_Ptr == nullptr){
		_front_Ptr = (Node<_Type>*)malloc(sizeof(Node<_Type>));
		_front_Ptr = _Node;
		return;
	}
	Node<_Type>* _aux_Ptr = _front_Ptr;
	while (true)
	{
		_aux_Ptr = _aux_Ptr->_next;
	}
}

#endif
