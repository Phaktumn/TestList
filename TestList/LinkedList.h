#define LINKED_LIST_H
#include <string>
#include <iomanip>
#ifdef LINKED_LIST_H

#ifndef __cplusplus
#error A C++ compiler is required!
#endif 

#include "stdafx.h"
#include <cstdlib>
#pragma once

#define  TRUE  1 
#define  FALSE 0 

#undef COMPACT

#define null nullptr

template <class T>
class BinaryTree {
	
	struct TreeNode {
		int _Index; 
		int _Item; 
		
		T _Info;

		TreeNode* _Right; 
		TreeNode* _Left;
	};

	TreeNode* _Root;
	int _Size;
	TreeNode* newNode(int _code_i, int value_r, T info);
	int maxDepth(TreeNode* node);
	void insert(TreeNode* node, int code, int value_i, T info);
	bool _find(TreeNode* node, int target);
	TreeNode* _get(TreeNode* node, int target);

	enum Direction {
		_Go_Left = 1,
		_Go_Right= 2,
		_None    =-1
	};
	Direction MovePointer(TreeNode* node, int item_i);

public:
	TreeNode* getRoot() { return this->_Root; }
	BinaryTree<T>()
		: _Root(null), _Size(0) { }

	bool find(int target);
	TreeNode* get(int target);
	void insert(int code, int value_i, T value);

	int size() const;
	int maxDepth();
	T minValue(TreeNode* node);
	void listTree();
	void listTree(TreeNode* node, int indet);
	void listTree(int indet);

	int _print_t(TreeNode *tree, int is_left, int offset, int depth, char s[20][255]);
};

template <class T>
class Linked_List
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

	Linked_List<T>();
	~Linked_List<T>();
};

/* Graph */ /* Graph */ /* Graph */ /* Graph */ /* Graph */ /* Graph */

template <class T>
class Edge {
	T _edgeInfo;
	double _Weight;

	Linked_List< Edge* > _connections;

public:
	Edge(T _edgeInfo, double _Weight)
		: _edgeInfo(_edgeInfo), _Weight(_Weight) { }

	void addConnection(Edge* edge) { _connections.push_back(edge); }
	T getInfo() { return _edgeInfo; }
	Linked_List< Edge* > getConnectionList() { return _connections; }
	double getWeight() const { return _Weight; }
};

template <class T>
class Graph {
	Linked_List< Edge < T >* > graph;

	int p_Size;
public:
	explicit Graph()
		: p_Size{ 0 }
	{ }

	int Size() const { return p_Size; }
	void addEdge(T info, double i);
	void setConnections(int EdgeIndex, int connect_To);
	void listGraph();

	void shortestPath(T start, T end);
};

template <class T>
void Graph<T>::addEdge(T info, double i) {
	graph.push_back(new Edge<T>(info,i));
}

template <class T>
void Graph<T>::setConnections(int EdgeIndex, int connect_To) {
	graph.operator[](EdgeIndex)->addConnection(graph.operator[](connect_To));
}

template <class T>
void Graph<T>::listGraph() {
	for (size_t i = 0; i < graph.size(); i++) {
		std::cout << std::to_string(graph.operator[](i)->getInfo()) + "|";
		for (size_t z = 0; z < graph.operator[](i)->getConnectionList().size(); z++) {
			std::cout << "--|"+std::to_string(int(graph.operator[](i)->getConnectionList().operator[](z)->getWeight()))+
				"|-->("+std::to_string(graph.operator[](i)->getConnectionList().operator[](z)->getInfo())+")";
		}
		std::cout << "\n";
	}
}

template <class T>
void Graph<T>::shortestPath(T start, T end) {

}

/* Graph */ /* Graph */ /* Graph */ /* Graph */ /* Graph */ /* Graph */


template <class T>
bool BinaryTree<T>::find(int target) {
	if (_Root == null) return FALSE;
	if (_find(_Root, target)) { return TRUE; }
	return FALSE;
}

template <class T>
typename BinaryTree<T>::TreeNode* BinaryTree<T>::_get(TreeNode* node, int target) {
	if(node == null) return null;
	if(MovePointer(node, target) == Direction::_Go_Left) {
		if (node->_Item == target) return node;
		_get(node->_Left, target);
	}
	if(MovePointer(node, target) == Direction::_Go_Right) {
		if (node->_Item == target) return node;
		_get(node->_Right, target);
	}
}

template <class T>
typename BinaryTree<T>::TreeNode* BinaryTree<T>::get(int target) {
	return _get(_Root, target);
}

template <class T>
bool BinaryTree<T>::_find(TreeNode* node, int target)
{
	if(MovePointer(node, target) == Direction::_Go_Left) {
		if (node->_Left == null) return FALSE;
		if (node->_Item == target) return TRUE;
		_find(node->_Left, target);
	}
	if(MovePointer(node, target) == Direction::_Go_Right) {
		if (node->_Right == null) return FALSE;
		if (node->_Item == target) return TRUE;
		_find(node->_Right, target);
	}
	return false;
}

template <class T>
typename BinaryTree<T>::Direction BinaryTree<T>::MovePointer(TreeNode* node, int item_i)
{
	if (node == null) return Direction::_None;
	if (node->_Item < item_i) 
		return Direction::_Go_Right;
	return Direction::_Go_Left;
}

template <class T>
void BinaryTree<T>::insert(int code, int value_i, T info)
{
	if (_Root == null) { _Root = newNode(code, value_i, info); return; }
	if (!find(code)) { insert(_Root, code, value_i, info); }
}

template <class T>
void BinaryTree<T>::insert(TreeNode* node, int code, int value_i, T info) {
	if (MovePointer(node, value_i) == Direction::_Go_Left) {
		if(node->_Left == null){ node->_Left = newNode(code, value_i, info); }
		else insert(node->_Left, code, value_i, info);
	}
	else {
		if (node->_Right == null) { node->_Right = newNode(code, value_i, info); }
		else insert(node->_Right, code, value_i, info);
	}
}

template <class T>
int BinaryTree<T>::size() const {
	if (_Root == null) return 0;
	return _Size;
}


template <class T>
typename BinaryTree<T>::TreeNode* BinaryTree<T>::newNode(int _code_i,int value, T value_r) {
	TreeNode* ptr = new TreeNode;
	ptr->_Index = _code_i;
	ptr->_Item = value;
	ptr->_Info = value_r;
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
void BinaryTree<T>::listTree() {
	listTree(_Root);
}

template <class T>
void BinaryTree<T>::listTree(TreeNode* node, int indent)
{ }

template<class T>
int BinaryTree<T>::_print_t(TreeNode *tree, int is_left, int offset, int depth, char s[20][255])
{
	char b[20];
	int width = 5;

	if (tree == null) return 0;
	int a = tree->_Item;

	sprintf(b, "(%03d)", a);

	int left = _print_t(tree->_Left, 1, offset, depth + 1, s);
	int right = _print_t(tree->_Right, 0, offset + left + width, depth + 1, s);

#ifdef COMPACT
	for (int i = 0; i < width; i++)
		s[depth][offset + left + i] = b[i];

	if (depth && is_left) {

		for (int i = 0; i < width + right; i++)
			s[depth - 1][offset + left + width / 2 + i] = '-';

		s[depth - 1][offset + left + width / 2] = '.';

	}
	else if (depth && !is_left) {

		for (int i = 0; i < left + width; i++)
			s[depth - 1][offset - width / 2 + i] = '-';

		s[depth - 1][offset + left + width / 2] = '.';
	}
#else
	for (int i = 0; i < width; i++)
		s[2 * depth][offset + left + i] = b[i];

	if (depth && is_left) {

		for (int i = 0; i < width + right; i++)
			s[2 * depth - 1][offset + left + width / 2 + i] = '-';

		s[2 * depth - 1][offset + left + width / 2] = '+';
		s[2 * depth - 1][offset + left + width + right + width / 2] = '+';

	}
	else if (depth && !is_left) {

		for (int i = 0; i < left + width; i++)
			s[2 * depth - 1][offset - width / 2 + i] = '-';

		s[2 * depth - 1][offset + left + width / 2] = '+';
		s[2 * depth - 1][offset - width / 2 - 1] = '+';
	}
#endif

	return left + width + right;
}

template <class T>
void BinaryTree<T>::listTree(int indent)
{
	listTree(_Root, indent);
}


/* LINKED LIST */

template <class T>
void Linked_List<T>::push_back(T _value)
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
void Linked_List<T>::pop_Back()
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
T Linked_List<T>::operator[](int _Index)
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
inline void Linked_List<T>::addAt(unsigned _Index, T _data) {
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
inline void Linked_List<T>::removeAt(unsigned _Index)
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
void Linked_List<T>::Clear()
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
T Linked_List<T>::front()
{
	if (_Front_Ptr == nullptr) return NULL;
	return _Front_Ptr->_Item;
}

template <class T>
T Linked_List<T>::back()
{
	Node* _Ptr = _Front_Ptr;
	while (_Ptr != nullptr) {
		if (_Ptr->_Next == nullptr) break;
		_Ptr = _Ptr->_Next;
	}
	return _Ptr->_Item;
}

template <class T>
T Linked_List<T>::find(T _value)
{
	Node* _Ptr = _Front_Ptr;
	while (_Ptr->_Next != nullptr) {
		if(_Ptr == _value) return _Ptr;
		_Ptr = _Ptr->_Next;
	}
	return FALSE;
}

template <class T>
bool Linked_List<T>::contains(T _value)
{
	if (find(_value) != nullptr) return TRUE; 
	return FALSE;
}

template <class T>
void Linked_List<T>::display() const
{
	Node* _Ptr = _Front_Ptr;
	while (_Ptr->_Next != nullptr) {
		std::cout << _Ptr->_Item << std::endl;
		_Ptr = _Ptr->_Next;
	}
}

template <class T>
unsigned Linked_List<T>::isEmpty() const
{
	if (size() == 0) return TRUE;
	return FALSE;
}

template <class T>
int Linked_List<T>::size() const
{
	return _size;
}

template <class T>
long int Linked_List<T>::hashcode() const {
	long double i = 2352338.2492847;
	size_t r = sizeof i;
	return r;
}

template <class T>
Linked_List<T>::Linked_List<T>(): _Front_Ptr{nullptr},
                                   _size{0}
{
}

template <class T>
Linked_List<T>::~Linked_List<T>()
{
}
#endif //LINKED_LIST_H


