// TestList.cpp : Defines the entry point for the console application.\
// Open ReadMe.txt
//
#include "stdafx.h"
#include "StreamFile.h"

IO file;

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
		cout << test[i] << "|";
		file.print_toFile("Int number: List Node: " + to_string(i), to_string(test[i]));
	}
	cout << "\n";
}

void print(Simple_Array<Simple*> test)
{
	for (size_t i = 0; i < test.size(); i++) {
		//Test for operator []
		cout << test[i]->m << "|";
		file.print_toFile("Simple Object: List Node: " + to_string(i), to_string(test[i]->m));
	}
	cout << "\n";
}

int main()
{
	cout << "Today`s Date: " << __DATE__ << endl;

	file = IO("teste.txt");
	file.openFile(_OF);
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

	file.print_toFile("INFORMATION: ", "Object List Initial State");
	print(simpleA);

	file.print_toFile("INFORMATION: ", "Remove Node 2");
	simpleA.removeAt(2);
	print(simpleA);

	file.print_toFile("INFORMATION: ", "Add new Object at Position 1 ");
	simpleA.addAt(1, new Simple(69));
	print(simpleA);


	file.print_toFile("INFORMATION: ", "INT List Initial State");
	print(test);

	test.addAt(1, 10);
	print(test);

	file.print_toFile("INFORMATION: ", "pop last node");
	test.pop_Back();
	print(test);

	file.print_toFile("INFORMATION: ", "remove node number 3");
	test.removeAt(3);
	print(test);

	cout << "\n";
	file.print_toFile("INFORMATION: ", "Front of the List: " + to_string(test.front()));
	file.print_toFile("INFORMATION: ", "Back of the list: " + to_string(test.back()));
	
	file.closeFile(_OF);

	system("pause");

    return 0;
}


