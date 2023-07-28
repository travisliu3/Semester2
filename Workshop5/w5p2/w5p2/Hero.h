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
#ifndef SDDS_HERO_H
#define SDDS_HERO_H
#include "power.h"

namespace sdds {
	class Hero {
		char heroname[MAX_NAME_LENGTH];
		Power* power;
		int numpowers;
		int powerlevel;
	public:
		Hero();  // Default constructor
		Hero(const char name[], Power* pow, int numpow);  // Three argument constructor
		~Hero();  // destructor
		std::ostream& display()const;  // display the Hero class object description
		void increasepower();  // Increase powerlevel
		int powerlev() const;  // Return powerlevel
		Power* powr();  // Return pointer to class Power object
		int increasedpowr();  // Increament numpower
		void operator+=(Power& pow);  // Add a new power class to to the power array
		void operator-=(int powlev);  // reduce the powerlevel
	};
	bool operator<(Hero hero1, Hero hero2);  // compare two Hero classes based on powerlevel
	bool operator>(Hero hero1, Hero hero2);  // compare two Hero classes based on powerlevel
	void operator>>(Power& pow, Hero& hero);  // Add a new power class to to the power array
	void operator<<(Hero& hero, Power& pow);  // Add a new power class to to the power array

}
#endif