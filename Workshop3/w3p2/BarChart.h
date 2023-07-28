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
#ifndef SDDS_BARCHART_H_
#define SDDS_BARCHART_H_

namespace sdds {
	class Bar;
	class BarChart {
		char* titleofchart;
		Bar* bars;
		char filler;
		int noofbars;
		int noofsamples = 0;
	public:

		// Initializes the BarChart with all required class bars element.
		void init(const char* title, int noOfSampels, char fill);
		
		// Sets the next available Bar (in the dynamic Bar array), or does nothing if they are all already set.
		void add(const char* bar_title, int value);
		
		// draws the bar chart
		void draw() const;

		// Deallocates all the dynamically allocated memory.
		void deallocate();
	};
}

#endif