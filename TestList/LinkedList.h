#define LINKED_LIST_H
#include <string>
#ifdef LINKED_LIST_H

#ifndef __cplusplus
#error A C++ compiler is required!
#endif 

#include "stdafx.h"
#include <cstdlib>
#pragma once

#define  TRUE  1 
#define  FALSE 0 

#define null nullptr

template <class T>
class BinaryTree {
	
	struct TreeNode {
		int _Index; 
		T _Item; 
		
		TreeNode* _Right; 
		TreeNode* _Left;
	};


	TreeNode* _Root;
	int _Size;
	TreeNode* newNode(int _code_i, T value_r);
	int maxDepth(TreeNode* node);

	void listTree(TreeNode* node);
	
public:

	BinaryTree<T>()
		: _Root(null), _Size(0) { }

	bool find(int target) const;
	void insert(int code, T value_i);

	int size() const;
	int maxDepth();
	T minValue(TreeNode* node);
	void listTree();
};

template <class T>
class Simple_Array_
{
	struct Node { T _Item; Node* _Next; };
	Node* _Front_Ptr;
	int _size;

public:
	void push_back(T _value);
	void pop_Back();
	T operator [](int _Index);
	void addAt(unsigned int _Index, T _data);
	void removeAt(unsigned int _Index);
	void Clear();
	T front();
	T back();
	T find(T _value);
	bool contains(T _value);
	void display() const;
	unsigned int isEmpty() const;
	int size() const;

	long int hashcode() const;

	Simple_Array_<T>();
	~Simple_Array_<T>();
};


template <class T>
bool BinaryTree<T>::find(int target) const
{
	TreeNode* _Ptr = _Root;
	if (_Ptr == null) return FALSE;
	else while (_Ptr != null) {
		if (target < _Ptr->_Index) {
			_Ptr = _Ptr->_Left;

		}
		else {
			_Ptr = _Ptr->_Right;
		}
		if (_Ptr != null && _Ptr->_Index == target) return TRUE;
	}
	return FALSE;
}

template <class T>
void BinaryTree<T>::insert(int code, T value_i)
{
	if (_Root == null) { _Root = newNode(code, value_i); return; }
	if (!find(code)) {
		TreeNode* _Ptr = _Root;
		while (true) {
			if (_Ptr->_Item < value_i) {
				if (_Ptr->_Right != null) _Ptr = _Ptr->_Right;
				else {
					_Ptr->_Right = newNode(code, value_i);
					break;
				}
			}
			else {
				if (_Ptr->_Left != null) _Ptr = _Ptr->_Left;
				else {
					_Ptr->_Left = newNode(code, value_i);
					break;
				}
			}
		}
	}
}

template <class T>
int BinaryTree<T>::size() const {
	if (_Root == null) return 0;
	return _Size;
}

template <class T>
typename BinaryTree<T>::TreeNode* BinaryTree<T>::newNode(int _code_i, T value_r) {
	TreeNode* ptr = new TreeNode;
	ptr->_Index = _code_i;
	ptr->_Item = value_r;
	ptr->_Left = null;
	ptr->_Right = null;
	_Size++;
	return ptr;
}

template <class T>
int BinaryTree<T>::maxDepth(TreeNode* node)
{
	if (node == null) { return 0; }
	else {
		int lDepth = maxDepth(node->_Left);
		int rDepth = maxDepth(node->_Right);
		if (lDepth > rDepth) return lDepth + 1;
		else return rDepth + 1;
	}
}

template <class T>
int BinaryTree<T>::maxDepth() {
	return maxDepth(_Root);
}

template <class T>
T BinaryTree<T>::minValue(TreeNode* node) {

}

template <class T>
void BinaryTree<T>::listTree(TreeNode* node) {
	if (node == null) {
		return;
	}

	listTree(node->_Left);
	int a = node->_Index;
	int* b = node->_Item;
	int* c = new int(-1);
	int* d = new int(-1);
	if (node->_Right != nullptr) {
		c = node->_Right->_Item;
	}
	if (node->_Left != nullptr) {
		d = node->_Left->_Item;
	}
	std::cout << "<NODE ID: " + std::to_string(a) +
		" || DATA-> " + std::to_string(*b) + 
		" || RIGHT-> " + std::to_string(*c) + 
		" || LEFT->" + std::to_string(*d) +">" << std::endl;
	listTree(node->_Right);
}

template <class T>
void BinaryTree<T>::listTree() {
	listTree(_Root);
}

/* LINKED LIST */

template <class T>
void Simple_Array_<T>::push_back(T _value)
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

		while (_Ptr != nullptr) {
			_Prev_Ptr = _Ptr;
			_Ptr = _Ptr->_Next;
		}

		_Ptr = static_cast<Node*>(malloc(sizeof(Node)));
		_Prev_Ptr->_Next = _Ptr;
		_Ptr->_Item = _value;
		_Ptr->_Next = nullptr;
		_size++;
	}
	fflush(stdin);
}

template <class T>
void Simple_Array_<T>::pop_Back()
{
	if (_Front_Ptr == nullptr) return;
	Node* _Ptr = _Front_Ptr;
	Node* _Prev_Ptr;
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

template <class T>
T Simple_Array_<T>::operator[](int _Index)
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

template <class T>
inline void Simple_Array_<T>::addAt(unsigned _Index, T _data) {
	int _curr_Index = 1;
	Node* _Ptr = _Front_Ptr;
	Node* _last_Ptr = nullptr;
	Node* _New_Data_;
	if (_Index == 1) {
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
		_New_Data_ = (Node*)malloc(sizeof(Node));
		_New_Data_->_Item = _data;
		_New_Data_->_Next = _Ptr;
		_last_Ptr->_Next = _New_Data_;
	}
	_size++;
}

template <class T>
inline void Simple_Array_<T>::removeAt(unsigned _Index)
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

template <class T>
void Simple_Array_<T>::Clear()
{
	Node* _Ptr = _Front_Ptr;
	Node* _aux__Ptr = _Front_Ptr;
	while (_Ptr != nullptr) {
		_Ptr = _aux__Ptr;
		if (_Ptr->_Next == nullptr) {
			free(_aux__Ptr);
			_size--;
			break;
		}
		_aux__Ptr = _Ptr->_Next;
		free(_Ptr);
		_size--;
	}
}

template <class T>
T Simple_Array_<T>::front()
{
	if (_Front_Ptr == nullptr) return NULL;
	return _Front_Ptr->_Item;
}

template <class T>
T Simple_Array_<T>::back()
{
	Node* _Ptr = _Front_Ptr;
	while (_Ptr != nullptr) {
		if (_Ptr->_Next == nullptr) break;
		_Ptr = _Ptr->_Next;
	}
	return _Ptr->_Item;
}

template <class T>
T Simple_Array_<T>::find(T _value)
{
	Node* _Ptr = _Front_Ptr;
	while (_Ptr->_Next != nullptr) {
		if(_Ptr == _value) return _Ptr;
		_Ptr = _Ptr->_Next;
	}
	return FALSE;
}

template <class T>
bool Simple_Array_<T>::contains(T _value)
{
	if (find(_value) != nullptr) return TRUE; 
	return FALSE;
}

template <class T>
void Simple_Array_<T>::display() const
{
	Node* _Ptr = _Front_Ptr;
	while (_Ptr->_Next != nullptr) {
		std::cout << _Ptr->_Item << std::endl;
		_Ptr = _Ptr->_Next;
	}
}

template <class T>
unsigned Simple_Array_<T>::isEmpty() const
{
	if (size() == 0) return TRUE;
	return FALSE;
}

template <class T>
int Simple_Array_<T>::size() const
{
	return _size;
}

template <class T>
long int Simple_Array_<T>::hashcode() const {
	long double i = 2352338.2492847;
	size_t r = sizeof i;
	return r;
}

template <class T>
Simple_Array_<T>::Simple_Array_<T>(): _Front_Ptr{nullptr},
                                   _size{0}
{
}

template <class T>
Simple_Array_<T>::~Simple_Array_<T>()
{
}

#endif //LINKED_LIST_H


