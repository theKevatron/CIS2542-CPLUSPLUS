// Lab #1 - CIS 2542 NET03
// Kevin Morales

#include <iostream>
#include <string>
#include <iomanip>
#include <string.h>

using namespace std;

// Structure definition: name, age, and number
struct player
{
	string name;
	int points;
	int number;
};

// Declare indentifiers
void loadPlayers(player team[]);
void  displayTable(player team[]);

// Function prototype
int main()
{

	// Create array to store player information (name, age, and number)
	player team[3];

	// Call function to get player info
	loadPlayers(team);

	// Call function to display player info and highest scoring player name and number
	displayTable(team);

	// End of program
	return 0;
}

// Function to get player info from console/ gather and store user input in "player" array
void loadPlayers(player team[])
{
	// Ask for user input to fill player information and store in array
	for (int i = 0; i < 3; i++)
	{
		cout << "Enter the name of player " << (i + 1) << "(then press enter): ";
		cin >> team[i].name;
		cout << endl;
		cout << "Enter the points scored by player " << (i + 1) << " (then press enter): ";
		cin >> team[i].points;
		cout << endl;
		// Input invalidation to not accept score numbers under 0
		if (team[i].points < 0)
		{
			cout << "Error: Cannot accept negative values." << endl;
			cout << "Please enter a value greater than or equal to 0: ";
			cin >> team[i].points;
			cout << endl;
		}
		cout << "Enter the number of player " << (i + 1) << " (then press enter): ";
		cin >> team[i].number;
		cout << endl;
		// Input invalidation to not accept player numbers under 0
		if (team[i].number < 0)
		{
			cout << "Error: Cannot accept negative values." << endl;
			cout << "Please enter a value greater than or equal to 0: ";
			cin >> team[i].number;
			cout << endl;
		}
	}

}

// Function to display array of player information/table information
void  displayTable(player team[])
{
	cout << "------------------------------------------------" << endl;
	cout << "Player name:    " << "Points scored:    " << "Player number:    " << endl;
	cout << "------------------------------------------------" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << endl;
		cout << right << setw(12) << team[i].name;
		cout << right << setw(18) << team[i].points;
		cout << right << setw(18) << team[i].number << endl;
	}

	// Caulculate and display total team points
	cout << endl;
	int teamPoints;
	teamPoints = team[0].points + team[1].points + team[2].points;
	cout << "--------------------------------" << endl;
	cout << "Total points scored by team:  " << teamPoints << endl;
	cout << "--------------------------------" << endl;
	cout << endl;

	// For loop to find highest scoring player
	int highestScore = team[0].points;
	int indexHighestScore = 0;
	for (int i = 0; i < 3; i++)
	{
		// If statement which calculates highest score
		if (team[i].points > highestScore)
		{
			highestScore = team[i].points;
			indexHighestScore = i;
		}

	}
	// Display highest scoreing player name and number
	cout << "----------------------------" << endl;
	cout << "MVP(highest scoring player): " << endl;
	cout << "----------------------------" << endl;
	cout << "Name:                   " << team[indexHighestScore].name << endl;
	cout << "Number:                   " << team[indexHighestScore].number << endl;
	cout << "----------------------------" << endl;
	cout << endl;
}


// Console:
/*
Enter the name of player 1(then press enter): John

Enter the points scored by player 1 (then press enter): -1

Error: Cannot accept negative values.
Please enter a value greater than or equal to 0: 31

Enter the number of player 1 (then press enter): 12

Enter the name of player 2(then press enter): Jack

Enter the points scored by player 2 (then press enter): 26

Enter the number of player 2 (then press enter): 32

Enter the name of player 3(then press enter): Kyle

Enter the points scored by player 3 (then press enter): 16

Enter the number of player 3 (then press enter): 51

------------------------------------------------
Player name:    Points scored:    Player number:
------------------------------------------------

		John                31                12

		Jack                26                32

		Kyle                16                51

--------------------------------
Total points scored by team:  73
--------------------------------

----------------------------
MVP(highest scoring player):
----------------------------
Name:                   John
Number:                   12
----------------------------


F:\SCHOOL-Spring 2022\CIS-2542(C++)\Lab #1\Lab 1 - Kevin Morales\Debug\Lab 1 - Kevin Morales.exe (process 548) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

*/