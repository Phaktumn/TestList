#define LINKED_LIST_H
#include <string>
#include <iomanip>
#include <list>
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

template <class T> class BinaryTree;
template <class T> class Linked_List;
template <class T> class Vertex;
template <class T> class Graph;

template <class T> struct TreeNode { int _Index; int _Item; T _Info; TreeNode<T>* _Right; TreeNode<T>* _Left; };
template <class T> struct Node { T _Item; Node<T>* _Next; };
template <class T> struct DNode { T _Item; DNode<T>* next_node; DNode<T>* previous_node; };
template <class T> struct Edge { Vertex<T>* _connection; double Weight; explicit Edge(double w_x, Vertex<T>* con) : _connection(con), Weight(w_x) {} };

template <class T>
class BinaryTree {

	TreeNode<T>* _Root;
	int _Size;
	TreeNode<T>* newNode(int _code_i, int value_r, T info);
	int maxDepth(TreeNode<T>* node);
	void insert(TreeNode<T>* node, int code, int value_i, T info);
	bool _find(TreeNode<T>* node, int target);
	TreeNode<T>* _get(TreeNode<T>* node, int target);

	enum Direction {
		_Go_Left = 1,
		_Go_Right= 2,
		_None    =-1
	};
	Direction MovePointer(TreeNode<T>* node, int item_i);

public:
	TreeNode<T>* getRoot() { return this->_Root; }
	BinaryTree<T>() : _Root(null), _Size(0) { }

	bool find(int target);
	TreeNode<T>* get(int target);
	void insert(int code, int value_i, T value);

	int size() const;
	int maxDepth();
	//T minValue(TreeNode<T>* node);
	void listTree();
	void listTree(TreeNode<T>* node, int indet);
	void listTree(int indet);

	int _print_t(TreeNode<T> *tree, int is_left, int offset, int depth, char s[20][255]);
};

template <class T>
class Linked_List
{
	Node<T>* _Front_Ptr;
	int _size;

public:
	void push_back(T _value);
	void pop_Back();
	T operator [](int _Index);
	Node<T> operator ()(int _Index);
	void addAt(unsigned int _Index, T _data);
	void removeAt(unsigned int _Index);
	T front();
	T back();
	T find(T _value);
	void Clear();
	bool contains(T _value);
	void display() const;
	unsigned int isEmpty() const;
	int size() const;

	long int hashcode() const;

	static void printList(Linked_List<T>& list);

	Linked_List<T>();
	~Linked_List<T>();
};

/* Graph */ /* Graph */ /* Graph */ /* Graph */ /* Graph */ /* Graph */

template <class T>
class Vertex {
	T _edgeInfo;

	int _visited;

	Linked_List< Edge < T >* > _connections;

public:
	explicit Vertex(T _edgeInfo)
		: _edgeInfo(_edgeInfo), _visited(0) { }

	void addConnection(Edge < T > * edge) { _connections.push_back(edge); }
	T getInfo(){
		if(_edgeInfo != NULL) return _edgeInfo;
		else return NULL;
	}
	Linked_List< Edge < T > * > getConnectionList() { return _connections; }

	void setVisited() { _visited = 1; }
	int isVisited() const { return _visited; }
	void resetState() { _visited = 0; }
};

template <class T>
class Graph {
	Linked_List< Vertex < T >* > graph;

	int p_Size;

	int counter = 0;
	int shotW = INT16_MAX;

public:
	explicit Graph()
		: p_Size{ 0 }
	{ }

	Linked_List< Vertex < T >* > getList() { return graph; }
	int Size() const { return p_Size; }
	void addVertex(T info);
	void addConnections(int EdgeIndex, int connect_To, double weight);
	void listGraph();

	bool hasPath(T start, T end);
	void printAllPaths(T start, T end);
	void allPaths(T u, T d, int path[], int &path_index);
	void shortestPath(T start, T end, int weigths[], int allW[], int path[], int &path_i, Linked_List<int>* sh, int shortAll);

	void clear();

	void resetEdges();
};


template <class T>
void Graph<T>::addVertex(T info) {
	graph.push_back(new Vertex<T>(info));
	p_Size++;
}

template <class T>
void Graph<T>::addConnections(int EdgeIndex, int connect_To, double weight) {
	graph.operator[](EdgeIndex)->addConnection(new Edge<T>(weight, graph.operator[](connect_To)));
}

template <class T>
void Graph<T>::listGraph() {
	for (size_t i = 0; i < graph.size(); i++) {
		std::cout << std::to_string(graph.operator[](i)->getInfo()) + "|";
		for (size_t z = 0; z < graph.operator[](i)->getConnectionList().size(); z++) {
			std::cout << "--|"+ std::to_string(graph.operator[](i)->getConnectionList().operator[](z)->Weight)+
				"|-->("+ std::to_string(graph.operator[](i)->getConnectionList().operator[](z)->_connection->getInfo())+")";
		}
		std::cout << "\n";
	}
}

template <class T>
bool Graph<T>::hasPath(T start, T end)
{
	return false;
}

template <class T>
void Graph<T>::printAllPaths(T start, T end) {

	// Create an array to store paths
	int *path = new int[p_Size];
	int path_index = 0; // Initialize path[] as empty

	int weigts_i[9];
	for (size_t i = 0; i < 9; i++) {
		weigts_i[i] = 0;
	}

	int lessW = INT16_MAX;
	int allW[1000];
	for (size_t i = 0; i < 1000; i++) {
		allW[i] = -1;
	}

	Linked_List<int>* shortest = new Linked_List<int>();

 	//allPaths(start, end, path, path_index);
	shortestPath(start, end, weigts_i, allW, path, path_index, shortest, 1000);
	for (size_t i = 0; i < counter; i++) {
		if(allW[i] <= lessW) {
			lessW = allW[i];
		}
	}
	std::cout << "\nSHORTEST PATH: " << std::endl;
	for (auto x = 0; x < shortest->size(); x++) {
			std::cout  <<  "(" << std::to_string(shortest->operator[](x)) << ")->";
	}
	std::cout << " |Weight: " << std::to_string(lessW);

	resetEdges();
}

template <class T>
void Graph<T>::allPaths(T u, T d, int path[], int& path_index)
{
	// Mark the current node and store it in path[]
	graph.operator[](u)->setVisited();
	path[path_index] = u;
	path_index++;

	// If current vertex is same as destination, then print
	// current path[]
	if (u == d) {
		for (int i = 0; i<path_index; i++) std::cout << path[i] << " ";
		std::cout << "end" << std::endl;
	}

	else // If current vertex is not destination  
	{
		// Recur for all the vertices adjacent to current vertex
		for (int i = 0; i != graph.operator[](u)->getConnectionList().size(); ++i) {
			Linked_List< Edge < T >* > aux = graph.operator[](u)->getConnectionList();
			if (!aux.operator[](i)->_connection->isVisited()) {
				allPaths(int(aux.operator[](i)->_connection->getInfo()), d, path, path_index);
			}
		}
	}

	// Remove current vertex from path[] and mark it as unvisited
	path_index--;
	graph.operator[](u)->resetState();
}

template <class T>
void Graph<T>::shortestPath(T start, T end, int weigths[], int allW[], int path[], int& path_i, Linked_List<int>* sh, int shortAll)
{
	graph.operator[](start)->setVisited();
	path[path_i] = start;
	path_i++;

	if(start == end) {
		int totalW = 0;
		for (size_t i = 0; i < path_i; i++) {
			totalW += weigths[i];
		}
	
		if (totalW < shotW) {
			shotW = totalW;
			sh->Clear();
			for (size_t x = 0; x < path_i; x++) {
				sh->push_back(path[x]);
			}
		}
		
		allW[counter++] = totalW;
		for (int i = 0; i<path_i; i++) {
			std::cout << "(" + std::to_string(path[i]) + ")|";
		}
		std::cout << " W " << std::to_string(totalW) << std::endl;
	}
	else {
		for (size_t i = 0; i < graph.operator[](start)->getConnectionList().size(); ++i) {
			Linked_List< Edge < T >* > aux = graph.operator[](start)->getConnectionList();
			if(!aux.operator[](i)->_connection->isVisited()) {
				weigths[path_i] = int(aux.operator[](i)->Weight);
				Vertex<T>* auxCon = aux.operator[](i)->_connection;
				int info = 0;
				if(auxCon!=null) info = int(auxCon->getInfo());
				shortestPath(info, end, weigths, allW, path, path_i, sh, shortAll);
			}
		}
	}
	path_i--;
	graph.operator[](start)->resetState();
}

template <class T>
void Graph<T>::resetEdges() {
	for (size_t i = 0; i < p_Size; i++) { graph.operator[](i)->resetState(); }
}

/* Graph */ /* Graph */ /* Graph */ /* Graph */ /* Graph */ /* Graph */


template <class T>
bool BinaryTree<T>::find(int target) {
	if (_Root == null) return FALSE;
	if (_find(_Root, target)) { return TRUE; }
	return FALSE;
}

template <class T>
TreeNode<T>* BinaryTree<T>::get(int target)
{
	return _get(_Root, target);
}


template <class T>
bool BinaryTree<T>::_find(TreeNode<T>* node, int target)
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
TreeNode<T>* BinaryTree<T>::_get(TreeNode<T>* node, int target)
{
	if (node == null) return null;
	if (MovePointer(node, target) == Direction::_Go_Left) {
		if (node->_Item == target) return node;
		_get(node->_Left, target);
	}
	if (MovePointer(node, target) == Direction::_Go_Right) {
		if (node->_Item == target) return node;
		_get(node->_Right, target);
	}
	return nullptr;
}

template <class T>
typename BinaryTree<T>::Direction BinaryTree<T>::MovePointer(TreeNode<T>* node, int item_i)
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
void BinaryTree<T>::insert(TreeNode<T>* node, int code, int value_i, T info) {
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
TreeNode<T>* BinaryTree<T>::newNode(int _code_i, int value_r, T info) {
	TreeNode<T>* ptr = new TreeNode<T>;
	ptr->_Index = _code_i;
	ptr->_Item = info;
	ptr->_Info = value_r;
	ptr->_Left = null;
	ptr->_Right = null;
	_Size++;
	return ptr;
}

template <class T>
int BinaryTree<T>::maxDepth(TreeNode<T>* node)
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
void BinaryTree<T>::listTree(TreeNode<T>* node, int indent)
{ }

template<class T>
int BinaryTree<T>::_print_t(TreeNode<T> *tree, int is_left, int offset, int depth, char s[20][255])
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
		_Front_Ptr = (Node<T>*)(malloc(sizeof(Node<T>)));
		_Front_Ptr->_Item = _value;
		_Front_Ptr->_Next = nullptr;
		_size++;
	}
	else {
		Node<T>* _Prev_Ptr = _Front_Ptr;
		Node<T>* _Ptr = _Front_Ptr;

		while (_Ptr != nullptr) {
			_Prev_Ptr = _Ptr;
			_Ptr = _Ptr->_Next;
		}

		_Ptr = static_cast<Node<T>*>(malloc(sizeof(Node<T>)));
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
	Node<T>* _Ptr = _Front_Ptr;
	Node<T>* _Prev_Ptr;
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
T Linked_List<T>::operator[](int _Index) {
	int _curr_Index = 0;
	Node<T>* _Ptr = _Front_Ptr;
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
Node<T> Linked_List<T>::operator()(int _Index) {
	int _curr_Index = 0;
	Node<T>* _Ptr = _Front_Ptr;
	if (_Ptr != nullptr) {
		while (_curr_Index < _Index) {
			_Ptr = _Ptr->_Next;
			if (_Ptr == nullptr) return 0;
			_curr_Index++;
		}
		return _Ptr;
	}
	return 0;
}

template <class T>
inline void Linked_List<T>::addAt(unsigned _Index, T _data) {
	int _curr_Index = 1;
	Node<T>* _Ptr = _Front_Ptr;
	Node<T>* _last_Ptr = nullptr;
	Node<T>* _New_Data_;
	if (_Index == 1) {
		_last_Ptr = _Ptr;
		_New_Data_ = (Node<T>*)malloc(sizeof(Node<T>));
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
		_New_Data_ = (Node<T>*)malloc(sizeof(Node<T>));
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
	Node<T>* _Ptr = _Front_Ptr;
	//Remove The first Node<T>
	if (_Index == 1) {
		_Front_Ptr = _Ptr->_Next;
		free(_Ptr);
		_size--;
	}

	else {
		Node<T>* _last_Ptr = _Front_Ptr;
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
void Linked_List<T>::Clear() {
	Node<T>* _Ptr = _Front_Ptr;
	while (_Ptr!=null) {
		Node<T>* temp = _Ptr->_Next;
		free(_Ptr);
		_Ptr = temp;
		_size--;
	}
	_Front_Ptr = null;
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
	Node<T>* _Ptr = _Front_Ptr;
	while (_Ptr != nullptr) {
		if (_Ptr->_Next == nullptr) break;
		_Ptr = _Ptr->_Next;
	}
	return _Ptr->_Item;
}

template <class T>
T Linked_List<T>::find(T _value)
{
	Node<T>* _Ptr = _Front_Ptr;
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
	Node<T>* _Ptr = _Front_Ptr;
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
	size_t r = sizeof (long double);
	return r;
}

template <class T>
void Linked_List<T>::printList(Linked_List<T>& list) {
	std::cout << "ROOT";
	for (int i = 0; i < list.size(); i++) {
		if (i == 0) { std::cout << "->|"; }
		else {
			std::cout << "|";
		}
		std::cout << std::to_string(int(i)) + " |->(" + std::to_string(int(list[i])) + ")->";
 	}
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


