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
	Linked_List<int> ll = Linked_List<int>();
	BinaryTree<std::string> bt = BinaryTree<std::string>();
	Graph<int> graph = Graph<int>();

	srand(time(nullptr));

	//for (size_t i = 0; i < 15; i++) {
	//	ll.push_back(rand() % 100);
	//}

	//Linked_List<int>::printList(ll);

	for (int i = 0; i < 9; i++) {
		graph.addVertex(i);
	}

	//0-1-2
	//|X|X|
	//3-4-5
	//|X|X|
	//6-7-8
	//Size x = 3
	//Size y = 3

	std::cout << "GRAFO" << std::endl;
	graph.addConnections(0, 1, rand() % 100);
	graph.addConnections(0, 4, rand() % 100);
	graph.addConnections(0, 7, rand() % 100);
	graph.addConnections(0, 8, rand() % 100);
	graph.addConnections(1, 5, rand() % 100);
	graph.addConnections(1, 7, rand() % 100);
	graph.addConnections(1, 8, rand() % 100);
	graph.addConnections(1, 0, rand() % 100);
	graph.addConnections(2, 6, rand() % 100);
	graph.addConnections(3, 1, rand() % 100);
	graph.addConnections(3, 8, rand() % 100);
	graph.addConnections(3, 0, rand() % 100);
	graph.addConnections(3, 5, rand() % 100);
	graph.addConnections(4, 6, rand() % 100);
	graph.addConnections(4, 2, rand() % 100);
	graph.addConnections(4, 8, rand() % 100);
	graph.addConnections(5, 1, rand() % 100);
	graph.addConnections(5, 2, rand() % 100);
	graph.addConnections(5, 0, rand() % 100);
	graph.addConnections(5, 4, rand() % 100);
	graph.addConnections(6, 1, rand() % 100);
	graph.addConnections(7, 3, rand() % 100);
	graph.addConnections(7, 1, rand() % 100);
	graph.addConnections(7, 0, rand() % 100);
	graph.addConnections(7, 8, rand() % 100);
	graph.addConnections(7, 4, rand() % 100);
	graph.addConnections(8, 7, rand() % 100);
	graph.addConnections(8, 2, rand() % 100);
	graph.addConnections(8, 5, rand() % 100);
	graph.addConnections(8, 1, rand() % 100);
	graph.addConnections(8, 4, rand() % 100);
	graph.addConnections(8, 3, rand() % 100);

	//graph.addConnections(0, 1, 1);
	//graph.addConnections(0, 4, 1.25);
	//graph.addConnections(0, 3, 1);

	//graph.addConnections(1, 0, 1);
	//graph.addConnections(1, 2, 1);
	//graph.addConnections(1, 3, 1.25);
	//graph.addConnections(1, 4, 1);
	//graph.addConnections(1, 5, 1.25);

	//graph.addConnections(2, 1, 1);
	//graph.addConnections(2, 4, 1.25);
	//graph.addConnections(2, 5, 1);

	//graph.addConnections(3, 0, 1);
	//graph.addConnections(3, 1, 1.25);
	//graph.addConnections(3, 4, 1);
	//graph.addConnections(3, 6, 1);
	//graph.addConnections(3, 7, 1.25);

	//graph.addConnections(4, 0, 1.25);
	//graph.addConnections(4, 1, 1);
	//graph.addConnections(4, 2, 1.25);
	//graph.addConnections(4, 3, 1);
	//graph.addConnections(4, 5, 1);
	//graph.addConnections(4, 6, 1.25);
	//graph.addConnections(4, 7, 1);
	//graph.addConnections(4, 8, 1.25);

	//graph.addConnections(5, 1, 1.25);
	//graph.addConnections(5, 2, 1);
	//graph.addConnections(5, 4, 1);
	//graph.addConnections(5, 7, 1.25);
	//graph.addConnections(5, 8, 1);

	//graph.addConnections(6, 3, 1);
	//graph.addConnections(6, 4, 1.25);
	//graph.addConnections(6, 7, 1);

	//graph.addConnections(7, 3, 1.25);
	//graph.addConnections(7, 4, 1);
	//graph.addConnections(7, 5, 1.25);
	//graph.addConnections(7, 6, 1);
	//graph.addConnections(7, 8, 1);

	//graph.addConnections(8, 4, 1.25);
	//graph.addConnections(8, 5, 1);
	//graph.addConnections(8, 7, 1);

	graph.listGraph();
	std::cout << "\n";
	graph.printAllPaths(0, 8);


	//std::cout << "ARVORE" << std::endl;
	//for (int i = 0; i < 10; i++) {
	//	bt.insert(i, rand() % 1000, std::to_string(i * 2));
	//}

	//const int r = 20;
	//char s[r][255];
	//for (int i = 0; i < r; i++) {
	//	sprintf(s[i], "%80s", " ");
	//}

	//bt._print_t(bt.getRoot() , 0, 0, 0, s);
	//
	//for (int i = 0; i < r; i++) {
	//	printf("%s\n", s[i]);
	//}

	system("pause");

    return 0;
}


