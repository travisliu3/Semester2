/*
*****************************************************************************
						OOP244-Workshop-5, part-2
Full Name  : Travis Liu
e-mail     : tliu84@myseneca.ca
Student ID#: 156740201
Date       : 16 June, 2022
Section    : ZCC

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstring>
#include "Power.h"

using namespace std;

namespace sdds {

	// Default constructor
	Power::Power() {
		this->setEmpty();
	}

	// Two argument constructor
	Power::Power(const char* name, int rarity) {
		this->createPower(name, rarity);
	}

	// Set to an empty state
	void Power::setEmpty() {
		m_name[0] = '\0';
		m_rarity = 0;
	}

	// Assign the instance variable
	void Power::createPower(const char* name, int rarity) {
		if (name && name[0] != '\0' && rarity > 0) {
			strncpy(this->m_name, name, MAX_NAME_LENGTH);
			this->m_rarity = rarity;
		}
		else {
			this->setEmpty();
		}
	}

	// Return m_name
	const char* Power::checkName() const {
		return m_name;
	}

	// Return m_rarity
	int Power::checkRarity() const {
		return m_rarity;
	}

	// Checks if Power class object is empty
	bool Power::isEmpty() const {
		return (m_name[0] == '\0' || m_rarity == 0);
	}

	// display the Power class object description
	void displayDetails(Power* powers, int size) {
		cout << "List of available powers: " << endl;
		for (int i = 0; i < size; i++) {
			if (!powers[i].isEmpty()) {
				cout << "  Name: " << powers[i].checkName() << ", "
					<< "Rarity: " << powers[i].checkRarity() << endl;
			}
		}
	}
}