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
#include "hero.h"

using namespace std;

namespace sdds {

	// Default constructor
	Hero::Hero() {
		heroname[0] = '\0';
		power = nullptr;
		numpowers = 0;
		powerlevel = 0;
	}

	// Three argument constructor
	Hero::Hero(const char name[], Power* pow, int numpow) {
		if (name[0] != '\0' && pow != nullptr && numpow != 0)
		{
			strcpy(heroname, name);
			power = nullptr;
			power = new Power[numpow + 1];
			for (int i = 0; i < numpow; i++)
			{
				power[i].createPower(pow[i].checkName(), pow[i].checkRarity());
			}
			numpowers = numpow;
			increasepower();
		}
		else
		{
			heroname[0] = '\0';
			power = nullptr;
			numpowers = 0;
			powerlevel = 0;
		}
	}

	// destructor
	Hero::~Hero() {
		delete[] power;
	}

	// display the Hero class object description
	std::ostream& Hero::display()const {
		cout << "Name: " << heroname << endl;
		cout << "List of available powers: " << endl;
		for (int i = 0; i < numpowers; i++)
		{
			cout << "  Name: " << power[i].checkName() << ", Rarity: " << power[i].checkRarity() << endl;
		}
		cout << "Power Level: " << powerlevel;
		return cout;
	}

	// Add a new power class to to the power array
	void Hero::operator+=(Power& pow) {
		numpowers++;
		for (int i = 0; i < numpowers; i++)
		{
			if (power[i].isEmpty())
			{
				this->power[i].createPower(pow.checkName(), pow.checkRarity());
			}
		}
		increasepower();
	}

	// reduce the powerlevel
	void Hero::operator-=(int powlev) {
		powerlevel -= powlev;
	}

	// Return powerlevel
	int Hero::powerlev() const{
		return powerlevel;
	}

	// Return pointer to class Power object
	Power* Hero::powr() {
		return power;
	}

	// compare two Hero classes based on powerlevel
	bool operator<(Hero hero1, Hero hero2) {
		if (hero1.powerlev() < hero2.powerlev())
		{
			return true;
		}
		return false;
	}

	// compare two Hero classes based on powerlevel
	bool operator>(Hero hero1, Hero hero2) {
		if (hero1.powerlev() > hero2.powerlev())
		{
			return true;
		}
		return false;
	}

	// Increase powerlevel
	void Hero::increasepower() {
		int rar = 0;
		for (int i = 0; i < numpowers; i++)
		{
			rar += power[i].checkRarity();
		}
		powerlevel = rar * numpowers;
	}

	// Increament numpower
	int Hero::increasedpowr() {
		return ++numpowers;
	}

	// Add a new power class to to the power array
	void operator>>(Power& pow, Hero& hero) {
		int increasedpow = hero.increasedpowr();
		for (int i = 0; i < increasedpow; i++)
		{
			if (hero.powr()[i].isEmpty())
			{
				hero.powr()[i].createPower(pow.checkName(), pow.checkRarity());
			}
		}
		hero.increasepower();
	}

	// Add a new power class to to the power array
	void operator<<(Hero& hero, Power& pow) {
		int increasedpow = hero.increasedpowr();
		for (int i = 0; i < increasedpow; i++)
		{
			if (hero.powr()[i].isEmpty())
			{
				hero.powr()[i].createPower(pow.checkName(), pow.checkRarity());
			}
		}
		hero.increasepower();
	}

}