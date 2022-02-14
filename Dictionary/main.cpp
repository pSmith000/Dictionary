#include <iostream>
#include "Dictionary.h"

void main()
{
	Dictionary<int, int> test = Dictionary<int, int>();
	Dictionary<int, int> test2 = Dictionary<int, int>();

	test.addItem(50, 1);
	test.addItem(20, 30);
	test.addItem(20, 1);
	test.addItem(20, 4);
	test.addItem(20, 6);
	int x = 10;
	test.remove(20, x);
	test.remove(20, x);

	
	test2 = test;
	test.clear();
	//test2.tryGetValue(50, x);

	if (test2.containsValue(1))
		std::cout << "It's here " << x;
}