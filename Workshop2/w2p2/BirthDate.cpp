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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "BirthDate.h"

using namespace std;

namespace sdds {
	struct Birthdate {
		char* name;
		int mm;
		int dd;
		int yyyy;
	}employee;

	FILE* fptr = NULL;
	int employeenumbermonth;
	Birthdate* employees = nullptr;

	// Opens the datafile.
	bool beginSearch(const char* filename) {
		fptr = fopen(filename, "r");
		if (fptr != NULL)
		{
			cout << "Birthdate search program" << endl;
			return true;
		}
		cout << "Data file \"" << filename << "\" not found!" << endl;
		return false;
	}

	// Reads the birth records matching the month.If at least one record is matchedand read, turns true, otherwise false
	bool readBirthDate(int month) {
		int employeenumber = 1;
		char ch;
		while (fscanf(fptr, "%c", &ch) == 1) {
			employeenumber += (ch == '\n');
		}
		rewind(fptr);
		employeenumbermonth = 0;
		char name[30 + 1] = { '\0' };
		for (int i = 0; i < employeenumber; i++)
		{
			fscanf(fptr, "%[^,],%d/%d/%d", name, &employee.mm, &employee.dd, &employee.yyyy);
			if (employee.mm == month)
			{
				employeenumbermonth++;
			}
		}
		rewind(fptr);
		employees = new Birthdate[employeenumbermonth];
		int j = 0;
		for (int i = 0; i < employeenumber; i++)
		{
			fscanf(fptr, "%[^,],%d/%d/%d\n", name, &employee.mm, &employee.dd, &employee.yyyy);
			if (employee.mm == month)
			{
				employees[j].name = new char[strlen(name) + 1];
				strcpy(employees[j].name, name);
				employees[j].mm = employee.mm;
				employees[j].dd = employee.dd;
				employees[j].yyyy = employee.yyyy;
				j++;
			}
		}
		rewind(fptr);
		if (employeenumbermonth)
		{
			cout << employeenumbermonth << " birthdates found:" << endl;
			return true;
		}
		return false;
	}

	// Sorts the records based on the year of birth in descending order.
	void sort() {
		for (int i = 0; i < employeenumbermonth - 1; i++)
		{
			for (int j = 0; j < employeenumbermonth - 1 - i; j++)
			{
				if (employees[j].yyyy >= employees[j + 1].yyyy)
				{
					employee.dd = employees[j].dd;
					employees[j].dd = employees[j + 1].dd;
					employees[j + 1].dd = employee.dd;
					employee.mm = employees[j].mm;
					employees[j].mm = employees[j + 1].mm;
					employees[j + 1].mm = employee.mm;
					employee.yyyy = employees[j].yyyy;
					employees[j].yyyy = employees[j + 1].yyyy;
					employees[j + 1].yyyy = employee.yyyy;
					employee.name = employees[j].name;
					employees[j].name = employees[j + 1].name;
					employees[j + 1].name = employee.name;
				}
			}
		}
	}

	// Displays the found records as displayed in the execution sample.
	void displayBirthdays() {
		for (int i = 0; i < employeenumbermonth; i++)
		{
			cout << i + 1 << ") " << employees[i].name << ':' << endl;
			cout << employees[i].yyyy << '-' << employees[i].mm << '-' << employees[i].dd << endl;
			cout << "===================================" << endl;
		}
	}

	// Releases all the dynamically allocated memory.
	void deallocate() {
		for (int i = 0; i < employeenumbermonth; i++)
		{
			delete[] employees[i].name;
		}
		delete[] employees;
	}

	// Finalizes the program by making sure all resources are released and closed.
	void endSearch() {
		fclose(fptr);
		fptr = NULL;
		employees = NULL;
		cout << "Birthdate Search Program Closed." << endl;
	}
}