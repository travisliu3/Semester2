/*
*****************************************************************************
						OOP244-Workshop-4, part-1
Full Name  : Travis Liu
e-mail     : tliu84@myseneca.ca
Student ID#: 156740201
Date       : 8 June, 2022
Section    : ZCC

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_CAR_H__
#define SDDS_CAR_H__

namespace sdds {
	class Car {
		char* m_type;
		char* m_brand;
		char* m_model;
		int m_year;
		int m_code;
		double m_price;
		void resetInfo(); // Set the data members to a safe empty state
	public:
		Car();  // Default constructor
		Car(const char* type, // Parameterized constructor
			const char* brand,
			const char* model,
			int year = 2022,
			int code = 100,
			double price = 1);
		Car& setInfo(const char* type, // sets the attributes to the corresponding arguments exactly like the 6 argument constructor
			const char* brand,
			const char* model,
			int year,
			int code,
			double price);
		~Car(); // Destructor
		void printInfo() const;  // prints the values of all the member variables on the screen
		bool isValid() const;  // returns whether all member variables have valid values or not based on the criteria
		bool isSimilarTo(const Car& car) const;  // check whether the type, make, brand and year of an object of Car are equal to another object of this class
	};
	bool has_similar(const Car car[], const int num_cars);  // It returns true if it finds two Car objects that have similar information in the car array
	bool has_invalid(const Car car[], const int num_cars);  // Checks for any invalid data in the array
	void print(const Car car[], const int num_cars);  // print and array of valid Cars and ignore the invalid Cars
}

#endif