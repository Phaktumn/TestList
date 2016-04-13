// TestList.cpp : Defines the entry point for the console application.\
// Open ReadMe.txt
//

#include "stdafx.h"

class Simple
{
public:
	explicit Simple(int m);
	int m;
};

Simple::Simple(int m)
{
	this->m = m;
}

void print(Simple_Array<int> test)
{
	for (size_t i = 0; i < test.size(); i++) {
		//Test for operator []
		std::cout << test[i] << "|";
	}
	std::cout << "\n";
}

void print(Simple_Array<Simple*> test)
{
	for (size_t i = 0; i < test.size(); i++) {
		//Test for operator []
		std::cout << test[i]->m << "|";
	}
	std::cout << "\n";
}

int main()
{
	std::cout << "Today`s Date: " << __DATE__ << std::endl;

	Simple_Array<int> test;
	Simple_Array<Simple*> simpleA;
	
	simpleA.push_back(new Simple(2));
	simpleA.push_back(new Simple(4));
	simpleA.push_back(new Simple(5));
	simpleA.push_back(new Simple(12));
	simpleA.push_back(new Simple(16));


	test.push_back(2);  //1
	test.push_back(5);  //2
	test.push_back(15); //3
	test.push_back(12); //4
	test.push_back(16); //5
	test.push_back(123);//6

	std::cout << "Object List Initial State" << std::endl;
	print(simpleA);

	std::cout << "Remove Node 2" << std::endl;
	simpleA.removeAt(2);
	print(simpleA);

	std::cout << "Add new Object at Position 1 " << std::endl;
	simpleA.addAt(1, new Simple(69));
	print(simpleA);

	std::cout << "INT List Initial State" << std::endl;
	print(test);

	std::cout << "pop last node" << std::endl;
	test.pop_Back();
	print(test);

	std::cout << "remove node number 3" << std::endl;
	test.removeAt(3);
	print(test);

	std::cout << "\n";
	std::cout << "Front of the List: " << test.front() << std::endl;
	std::cout << "Back of the list: " << test.back() << std::endl;

	system("pause");

    return 0;
}

