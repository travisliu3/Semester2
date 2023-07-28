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
#ifndef SDDS_STUDENT_H_
#define SDDS_STUDENT_H_
namespace sdds {

	struct Student;

	// This overload of the load function returns a bool and receives a Student reference 
	// and read from the file to initialize Student reference with student data.
	bool load(struct Student &student);

	// This overload of the load function loads all the student records into
	// the Student array and returns a bool for successand has no arguments.
	bool load(const char* filename);

	// This overload of display function receives a constant student reference and prints it.
	void display(const struct Student &student);

	// First sort the array of Studentsand then display them one by one with a row number.
	// See the sample output.
	void display();

	// In a loop go through all the elements of the student array and deallocate the dynamic
	// name of each student. Then deallocate the whole student array.
	void deallocateMemory();

	// This function sorts the dynamic array of students based on the Grade of the students.
	void sort();
}
#endif // !SDDS_STUDENT_H_