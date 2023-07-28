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

#include "FullName.h"

namespace sdds {

	// Creates an empty FullName.
	FullName::FullName() {
		m_value = nullptr;
	}
	
	// Passess name to the constructor of the base class and dynamically keeps a copy of lastName in the m_value of FullName
	FullName::FullName(const char* name, const char* lastName): Name(name) {
		m_value = new char[strlen(lastName) + 1];
		strcpy(m_value, lastName);
	}
	
	FullName::~FullName() {
		delete[] m_value;
	}

	FullName::FullName(FullName& name): Name(name) {
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

	void FullName::operator=(const FullName& name) {
		delete[] m_value;
		Name::operator=(name);
		if (name)
		{
			m_value = new char[strlen((const char*)name) + 1];
			strcpy(m_value, (const char*)name);
		}
	}

	// Returns the address of the m_value in the FullName.
	FullName::operator const char* ()const {
		return m_value;
	}
	
	// Returns true only if both FullName and Name are not empty.
	FullName::operator bool()const {
		return (m_value != nullptr && Name::operator bool());
	}
	
	// If the FullName is not empty it will insert the Name, one space and then the m_value of the FullName into the ostream reference without going to the new line.
	// Then it will return the ostream reference.
	ostream& FullName::display(ostream& ostr)const {
		if (m_value != nullptr)
		{
			Name::display(ostr);
			ostr << " " << m_value;
		}
		return ostr;
	}
	
	// Reads the Name and then dynamically reads a Cstring into the m_value of FullName from istream until it reaches the newline character.
	// The newline character is removed from istream and the istream reference is returned.
	istream& FullName::read(istream& istr) {
		Name::read(istr);
		char value[30 + 1];
		istr.get(value, 1000, '\n');
		if (!istr.fail())
		{
			m_value = new char[strlen(value) + 1];
			strcpy(m_value, value);
		}
		return istr;
	}
	
}