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

	for (size_t i = 0; i < 15; i++) {
		ll.push_back(rand() % 100);
	}

	Linked_List<int>::printList(ll);

	//for (int i = 0; i < 10; i++) {
	//	graph.addEdge(i, rand() % 100);
	//}

	//std::cout << "GRAFO" << std::endl;
	//graph.setConnections(0, 4);

	//graph.setConnections(1, 0);
	//graph.setConnections(1, 2);

	//graph.setConnections(2, 3);
	//graph.setConnections(2, 7);
	//graph.setConnections(2, 9);

	//graph.setConnections(3, 2);
	//graph.setConnections(3, 4);
	//graph.setConnections(3, 8);

	//graph.setConnections(4, 1);

	//graph.setConnections(5, 1);
	//graph.setConnections(5, 3);

	//graph.setConnections(6, 2);
	//graph.setConnections(6, 8);
	//graph.setConnections(6, 1);

	//graph.setConnections(7, 3);
	//graph.setConnections(7, 1);
	//graph.setConnections(7, 2);
	//graph.setConnections(7, 9);

	//graph.setConnections(8, 2);
	//graph.setConnections(8, 6);
	//graph.setConnections(8, 1);
	//graph.setConnections(8, 0);

	//graph.setConnections(9, 5);
	//graph.setConnections(9, 2);
	//graph.setConnections(9, 8);
	//graph.setConnections(9, 7);

	//graph.listGraph();
	//std::cout << "\n";
	//graph.printAllPaths(0, 5);

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


