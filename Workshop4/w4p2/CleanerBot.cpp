/*
*****************************************************************************
						OOP244-Workshop-4, part-2
Full Name  : Travis Liu
e-mail     : tliu84@myseneca.ca
Student ID#: 156740201
Date       : 9 June, 2022
Section    : ZCC

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
#include "CleanerBot.h"

using namespace std;

namespace sdds {

	// Default constructor
	CleanerBot::CleanerBot() {
		location = nullptr;
		battery = 0;
		brush = 0;
		active = false;
	}

	// 4 argument constructor
	CleanerBot::CleanerBot(const char* loc, const double batt, const int bru, const bool act) {
		if (loc != nullptr &&
			batt != 0 &&
			bru != 0)
		{
			location = new char[strlen(loc) + 1];
			strcpy(location, loc);
			battery = batt;
			brush = bru;
			active = act;
		}
		else {
			location = nullptr;
			battery = 0;
			brush = 0;
			active = false;
		}
	}

	// Deconstructor
	CleanerBot::~CleanerBot() {
		delete[] location;
	}

	// to set the robot information (same order as the constructor)
	CleanerBot& CleanerBot::set(char* loc, double batt, int bru, bool act) {
		delete[] location;
		location = nullptr;
		if (loc != nullptr &&
			batt > 0 &&
			bru > 0)
		{
			location = new char[strlen(loc) + 1];
			setLocation(loc);
			battery = batt;
			brush = bru;
			setActive(act);
		}
		else
		{
			location = nullptr;
			battery = 0;
			brush = 0;
			active = false;
		}
		return *this;
	}

	// to set the robot location
	void CleanerBot::setLocation(char* loc) {
		strcpy(location, loc);
	}

	// to set the robot active status (true or false)
	void CleanerBot::setActive(bool act) {
		active = act;
	}

	// to return the robot location
	char* CleanerBot::getLocation() const {
		return location;
	}

	// to return the robot remaining battery percentage
	double CleanerBot::getBattery() const {
		return battery;
	}

	// to return the robot number of brushes
	int CleanerBot::getBrush() const {
		return brush;
	}

	// to return if a robot is active
	bool CleanerBot::isActive() const {
		return active;
	}

	// to return if the robot information is valid
	bool CleanerBot::isValid() const {
		if (location != nullptr &&
			battery > 0 &&
			brush > 0)
		{
			return true;
		}
		return false;
	}

	// to display the information
	void CleanerBot::display() const {
		cout.setf(ios::fixed);
		cout << "| ";
		cout.width(10);
		cout.setf(ios::left);
		cout << this->getLocation();
		cout << " | ";
		cout.unsetf(ios::left);
		cout.setf(ios::right);
		cout.width(7);
		cout.precision(1);
		cout << this->getBattery();
		cout << " | ";
		cout.width(18);
		cout << this->getBrush();
		cout << " | ";
		cout.unsetf(ios::right);
		cout.setf(ios::left);
		cout.width(7);
		if (this->isActive()) {
			cout << "YES";
		}
		else {
			cout << "NO";
		}
		cout.unsetf(ios::left);
		cout << "|" << endl;
		cout.unsetf(ios::fixed);
	}

	// receives an array of robots and prints a report of their information
	void report(CleanerBot* bot, const short num_bots) {
		int invalid = 0;
		int lowbattery = 0;
		CleanerBot tempbot;
		cout << "         ------ Cleaner Bots Report -----" << endl;
		cout << "     ---------------------------------------" << endl;
		cout << "| Location   | Battery |  Number of Brushes | Active |" << endl;
		cout << "|------------+---------+--------------------+--------|" << endl;
		for (int i = 0; i < num_bots; i++)
		{
			if (bot[i].isValid())
			{
				bot[i].display();
			}
			else {
				invalid++;
			}
			if (bot[i].getBattery() < 30)
			{
				lowbattery = 1;
			}
		}
		cout << endl;
		if (lowbattery)
		{
			cout << "|====================================================|" << endl;
			cout << "| LOW BATTERY WARNING:                               |" << endl;
			cout << "|====================================================|" << endl;
			cout << "| Number of robots to be charged: " << invalid << "                  |" << endl;
			cout << "| Sorting robots based on their available power:     |" << endl;
			cout << "| Location   | Battery |  Number of Brushes | Active |" << endl;
			cout << "|------------+---------+--------------------+--------|" << endl;
			for (int i = 0; i < num_bots - 1; i++)
			{
				for (int j = 0; j < num_bots - i - 1; j++)
				{
					if (bot[j].isValid())
					{
						if (bot[j + 1].isValid())
						{
							if (bot[j].getBattery() < bot[j + 1].getBattery())
							{
								tempbot = bot[j];
								bot[j] = bot[j + 1];
								bot[j + 1] = tempbot;
							}
						}
						else
						{
							int k = j + 1;
							while (!bot[k].isValid())
							{
								k++;
							}
							if (bot[j].getBattery() < bot[k].getBattery())
							{
								tempbot = bot[j];
								bot[j] = bot[k];
								bot[k] = tempbot;
							}
						}
					}
				}
			}
			for (int i = 0; i < num_bots; i++)
			{
				if (bot[i].isValid())
				{
					bot[i].display();
				}
			}
			cout << "|====================================================|" << endl;
		}
	}

}