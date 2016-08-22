#include "stdafx.h"
#include "StreamFile.h"
#include "AppLoop.h"
#include <string>

class Simple
{
public:
	explicit Simple(std::string m);
	std::string m;
};

Simple::Simple(std::string m)
{
	this->m = m;
}

int main()
{
	Linked_List<Simple*> ll = Linked_List<Simple*>();
	BinaryTree<std::string> bt = BinaryTree<std::string>();
	Graph<int> graph = Graph<int>();

	srand(time(nullptr));

	for (int i = 0; i < 5; i++) {
		graph.addEdge(i, rand() % 100);
	}

	std::cout << "GRAFO" << std::endl;
	graph.setConnections(2, 1);
	graph.setConnections(2, 3);
	graph.setConnections(2, 4);

	graph.setConnections(1, 4);

	graph.setConnections(3, 2);

	graph.listGraph();

	std::cout << "ARVORE" << std::endl;
	for (int i = 0; i < 10; i++) {
		bt.insert(i, rand() % 1000, std::to_string(i * 2));
	}

	const int r = 20;
	char s[r][255];
	for (int i = 0; i < r; i++) {
		sprintf(s[i], "%80s", " ");
	}

	bt._print_t(bt.getRoot() , 0, 0, 0, s);
	
	for (int i = 0; i < r; i++) {
		printf("%s\n", s[i]);
	}

	system("pause");

    return 0;
}


