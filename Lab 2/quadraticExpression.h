#pragma once
// Lab #2 - CIS 2542 NET03
// Kevin Morales

using namespace std;

// Declaration of class
class quadraticExpression
{
public:
	// Constructor to provide values when no values are set on declaration of a member of class "quadraticExpression"
	quadraticExpression(double = 0, double = 0, double = 0);

	// Member function prototype to change coeffient values
	void changeCoeffients(double, double, double);

	// Member function prototypes to set values of a, b, and c
	void setA(double);
	void setB(double);
	void setC(double);

	// Constant inline function to get/return values of either a, b, and c
	double getACoeeficient() const { return a; }
	double getBCoeeficient() const { return b; }
	double getCCoeeficient() const { return c; }

	// Constant member funtion prototype to get/return all coeffiecient values (a, b, and c)
	void printCoefficients() const;

	// Constant function protoype to evaluate quadratic expression at a particular value
	double evaluate (double) const;

	// Constant function prototype to get number of roots
	int getNumberOfRoots() const;

	// Constant function prototype to return first root
	void getFirstRoot() const;

	// Constant function prototype to return second root
	void getSecondRoot() const;

	// Enumerated list of number of roots
	enum
	{
		NO_ROOTS = 0,
		ONE_ROOT = 1,
		TWO_ROOTS = 2,
		INFINITE_ROOTS = 3
	};
private:
	// Private data variables a, b, and c declared
	double a;
	double b;
	double c;
};

// Constant function to return second root
void quadraticExpression::getSecondRoot() const
{
	double root2;
	if (a != 0 && ((b * b) > (4 * a * c)))
	{
		root2 = (((-b) + sqrt((b * b) - (4 * a * c))) / (2 * a));
		cout << root2;
	}
	else
		cout << "domain_error";
};

// Constant function to return first root
void quadraticExpression::getFirstRoot() const
{
	double root1;
	if (a == 0 && b == 0 && c == 0)
		cout << "0";
	else if (a == 0 && b != 0)
	{
		root1 = -c / b;
		cout << root1;
	}
	else if (a != 0 && ((b * b) == (4 * a * c)))
	{
		root1 = -b / (2 * a);
		cout << root1;
	}
	else if (a != 0 && ((b * b) > (4 * a * c)))
		root1 = (((-b) - sqrt((b * b) - (4 * a * c))) / (2 * a));
	else
		cout << "domain_error";
};

// Constant function to get number of roots
int quadraticExpression::getNumberOfRoots() const
{
	if (a == 0 && b == 0 && c == 0)
		return INFINITE_ROOTS;
	else if (a == 0 && b == 0 && c != 0)
		return NO_ROOTS;
	else if (a == 0 && b != 0)
		return ONE_ROOT;
	else if (a != 0 && ((b*b) < (4*a*c)))
		return NO_ROOTS;
	else if (a != 0 && ((b * b) == (4 * a * c)))
		return ONE_ROOT;
	else if (a != 0 && ((b * b) > (4 * a * c)))
		return TWO_ROOTS;
};

// Constant function to evaluate quadratic expression at a particular value
double quadraticExpression::evaluate(double x) const
{
	double value = ((a * x) * (a * x)) + (b * x) + c;
	cout << value << endl;
};

// Member function to change coeffient values using set functions
void quadraticExpression::changeCoeffients(double d, double e, double f)
{
	setA(a);
	setB(b);
	setC(c);
};

// Constant member function to get/return all coeffiecient values (a, b, and c)
void quadraticExpression::printCoefficients() const
{
	cout << "Printing coefficient values: " << endl;
	cout << "a: " << a << " b: " << b << " c: " << c << endl;
};

// Constructor to create a member with specified values on declaration
quadraticExpression::quadraticExpression(double d, double e, double f)
{
	setA(a);
	setB(b);
	setC(c);
};

// Member function to set value of a
void quadraticExpression::setA(double d)
{
	a = d;
};
// Member function to set value of b
void quadraticExpression::setB(double e)
{
	b = e;
};
// Member function to set value of c
void quadraticExpression::setC(double f)
{
	c = f;
};