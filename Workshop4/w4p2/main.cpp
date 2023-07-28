/* ------------------------------------------------------
Workshop 4 part 2
Module: N/A
Filename: main.cpp
Version 1.0
Author: Asad Norouzi
-----------------------------------------------------------*/
/*
*****************************************************************************
						OOP244-Workshop-4, part-2
Full Name  : Travis Liu
e-mail     : tliu84@myseneca.ca
Student ID#: 156740201
Date       : 9 June, 2022
Section    : ZCC

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include <iostream>
#include "CleanerBot.h"

using namespace std;
using namespace sdds;

int main()
{
	const int num_bots = 8;
	CleanerBot bot[num_bots] = {
		{},
		{"library", 82.5, 7, false},
		{"corridor", 75, 3, true},
		{"pantry", 23.6, 12, false},
		{"parking", 30.1, 9, true},
		{"storage", 57, 2, true},
		{"?", -1, 1, false},
		{"basement", 29.9, 1, true}
	};

	report(bot, num_bots);

	return 0;
}