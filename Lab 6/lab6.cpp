// Kevin Morales
// Lab #6
// CIS 2542 NET03
// April 10, 2021

#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

// Template function declaration
template <typename T>
typename list <T>::iterator maxLoc(list<T>& aList)
{
	// Declaring max variable to keep track of highest value in list
	int max = -5;
	for (typename list <T>::iterator itr = aList.begin(); itr != aList.end(); itr++)
	{
		if (*itr > max)
		{
			max = *itr;
		}
	}
	// Calling function to find max value in list
	typename list <T>::iterator itrMax = find(aList.begin(), aList.end(), max);
	// Output largest value
	cout << "Largest Value: " << max << endl;
	// Return max value iterator
	return itrMax;
};

int main()
{
	// Integer array and list declaration
	int intArr[] = { 23, 49, -3, 29, 17, 200, 38, 93, 40 };
	int intSize = sizeof(intArr) / sizeof(int);
	list<int> intList(intArr, intArr + intSize);

	// Character array and list declaration
	char chrArr[] = "Hello World!";
	int chrSize = sizeof(chrArr);
	list<char> chrList(chrArr, chrArr + chrSize);

	// Repeatedly call maxLoc() function to find highest int value in list and delete that value
	cout << "Int List: " << endl;
	intList.erase(maxLoc(intList));
	cout << "Value deleted." << endl;
	intList.erase(maxLoc(intList));
	cout << "Value deleted." << endl;
	intList.erase(maxLoc(intList));
	cout << "Value deleted." << endl;
	intList.erase(maxLoc(intList));
	cout << "Value deleted." << endl;
	intList.erase(maxLoc(intList));
	cout << "Value deleted." << endl;
	intList.erase(maxLoc(intList));
	cout << "Value deleted." << endl;
	intList.erase(maxLoc(intList));
	cout << "Value deleted." << endl;
	intList.erase(maxLoc(intList));
	cout << "Value deleted." << endl;
	intList.erase(maxLoc(intList));
	cout << "Value deleted." << endl;

	// Repeatedly call maxLoc() function to find highest char value in list and delete that value
	cout << endl;
	cout << "Char List: " << endl;
	chrList.erase(maxLoc(chrList));
	cout << "Value deleted." << endl;
	chrList.erase(maxLoc(chrList));
	cout << "Value deleted." << endl;
	chrList.erase(maxLoc(chrList));
	cout << "Value deleted." << endl;
	chrList.erase(maxLoc(chrList));
	cout << "Value deleted." << endl;
	chrList.erase(maxLoc(chrList));
	cout << "Value deleted." << endl;
	chrList.erase(maxLoc(chrList));
	cout << "Value deleted." << endl;
	chrList.erase(maxLoc(chrList));
	cout << "Value deleted." << endl;
	chrList.erase(maxLoc(chrList));
	cout << "Value deleted." << endl;
	chrList.erase(maxLoc(chrList));
	cout << "Value deleted." << endl;
	chrList.erase(maxLoc(chrList));
	cout << "Value deleted." << endl;
	chrList.erase(maxLoc(chrList));
	cout << "Value deleted." << endl;
	chrList.erase(maxLoc(chrList));
	cout << "Value deleted." << endl;
	chrList.erase(maxLoc(chrList));
	cout << "Value deleted." << endl;

	return 0;
}

/*
Int List:
Largest Value: 200
Value deleted.
Largest Value: 93
Value deleted.
Largest Value: 49
Value deleted.
Largest Value: 40
Value deleted.
Largest Value: 38
Value deleted.
Largest Value: 29
Value deleted.
Largest Value: 23
Value deleted.
Largest Value: 17
Value deleted.
Largest Value: -3
Value deleted.

Char List:
Largest Value: 114
Value deleted.
Largest Value: 111
Value deleted.
Largest Value: 111
Value deleted.
Largest Value: 108
Value deleted.
Largest Value: 108
Value deleted.
Largest Value: 108
Value deleted.
Largest Value: 101
Value deleted.
Largest Value: 100
Value deleted.
Largest Value: 87
Value deleted.
Largest Value: 72
Value deleted.
Largest Value: 33
Value deleted.
Largest Value: 32
Value deleted.
Largest Value: 0
Value deleted.

F:\SCHOOL-Spring 2022\CIS-2542(C++)\Lab #6\Lab 6 - Kevin Morales\Debug\Lab 6 - Kevin Morales.exe (process 9380) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

*/
