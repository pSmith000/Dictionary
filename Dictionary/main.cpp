#include <iostream>
#include "Dictionary.h"

void main()
{
	Dictionary<const char*, int> test = Dictionary<const char*, int>();
	Dictionary<const char*, int> test2 = Dictionary<const char*, int>();

	test.addItem("yes", 1);
	test.addItem("house", 20);
	test.addItem("dog", 30);
	int x = test["house"];

	
	test2 = test;
	test2.remove("house");
	int y = test2["house"];
	test.clear();
	//test2.tryGetValue(50, x);

	if (test2.containsValue(1))
		std::cout << "It's here " << y;

}