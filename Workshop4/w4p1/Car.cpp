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
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
#include "Car.h"

using namespace std;

namespace sdds {

	// Set the data members to a safe empty state
	void Car::resetInfo() {
		m_type = nullptr;
		m_brand = nullptr;
		m_model = nullptr;
		m_year = 0;
		m_code = 0;
		m_price = 0;
	}

	// Default constructor
	Car::Car() {
		resetInfo();
	}

	// Parameterized constructor
	Car::Car(const char* type, const char* brand, const char* model, int year, int code, double price) {
		if ((type != nullptr) &&
			(brand != nullptr) &&
			(model != nullptr) &&
			year >= 1990 &&
			(code >=100 || code < 1000) &&
			price > 0)
		{
			m_type = new char[strlen(type) + 1];
			m_brand = new char[strlen(brand) + 1];
			m_model = new char[strlen(model) + 1];
			strcpy(m_type, type);
			strcpy(m_brand, brand);
			strcpy(m_model, model);
			m_year = year;
			m_code = code;
			m_price = price;
		}
		else
		{
			resetInfo();
		}
	}

	// Destructor
	Car::~Car() {
		delete[] m_type;
		delete[] m_brand;
		delete[] m_model;
	}

	// sets the attributes to the corresponding arguments exactly like the 6 argument constructor
	Car& Car::setInfo(const char* type, const char* brand, const char* model, int year, int code, double price) {
		delete[] m_type;
		m_type = nullptr;
		delete[] m_brand;
		m_brand = nullptr;
		delete[] m_model;
		m_model = nullptr;
		if ((type != nullptr) &&
			(brand != nullptr) &&
			(model != nullptr) &&
			year >= 1990 &&
			(code >= 100 && code < 1000) &&
			price > 0)
		{
			m_type = new char[strlen(type) + 1];
			m_brand = new char[strlen(brand) + 1];
			m_model = new char[strlen(model) + 1];
			strcpy(m_type, type);
			strcpy(m_brand, brand);
			strcpy(m_model, model);
			m_year = year;
			m_code = code;
			m_price = price;
		}
		else
		{
			resetInfo();
		}
		return *this;
	}

	// prints the values of all the member variables on the screen
	void Car::printInfo() const {
		cout.setf(ios::fixed);
		cout << "| ";
		cout.width(10);
		cout.setf(ios::left);
		cout << this->m_type;
		cout << " | ";
		cout.width(16);
		cout << this->m_brand;
		cout << " | ";
		cout.width(16);
		cout << this->m_model;
		cout << " | ";
		cout.width(5);
		cout << this->m_year;
		cout << "|  ";
		cout.width(4);
		cout << this->m_code;
		cout << "| ";
		cout.unsetf(ios::left);
		cout.setf(ios::right);
		cout.width(9);
		cout.precision(2);
		cout << this->m_price << ' ';
		cout.unsetf(ios::fixed);
		cout.unsetf(ios::right);
		cout << "|" << endl;
	}

	// returns whether all member variables have valid values or not based on the criteria
	bool Car::isValid() const {
		if ((m_type != nullptr) &&
			(m_brand != nullptr) &&
			(m_model != nullptr) &&
			m_year >= 1990 &&
			(m_code >= 100 || m_code < 1000) &&
			m_price > 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	// check whether the type, make, brand and year of an object of Car are equal to another object of this class
	bool Car::isSimilarTo(const Car& car) const {
		if (this->isValid())
		{
			if (*this->m_type == *car.m_type && *this->m_brand == *car.m_brand && *this->m_model == *car.m_model && this->m_year == car.m_year)
			{
				return true;
			}
		}
		return false;
	}

	// It returns true if it finds two Car objects that have similar information in the car array
	bool has_similar(const Car car[], const int num_cars) {
		for (int i = 0; i < num_cars; i++) {
			for (int j = i + 1; j < num_cars; j++) {
				if (car[i].isSimilarTo(car[j])) {
					return true;
				}
			}
		}
		return false;
	}

	// Checks for any invalid data in the array
	bool has_invalid(const Car car[], const int num_cars) {
		for (int i = 0; i < num_cars; i++) {
			if (!car[i].isValid())
			{
				return true;
			}
		}
		return false;
	}

	// print and array of valid Cars and ignore the invalid Cars
	void print(const Car car[], const int num_cars) {
		for (int i = 0; i < num_cars; i++)
		{
			if (car[i].isValid())
			{
				car[i].printInfo();
			}
		}
	}

}