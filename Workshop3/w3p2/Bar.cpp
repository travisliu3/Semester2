/*
*****************************************************************************
						OOP244-Workshop-3, part-2
Full Name  : Travis Liu
e-mail     : tliu84@myseneca.ca
Student ID#: 156740201
Date       : 1 June, 2022
Section    : ZCC

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "Bar.h"

using namespace std;

namespace sdds {
	
	// set the Bar to the empty state
	void Bar::setEmpty() {
		samplevalue = -1;
	}

	// set the title, fill character and value of the bar and set the function to an invalid state if the value is not acceptable
	void Bar::set(const char* name, char write, int value) {
		if (isBarvalid(value))
		{
			strcpy(title, name);
			filler = write;
			samplevalue = value;
		}
		else {
			setEmpty();
		}
	}

	// returns "if the Bar is valid or not"
	bool Bar::isBarvalid(int value) const{
		if (value >= 0 && value <= 100)
		{
			return true;
		}
		return false;
	}

	// draws bar
	void Bar::draw() const {
		if (isBarvalid(samplevalue))
		{
			cout.width(MAX_TITLE_LENGTH);
			cout.fill('.');
			cout.setf(ios::left);
			cout << title;
			cout << '|';
			for (int i = 0; i < samplevalue/2; i++)
			{
				cout << filler;
			}
			cout << endl;
			cout.unsetf(ios::left);
		}
	}
}