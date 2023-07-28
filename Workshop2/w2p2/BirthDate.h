/*
*****************************************************************************
						OOP244-Workshop-2, part-2
Full Name  : Travis Liu
e-mail     : tliu84@myseneca.ca
Student ID#: 156740201
Date       : 26 May, 2022
Section    : ZCC

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef _SDDS_BIRTHDATE_H_
#define _SDDS_BIRTHDATE_H_
namespace sdds {

	// Opens the datafile.
	bool beginSearch(const char* filename);
	
	// Reads the birth records matching the month. If at least one record is matched and read, turns true, otherwise false.
	bool readBirthDate(int month);
	
	// Sorts the records based on the year of birth in descending order.
	void sort();

	// Displays the found records as displayed in the execution sample.
	void displayBirthdays();

	// Releases all the dynamically allocated memory.
	void deallocate();

	// Finalizes the program by making sure all resources are released and closed.
	void endSearch();
}
#endif