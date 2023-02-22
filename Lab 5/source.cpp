// Kevin Morales
// Chapter #4
// CIS 2542 NET03
// March 21, 2021

#include <iostream>
#include "bag2.h"

using namespace std;
using namespace main_savitch_4;

int main() 
{
	bag b(4); // initial capacity to 4

	b.test(); // testing test function to show used spots in array and capacity

	for (int i = 0; i < 10; i++)
	{
		b.insert(i * 2 + 1);
		b.test();
	}

	return 0;
}
