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
#include "BarChart.h"

using namespace std;

namespace sdds {

	// Initializes the BarChart with all required class bars element.
	void BarChart::init(const char* title, int noOfSampels, char fill) {
		titleofchart = new char[strlen(title) + 1];
		strcpy(titleofchart, title);
		filler = fill;
		noofbars = noOfSampels;
		bars = new Bar[noofbars];
	}

	// Sets the next available Bar (in the dynamic Bar array), or does nothing if they are all already set.
	void BarChart::add(const char* bar_title, int value) {
		if (bars[noofsamples].isBarvalid(value))
		{
			bars[noofsamples].set(bar_title, filler, value);
			noofsamples++;
		}
	}

	// draws the bar chart
	void BarChart::draw() const {
		if (noofsamples == noofbars)
		{
			cout << titleofchart << "\n-----------------------------------------------------------------------" << endl;
			for (int i = 0; i < noofbars; i++)
			{
				bars[i].draw();
			}
			cout << "-----------------------------------------------------------------------" << endl;
		}
		else
		{
			cout << "Invalid Chart!" << endl;
		}
	}

	// Deallocates all the dynamically allocated memory.
	void BarChart::deallocate() {
		delete[] titleofchart;
		delete[] bars;
	}
}