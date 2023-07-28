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
#include"MemberParliament.h"

using namespace std;

namespace sdds {

	// Set the district the MP represents as Unassigned. Assume all data is valid.
	MemberParliament::MemberParliament(const char mpid[], int mpage)
	{
		strcpy(id, mpid);
		age = mpage;
		strcpy(mpdistrict, "Unassigned");
	}

	// assigns the MP to new district. Prints to the screen the message
	void MemberParliament::NewDistrict(const char* district)
	{
		cout << "|  " << id << "| |";
		cout.width(20);
		cout << mpdistrict;
		cout << " ---> ";
		cout.setf(ios::left);
		cout.width(23);
		cout << district;
		cout.unsetf(ios::left);
		cout  << "|" << endl;
		for (int i = 0; mpdistrict[i] != '\0'; i++)
		{
			mpdistrict[i] = '\0';
		}
		strcpy(mpdistrict, district);
	}

	// a query that inserts into cout the content of the object in the format
	ostream& MemberParliament::write(ostream& os)
	{
		os << "| " << id << " | " << age << " | " << mpdistrict;
		return os;
	}

	// a mutator that reads from the stream cin the data for the current object
	istream& MemberParliament::read(istream& in)
	{
		cout << "Age: ";
		in >> age;
		cout << "Id: ";
		in >> id;
		cout << "District: ";
		in >> mpdistrict;
		return in;
	}

	// insert a MemberParliament into a stream
	ostream& operator<<(ostream& os, MemberParliament member)
	{
		member.write(os);
		return os;
	}

	// extract a MemberParliament from a stream
	istream& operator>>(istream& in, MemberParliament& member)
	{
		member.read(in);
		return in;
	}

}