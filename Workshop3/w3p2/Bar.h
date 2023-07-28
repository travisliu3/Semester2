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
#ifndef SDDS_BAR_H_
#define SDDS_BAR_H_

namespace sdds {
	const int MAX_TITLE_LENGTH = 20;
	class Bar {
		char title[MAX_TITLE_LENGTH + 1];
		char filler;
		int samplevalue;
	public:
		// set the Bar to the empty state
		void setEmpty();

		// set the title, fill character and value of the bar and set the function to an invalid state if the value is not acceptable
		void set(const char* name, char write, int value);
	
		// returns "if the Bar is valid or not"
		bool isBarvalid(int value) const;
		
		// draws bar
		void draw() const;
	};
}

#endif