
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
#ifndef SDDS_POWER_H
#define SDDS_POWER_H


namespace sdds {
	const int MAX_NAME_LENGTH = 50;

	class Power {
		char m_name[MAX_NAME_LENGTH + 1];
		int m_rarity;

	public:
		Power();  // Default constructor
		Power(const char* name, int rarity);  // Two argument constructor
		void setEmpty();  // Set to an empty state
		void createPower(const char* name, int rarity);  // Assign the instance variable
		const char* checkName() const;  // Return m_name
		int checkRarity() const;  // Return m_rarity
		bool isEmpty() const;  // Checks if Power class object is empty
	};
	void displayDetails(Power* powers, int size);  // display the Power class object description
}
#endif