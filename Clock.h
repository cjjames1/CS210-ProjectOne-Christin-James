// Header file for declarations of functions 
#pragma once
#ifndef ADD_H_INCLUDED   // Header file guard
#define ADD_H_INCLUDED
#include <string>

void addHour(unsigned int& h);
void addMinute(unsigned int& h, unsigned int& m);
void addSecond(unsigned int& h, unsigned int& m, unsigned int& s);
std::string get12HourFormat(unsigned int h, unsigned int m, unsigned int s);
std::string get24HourFormat(unsigned int h, unsigned int m, unsigned int s);

std::string twoDigitString(unsigned int n); 
std::string nCharString(size_t , char);

void printClock(unsigned int& h, unsigned int& m, unsigned int& s);
void printMenu();
unsigned int getMenuChoice();
#endif // Ending header file guard
