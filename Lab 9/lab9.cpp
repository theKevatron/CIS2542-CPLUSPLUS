#include <iostream>
#include "student.h"

int main()
{
    // Kevin Morales - 5/8/22 - CIS 2542 - Lab #9

    // Student and student athlete declarations using constructors
    student ja("John Anderson", "345 - 12 - 3547");
    student bw("Bill Williams", "286 - 72 - 6194");
    studentAthlete bj("Bob Johnson", "294 - 87 - 6295", "football");
    studentAthlete dr("Dick Robinson", "669 - 28 - 9296", "baseball");

    // List of student pointers
    student* stud[] = { &ja, &bw, &bj, &dr };

    // For loop that calls the identify() function for the student pointers list 4 times
    for (int i = 0; i <= 3; i++) 
    {
        stud[i]->identify();
    }

    /*
    Output:

    student John Anderson  Social Security Number 345 - 12 - 3547
    student Bill Williams  Social Security Number 286 - 72 - 6194
    student Bob Johnson  Social Security Number 294 - 87 - 6295  Sport football
    student Dick Robinson  Social Security Number 669 - 28 - 9296  Sport baseball

    F:\SCHOOL-Spring 2022\CIS-2542(C++)\Lab #9\Lab 9 - KM\Debug\Lab 9 - KM.exe (process 11848) exited with code 0.
    To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
    Press any key to close this window . . .

    */
}