#pragma once
#include <string>

using namespace std;

class clock
{
public:
	// Constructor to provide values when no values are declared on declaration of a member of class "clock"
	clock(int = 0, int = 0);

	// Function prototypes
	void setHour(int);
	void setMinute(int);

	// Inline functions
	int getHour() const { return hour; }
	int getMinute() const { return minute; }

	void printStandard() const;

	// Function prototype to add time to clock by minutes entered
	void addTime(int);

private:
	int hour;
	int minute;
};

// Function to add time to clock by m minutes
void clock::addTime(int m)
{
	minute += m;

	// Check for extra hours
	int xHours = minute / 60;

	// Put remainder into minutes
	minute = minute % 60;

	// Put xHours into hours variable
	hour += xHours;

	// Check for over 24 hours
	hour = hour % 24;
};

// Constructor to set spcified values when declaring new object of class "clock"
clock::clock(int h, int m)
{
	setHour(h);
	setMinute(m);
};

void clock::printStandard() const
{
	if (hour > 12)
		cout << (hour - 12);
	else if (hour == 0)
		cout << "12";
	else
		cout << hour;

	cout << ":";

	if (minute < 10)
		cout << "0";

	cout << minute;

	// Check for AM/PM
	if (hour >= 12)
		cout << "PM";
	else
		cout << "AM";
};

// Class implementation
void clock::setHour(int h)
{
	// Check if h is valid
	if (h < 0 || h > 24)
		throw invalid_argument("Hour is invalid");
	else
		hour = h;
};

void clock::setMinute(int m)
{
	// Check if m is valid
	if (m < 0 || m > 59)
		throw invalid_argument("Minute is invalid");
	else
		minute = m;
};