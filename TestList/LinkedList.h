#define LINKED_LIST_H
#ifdef LINKED_LIST_H

#ifndef __cplusplus
#error A C++ compiler is required!
#endif 

#include "stdafx.h"
#include <cstdlib>
#pragma once

#define  TRUE  1
#define  FALSE 0

template<class T> class Simple_Array
{
	typedef struct Node {
		T _Item;
		Node* _Next;
	};

	Node* _Front_Ptr;
	int _size;
public:

	void push_back(T _value)
	{
		if (_Front_Ptr == nullptr) {
			_Front_Ptr = (Node*)(malloc(sizeof(Node)));
			_Front_Ptr->_Item = _value;
			_Front_Ptr->_Next = nullptr;
			_size++;
		}
		else {
			Node* _Prev_Ptr = _Front_Ptr;
			Node* _Ptr = _Front_Ptr;

			while (_Ptr != nullptr)
			{
				_Prev_Ptr = _Ptr;
				_Ptr = _Ptr->_Next;
			}

			_Ptr = (Node*)malloc(sizeof(Node));
			_Prev_Ptr->_Next = _Ptr;
			_Ptr->_Item = _value;
			_Ptr->_Next = nullptr;
			_size++;
		}
		fflush(stdin);
	}

	void pop_Back()
	{
		if (_Front_Ptr == nullptr) return;
		Node* _Ptr = _Front_Ptr;
		Node* _Prev_Ptr = _Front_Ptr;
		while (_Ptr != nullptr) {
			_Prev_Ptr = _Ptr;
			_Ptr = _Ptr->_Next;
			if (_Ptr->_Next == nullptr) {
				_Prev_Ptr->_Next = nullptr;
				free(_Ptr);
				_size--;
				break;
			}
		}
	}

	T operator [](int _Index)
	{
		int _curr_Index = 0;
		Node* _Ptr = _Front_Ptr;
		if (_Ptr != nullptr) {
			while (_curr_Index < _Index) {
				_Ptr = _Ptr->_Next;
				if (_Ptr == nullptr) return 0;
				_curr_Index++;
			}
			return _Ptr->_Item;
		}
		return 0;
	}

	void addAt(unsigned int _Index, T _data)
	{
		int _curr_Index = 1;
		Node* _Ptr = _Front_Ptr;
		Node* _last_Ptr = nullptr;
		Node* _New_Data_;
		if(_Index == 1){
			_last_Ptr = _Ptr;
			_New_Data_ = (Node*)malloc(sizeof(Node));
			_New_Data_->_Item = _data;
			_New_Data_->_Next = _last_Ptr;
			_Front_Ptr = _New_Data_;
		}
		else {
			while (_Ptr != nullptr) {
				_curr_Index++;
				_last_Ptr = _Ptr;
				_Ptr = _Ptr->_Next;
				if (_curr_Index == _Index)
					break;
			}
			_New_Data_ = (Node*)(malloc(sizeof(Node)));
			_New_Data_->_Item = _data;
			_New_Data_->_Next = _Ptr;
			_last_Ptr->_Next = _New_Data_;	
		}
		_size++;
	}

	void removeAt(unsigned int _Index)
	{
		unsigned short int _curr_Index = 1;
		Node* _Ptr = _Front_Ptr;
		//Remove The first Node
		if (_Index == 1) {
			_Front_Ptr = _Ptr->_Next;
			free(_Ptr);
			_size--;
		}

		else {
			Node* _last_Ptr = _Front_Ptr;
			while (_Ptr != nullptr) {
				_curr_Index++;
				_last_Ptr = _Ptr;
				_Ptr = _Ptr->_Next;
				if (_curr_Index == _Index) {
					_size--;
					break;
				}
			}
			_last_Ptr->_Next = _Ptr->_Next;
			free(_Ptr);
		}
	}

	void Clear()
	{
		Node* _Ptr = _Front_Ptr;
		Node* _aux__Ptr = _Front_Ptr;
		while (_Ptr != nullptr) {
			_Ptr = _aux__Ptr;
			if (_Ptr->_Next == nullptr){
				free(_aux__Ptr);
				_size--;
				break;
			}
			_aux__Ptr = _Ptr->_Next;
			free(_Ptr);
			_size--;
		}
	}

	T front()
	{
		if (_Front_Ptr == nullptr) return NULL;
		return _Front_Ptr->_Item;
	}

	T back()
	{
		Node* _Ptr = _Front_Ptr;
		while (_Ptr != nullptr) {
			if (_Ptr->_Next == nullptr)
				break;
			_Ptr = _Ptr->_Next;
		}
		return _Ptr->_Item;
	}

	unsigned int isEmpty() const
	{
		if (size() == 0) return TRUE;
		return FALSE;
	}

	int size() const {
		return _size;
	}

	Simple_Array()
		: _Front_Ptr{ nullptr },
		_size{ 0 }
	{ }

	~Simple_Array()
	{ }
};

#endif //LINKED_LIST_H
