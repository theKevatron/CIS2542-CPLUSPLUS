// Lab #4 - CIS 2542 NET03
// Kevin Morales

#include <iostream>
#include <string>
#include "bag1.h"

using namespace std;
using namespace main_savitch_3;

// Function prototype
int main()
{
	bag b; // empty bag
	bag a;

	a.insert(4);
	a.insert(6);

	b.insert(5);
	b.insert(7);
	b.insert(23);

	for (int i = 0; i < 15; i++)
		b.insert(i * 2 + 1);

	b.test();

	cout << b.count(5) << endl;
	cout << b.count(8) << endl;
	cout << b.count(15) << endl;

	cout << b.erase_one(9) << endl;
	b.test();

	cout << b.erase(5) << endl;
	b.test();

	a = a + b;

	a.test();

	// End of program
	return 0;
}


// Console:
/*
{5,7,23,1,3,5,7,9,11,13,15,17,19,21,23,25,27,29,} used = 18
2
0
1
1
{5,7,23,1,3,5,7,29,11,13,15,17,19,21,23,25,27,} used = 17
2
{27,7,23,1,3,25,7,29,11,13,15,17,19,21,23,} used = 15
{4,6,27,7,23,1,3,25,7,29,11,13,15,17,19,21,23,} used = 17

F:\SCHOOL-Spring 2022\CIS-2542(C++)\Lab #4\Lab 4\Debug\Lab 4.exe (process 22808) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .
*/