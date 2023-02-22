#include <iostream>
#include <string>

using namespace std;

// Student class declaration
class student
{
public:
	// Constructor for student class
	student(const string& name, const string& ssn) : studName(name), studSSN(ssn)
	{}

	// Member function declaration that displays students name and SSN
	virtual void identify() const
	{
		cout << "student " << studName << "  Social Security Number " << studSSN << endl;
	}

protected:
	// Private data type declarations for student name and student SSN
	string studName;
	string studSSN;
};

// Student Athlete class declaration
class studentAthlete : public student
{
public:
	// Constructor for studentAthlete
	studentAthlete(const string& name, const string& ssn, const string& spt) : student(name, ssn), sport(spt)
	{}

	// Member function that displays students name, SSN, and sport
	void identify() const
	{
		cout << "student " << studName << "  Social Security Number " << studSSN << "  Sport " << sport << endl;
	}

private:
	// Private data sport declaration
	string sport;
};