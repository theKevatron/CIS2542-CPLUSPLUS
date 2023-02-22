// Lab #2 - CIS 2542 NET03
// Kevin Morales

#include <iostream>
#include "quadraticExpression.h"

using namespace std;

void evaluateExpression(const quadraticExpression&);

int main()
{
	quadraticExpression q[6] = { quadraticExpression(2.1, 3, -7),
								 quadraticExpression(1.4, 3.9, +7),
								 quadraticExpression(-.75, 0, 0),
								 quadraticExpression(0, .3, -7),
								 quadraticExpression(0, 0, 4),
								 quadraticExpression() };


	for (int i = 0; i < 6; i++)
		evaluateExpression(q[i]);

	return EXIT_SUCCESS;
}

void evaluateExpression(const quadraticExpression& q)
{
	enum
	{
		NO_ROOTS = 0,
		ONE_ROOT = 1,
		TWO_ROOTS = 2,
		INFINITE_ROOTS = 3
	};

	int errorsHandled = 0;

	cout << "f(-5) = " << q.evaluate(-5) << endl;
	cout << "f(0)  = " << q.evaluate(0) << endl;
	cout << "f(5)  = " << q.evaluate(5) << endl;

	if (q.getNumberOfRoots() == INFINITE_ROOTS)
		cout << "The Expression has Infinite Roots" << endl;
	else if (q.getNumberOfRoots() == ONE_ROOT)
		cout << "The Expression has One Root at x = " << q.getFirstRoot() << endl;
	else if (q.getNumberOfRoots() == TWO_ROOTS)
	{
		cout << "The Expression has First Root at x  = " << q.getFirstRoot() << endl;
		cout << "The Expression has Second Root at x = " << q.getSecondRoot() << endl;
	}
	else
		cout << "The Expression has No Roots" << endl;

	try {
		q.getFirstRoot();
	}
	catch (domain_error e) {
		errorsHandled++;
	}

	try {
		q.getSecondRoot();
	}
	catch (domain_error e) {
		errorsHandled++;
	}

	cout << "Errors Handled: " << errorsHandled << endl;

	cout << endl;
	cout << endl;
}