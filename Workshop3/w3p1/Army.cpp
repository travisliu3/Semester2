/*
*****************************************************************************
						OOP244-Workshop-3, part-1
Full Name  : Travis Liu
e-mail     : tliu84@myseneca.ca
Student ID#: 156740201
Date       : 31 May, 2022
Section    : ZCC

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "Army.h"

using namespace std;

namespace sdds {
	void Army::setEmpty() {
		if (nationality[0] == '\0' && units < 0)
		{
			nationality[MAX_NAME_LEN] = { '\0' };
			units = 0;
		}
	}
	void Army::createArmy(const char* country, double pow, int troops) {
		if (country != nullptr && strlen(country) > 0 && troops > 0 && pow > 0)
		{
			strcpy(nationality, country);
			units = troops;
			power = pow;
		}
		else {
			setEmpty();
		}
	}
	void Army::updateUnits(int troops) {
		units += troops;
		power += 0.25 * troops;
	}
	const char* Army::checkNationality() const {
		return nationality;
	}
	int Army::checkCapacity() const {
		return units;
	}
	double Army::checkPower() const {
		cout.setf(ios::fixed);
		cout.precision(1);
		return power;
	}
	bool Army::isEmpty() const {
		if (nationality[0] == '\0' && units == 0)
		{
			return true;
		}
		else {
			return false;
		}
	}
	bool Army::isStrongerThan(const Army& army) const {
		if (power > army.power)
		{
			return true;
		}
		return false;
	}

	void battle(Army& arm1, Army& arm2) {
		if (!arm1.isEmpty() && !arm2.isEmpty())
		{
			if (arm1.isStrongerThan(arm2))
			{
				arm2.updateUnits((int)(0.5 * (arm2.checkCapacity() * -1)));
				cout << "In battle of " << arm1.checkNationality() << " and " << arm2.checkNationality() << ", " << arm1.checkNationality() << " is victorious!" << endl;
			}
			else {
				arm1.updateUnits((int)(0.5 * (arm1.checkCapacity() * -1)));
				cout << "In battle of " << arm1.checkNationality() << " and " << arm2.checkNationality() << ", " << arm2.checkNationality() << " is victorious!" << endl;
			}
		}
	}
	void displayDetails(const Army* armies, int size) {
		cout << "Armies reporting to battle: " << endl;
		for (int i = 0; i < size; i++)
		{
			if (!armies[i].isEmpty())
			{
				cout << "Nationality: " << armies[i].checkNationality()
					<< ", Units Count: " << armies[i].checkCapacity()
					<< ", Power left: " << armies[i].checkPower() << endl;
			}
		}
	}
}