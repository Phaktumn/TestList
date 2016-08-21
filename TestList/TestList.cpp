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
	Simple_Array_<Simple*> ll = Simple_Array_<Simple*>();
	BinaryTree<int*> bt = BinaryTree<int*>();

	srand(time(NULL));

	for (int i = 0; i < 100; i++) {
		bt.insert(i, new int(rand() % 1000));
	}

	bt.listTree();

	system("pause");

    return 0;
}


