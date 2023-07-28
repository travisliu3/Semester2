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
#ifndef SDDS_CAR_H__
#define SDDS_CAR_H__

namespace sdds {
	
	class CleanerBot {
		char* location;
		double battery;
		int brush;
		bool active;
	public:
		CleanerBot();  // Default constructor
		CleanerBot(const char* location, const double battery, const int brush, const bool active);  // 4 argument constructor
		~CleanerBot();  // Deconstructor
		CleanerBot& set(char* location, double battery, int brush, bool active);  // to set the robot information (same order as the constructor)
		void setLocation(char* location);  // to set the robot location
		void setActive(bool active);  // to set the robot active status (true or false)
		char* getLocation() const;  // to return the robot location
		double getBattery() const;  // to return the robot remaining battery percentage
		int getBrush() const;  // to return the robot number of brushes
		bool isActive() const;  // to return if a robot is active
		bool isValid() const;  // to return if the robot information is valid
		void display() const;  // to display the information
	};
	void report(CleanerBot* bot, const short num_bots);  // receives an array of robots and prints a report of their information

}

#endif