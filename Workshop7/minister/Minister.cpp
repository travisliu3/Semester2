/*
*****************************************************************************
						OOP244-Workshop-7
Full Name  : Travis Liu
e-mail     : tliu84@myseneca.ca
Student ID#: 156740201
Date       : 14 July, 2022
Section    : ZCC

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include"Minister.h"

using namespace std;

namespace sdds {

	// constructor
	Minister::Minister(const char mpid[], int mpage, int year, const char name[], const char district[]) : MemberParliament(mpid, mpage)
	{
		powyear = year;
		NewDistrict(district);
		strcpy(primename, name);
	}

	// a mutator that updates the PM the minister reports to.
	void Minister::changePM(const char* pm)
	{
		for (int i = 0; primename[i] != '\0'; i++)
		{
			primename[i] = '\0';
		}
		strcpy(primename, pm);
	}

	// a mutator that updates the year the minister assumed office
	void Minister::assumeOffice(double year)
	{
		powyear = year;
	}

	// a query that inserts into os the content of the object
	ostream& Minister::write(ostream& os)
	{
		MemberParliament::write(os);
		os << " | " << primename << "/" << powyear;
		return os;
	}

	// a mutator that reads from the stream in the data for the current object
	istream& Minister::read(istream& in)
	{
		MemberParliament::read(in);
		cout << "Reports TO: ";
		in >> primename;
		cout << "Year Assumed Office: ";
		in >> powyear;
		return in;
	}

	// insert a Minister into a stream
	ostream& operator<<(ostream& os, Minister member)
	{
		member.write(os);
		return os;
	}

	// extract a Minister from a stream
	istream& operator>>(istream& in, Minister& member)
	{
		member.read(in);
		return in;
	}

}