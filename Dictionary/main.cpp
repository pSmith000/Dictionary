#include <iostream>
#include "Dictionary.h"

void main()
{
	//creat a new dictionary
	Dictionary<const char*, int> test = Dictionary<const char*, int>();

	test.clear();

	//Add items to Dictionary
	test.addItem("yes", 1);
	test.addItem("house", 20);
	test.addItem("dog", 30);
	test.remove("house", 40);

	//Test the constructor
	Dictionary<const char*, int> test2 = Dictionary<const char*, int>(test);

	//Sets a variable to be the data to see if the constructor worked
	int y = test2["house"];

	//If the constructor worked print 
	if (test2.containsValue(1))
		std::cout << "It's here " << y << std::endl;

	system("pause");

}