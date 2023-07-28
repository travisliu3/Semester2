/*
*****************************************************************************
						OOP244-Workshop-7
Full Name  : Travis Liu
e-mail     : tliu84@myseneca.ca
Student ID#: 156740201
Date       : 14 July, 2022
Section    : ZCC

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef _SDDS_MINISTER_H__
#define _SDDS_MINISTER_H__

#include"MemberParliament.h"

namespace sdds {

	const int PRIME_MINISTER_NAME = 50;

	class Minister : public MemberParliament
	{
		char primename[PRIME_MINISTER_NAME + 1];
		double powyear;
	public:
		Minister(const char mpid[], int mpage, int powyear, const char district[], const char name[]);  // constructor
		void changePM(const char* pm);  // a mutator that updates the PM the minister reports to.
		void assumeOffice(double year);  // a mutator that updates the year the minister assumed office
		std::ostream& write(std::ostream& os);  // a query that inserts into os the content of the object
		std::istream& read(std::istream& in);  // a mutator that reads from the stream in the data for the current object
	};
	std::ostream& operator<<(std::ostream& os, Minister member);  // insert a Minister into a stream
	std::istream& operator>>(std::istream& in, Minister& member);  // extract a Minister from a stream

}

#endif