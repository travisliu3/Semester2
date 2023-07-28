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
#ifndef _SDDS_MEMBERPARLIAMENT_H__
#define _SDDS_MEMBERPARLIAMENT_H__

namespace sdds {

	const int ID_LENGTH = 32;
	const int DISTRICT_LENGTH = 64;

	class MemberParliament
	{
		char id[ID_LENGTH + 1];
		char mpdistrict[DISTRICT_LENGTH + 1];
		int age;
	public:
		MemberParliament(const char mpid[], int mpage);  // Set the district the MP represents as Unassigned. Assume all data is valid.
		void NewDistrict(const char* district);  // assigns the MP to new district. Prints to the screen the message
		std::ostream& write(std::ostream& os);  // a query that inserts into cout the content of the object in the format
		std::istream& read(std::istream& in);  // a mutator that reads from the stream cin the data for the current object
	};
	std::ostream& operator<<(std::ostream& os, MemberParliament member);  // insert a MemberParliament into a stream
	std::istream& operator>>(std::istream& in, MemberParliament& member);  // extract a MemberParliament from a stream

}

#endif