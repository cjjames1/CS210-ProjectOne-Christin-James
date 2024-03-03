// File containing function definitions

#include "Clock.h"
#include <string>
#include <iostream>
using namespace std;

int h; // Variables to use in functions below
int m;
int s;
string amPm;
int n;
char c;


void addHour(unsigned int& h) // Function to add one hour
{
	if (h >= 0 && h <= 23) { // Add one hour if hour (hh) is between 0 and 23
		h += 1; 
	}
	else if (h == 24) { // For 12-hour clock, set added hour to '01' (twoDigitString() applied) if time inputted is 24 
		h = 1;
	}
}

void addMinute(unsigned int& h, unsigned int& m) // Function to add one minute
{
	if (m == 59) { // Set added minute to '00' if minute is '59' and add 1 to hh
		m = 0;
		addHour(h);
	}
	else if (h == 12 && m == 59) { // For 12-hour clock - if hh:mm is 12:59, set added minute hh to '01' and mm to '00'
		h = 1;
		m = 0;
	}
	else if (h == 23 && m == 59) { // For 24-hour clock - if hh:mm is 23:59, set added minute hh to '24' and mm to '00'
		h = 24;
		m = 0;
	}
	else if (h == 24 && m == 00) { // For 24-hour clock - if hh:mm is 24:00, set added minute hh to '00' and mm to '01'
		h = 0;
		m = 1;
	} 
	else {
		m += 1;
	}
}

void addSecond(unsigned int& h, unsigned int& m, unsigned int& s) // Function to add one second
{
	if (s == 59) { // Change seconds to '00' after adding, if '59'
		s = 0;
		addMinute(h, m);
	}
	else {
		s += 1; 
	}					
}


std::string twoDigitString(unsigned int n) // Changes single or double digit int to string
{
	
	if (n >= 0 && n < 10) {
		return "0" + std::to_string(n); // If int n < 10, a "0" is prepended to the string representation of the number
	}
	else {
		return std::to_string(n); 
	}

}

std::string nCharString(size_t n, char c) // Function to multiply a char c by size n and print
{
	return std::string(n, c);
}

std::string get12HourFormat(unsigned int h, unsigned int m, unsigned int s) // Returns hh:mm:ss + AM or PM. Converts military time (24-hour) format to 12-hour format.
{
	amPm = "AM"; // Times not meeting the conditional(s) criteria will stick to "AM"

	if (h >= 13 && h <= 23) { // If hours is >=13 and <24, 12 is subtracted to produce 12-hour PM hours
		h = h - 12;
		amPm = "PM";
	}
	else if (h == 24) { // If hh is 24, 12 is subtracted to get '12 AM'
		h = h - 12;
		amPm = "AM";
	}
	else if (h == 12) { // Set '12' to 12 PM 
		amPm = "PM";
	}
	if (h == 0) { // Set '00' to 12 AM
		h = 12;
		amPm = "AM"; 
	}

	string hour;
	string minute;
	string second;
	

	hour = twoDigitString(h); // Applies twoDigitString format to each variable to convert int to two digit string
	minute = twoDigitString(m);
	second = twoDigitString(s);

	std::string twelveTime = hour + ":" + minute + ":" + second + " " + amPm;
	return twelveTime;
						 
}

std::string get24HourFormat(unsigned int h, unsigned int m, unsigned int s) // Gets 24-hour format in two digit string format
{
	string hour;
	string minute;
	string second;
	
	if (h == 24) { // Sets to '00' if hh is 24
		h = 0;
	}

	hour = twoDigitString(h); // Applies twoDigitString format to each variable to convert int to two digit string
	minute = twoDigitString(m);
	second = twoDigitString(s);

	std::string twentyfourTime = hour + ":" + minute + ":" + second + " ";
	return twentyfourTime;
}

void printClock(unsigned int& h, unsigned int& m, unsigned int& s) { // Prints out clock using nCharString which displays 12 and 24-hour displays of inputted time
	cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;
	cout << nCharString(1, '*') << nCharString(6, ' ') << "12-Hour Clock" << nCharString(6, ' ') << nCharString(1, '*') << nCharString(3, ' ');
	cout << nCharString(1, '*') << nCharString(6, ' ') << "24-Hour Clock" << nCharString(6, ' ') << nCharString(1, '*') << endl;
	cout << nCharString(1, '*') << nCharString(6, ' ') << get12HourFormat(h, m, s) << nCharString(8, ' ') << nCharString(1, '*') << nCharString(3, ' ');
	cout << nCharString(1, '*') << nCharString(8, ' ') << get24HourFormat(h, m, s) << nCharString(8, ' ') << nCharString(1, '*') << endl;
	cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;
}


void printMenu() { // Displays menu with options 1-4 using nCharString
	cout << nCharString(24, '*') << endl;
	cout << nCharString(1,'*') << nCharString(1, ' ') <<  "1---Add One Hour" << nCharString(5, ' ') << nCharString(1, '*') << endl;
	cout << nCharString(1, '*') << nCharString(1, ' ') << "2---Add One Minute" << nCharString(3, ' ') << nCharString(1, '*') << endl;
	cout << nCharString(1, '*') << nCharString(1, ' ') << "3---Add One Second" << nCharString(3, ' ') << nCharString(1, '*') << endl;
	cout << nCharString(1, '*') << nCharString(1, ' ') << "4---Exit Program" << nCharString(5, ' ') << nCharString(1, '*') << endl;
	cout << nCharString(24, '*') << endl;
}

unsigned int getMenuChoice() { // do while loop to get user choice from Menu
	unsigned int choice;

	do { // This repeats until a valid choice is entered
		cout << "Enter your choice (1-4): ";
		cin >> choice;

		if (choice >= 1 && choice <= 4) { // Checks if the input is within range 1-4 and breaks out of the loop
			break; 
		}
		else {
			cout << "Invalid entry. Please enter a number between 1 and 4." << endl;
		}
	} while (choice < 1 || choice > 4); // Condition for loop to repeat

	return choice; // Used in main function in switch statement
}





