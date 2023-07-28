/*
*****************************************************************************
						OOP244-Workshop-2, part-1
Full Name  : Travis Liu
e-mail     : tliu84@myseneca.ca
Student ID#: 156740201
Date       : 25 May, 2022
Section    : ZCC

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {

	// Opens the data file for reading
	bool openFile(const char filename[]);

	// Closes the data file
	void closeFile();

	// Returns an integer that is the number of records in the file
	int noOfRecords();

	// read function for the student name
	bool read(char* m_name);

	// read function for the student number
	bool read(int &m_studentNumber);

	// read function for the student grade
	bool read(char &m_grade);
}
#endif // !SDDS_FILE_H_