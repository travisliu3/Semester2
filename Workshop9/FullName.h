/*
*****************************************************************************
							OOP244-Workshop-9
Full Name  : Travis Liu
e-mail     : tliu84@myseneca.ca
Student ID#: 156740201
Date       : 26 July, 2022
Section    : ZCC

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_FULLNAME_H__
#define SDDS_FULLNAME_H__

#include "Name.h"

namespace sdds {

    class FullName : public Name {
        char* m_value;
    public:
        FullName();  // Creates an empty FullName.
        FullName(const char* name, const char* lastName);  // Passess name to the constructor of the base class and dynamically keeps a copy of lastName in the m_value of FullName
        // Rule of three:
        ~FullName();
        FullName(FullName& name);
        void operator=(const FullName& name);

        operator const char* ()const;  // Returns the address of the m_value in the FullName.
        virtual operator bool()const;  // Returns true only if both FullName and Name are not empty.
        virtual std::ostream& display(std::ostream& ostr = std::cout)const;  // If the FullName is not empty it will insert the Name, one space and then the m_value of the FullName into the ostream reference without going to the new line.Then it will return the ostream reference.
        virtual std::istream& read(std::istream& istr = std::cin);  // Reads the Name and then dynamically reads a Cstring into the m_value of FullName from istream until it reaches the newline character.The newline character is removed from istream and the istream reference is returned.
    };

}

#endif