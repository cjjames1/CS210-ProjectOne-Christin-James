
/* *********************************************************************
							"Clock Project"
     A user-centered program displaying/updating 12 and 24-hour clocks 
						 Developer: Christin James
							  Date: 1/30/24 
   ********************************************************************* */

using namespace std;

#include <iostream>
#include <iomanip>
#include <string>
#include "Clock.h"



int main() {

	unsigned int h, m, s; // Variables to use in corresponding functions

	cout << "Enter hour (24-hr format): " << endl; //Prompting user to enter desired hours, minutes, and seconds
	cin >> h;
	cout << "Enter minutes: " << endl;
	cin >> m;
	cout << "Enter seconds: " << endl;
	cin >> s;

	unsigned int choice; // Variable to equate to returning variable from getMenuChoice() and use in switch statement

	do {
		printClock(h, m, s); // Displays 12 and 24-hour clocks using user input

		printMenu(); // Prints menu

		choice = getMenuChoice(); // Gets user's choice

		switch (choice) {
		case 1: // If user enters '1', add one hour
			addHour(h);
			break;

		case 2: // if user enters '2', add one minute
			addMinute(h, m);
			break;

		case 3: // if user enters '3', add one second
			addSecond(h, m, s);
			break;

		case 4: // if user enters '4', the program exits
			cout << "Exiting the program." << endl;
			break;

		default:
			cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
		}

	} while (choice != 4); // Used to loop to beginning if user enters choice 1-3.
	
return 0;
}
		


	