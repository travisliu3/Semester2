/*
*****************************************************************************
							OOP244-Workshop-9
Full Name  : Travis Liu
e-mail     : tliu84@myseneca.ca
Student ID#: 156740201
Date       : 26 July, 2022
Section    : ZCC

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

using namespace std;

#include "Name.h"

namespace sdds {

	// Creates an empty name
	Name::Name() {
		m_value = nullptr;
	}
	
	// Keeps a dynamic copy of the name in the Name object.
	Name::Name(const char* name) {
		m_value = new char[strlen(name) + 1];
		strcpy(m_value, name);
	}
	
	Name::~Name() {
		delete[] m_value;
	}

	Name::Name(const Name& name) {
		if (name)
		{
			m_value = new char[strlen((const char*)name) + 1];
			strcpy(m_value, (const char*)name);
		}
		else
		{
			m_value = nullptr;
		}
	}

	void Name::operator=(const Name& name) {
		delete[] m_value;
		if (name)
		{
			m_value = new char[strlen((const char*)name) + 1];
			strcpy(m_value, (const char*)name);
		}
	}

	// Returns the address of the dynamic Cstring.
	Name::operator const char* ()const {
		return m_value;
	}
	
	// Return true if name is not empty, otherwise, it returns false.
	Name::operator bool()const {
		return (m_value != nullptr);
	}
	
	// Inserts the Cstring value into ostr without going to new line if the Name is valid and then returns the ostr;
	ostream& Name::display(ostream& ostr)const {
		if (m_value != nullptr)
		{
			ostr << m_value;
		}
		return ostr;
	}
	
	// Dynamically reads the Cstring from istr without any spaces(stops at space) and keeps the address in the m_value pointer.
	// If the read is successful it will ignore one character from istr.
	// returns istr at end.
	istream& Name::read(istream& istr) {
		char value[30 + 1];
		istr >> value;
		if (!istr.fail())
		{
			istr.ignore();
			m_value = new char[strlen(value) + 1];
			strcpy(m_value, value);
		}
		return istr;
	}
	
	ostream& operator<<(ostream& os, const Name& name) {
		name.display(os);
		return os;
	}

	istream& operator>>(istream& is, Name& name) {
		name.read(is);
		return is;
	}

}