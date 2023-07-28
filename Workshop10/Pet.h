// Workshop 10:
// Pet.h
// 2022-02-25
// Version: 1.0 
// Author: Nathan Misener
// Revised by: 
/////////////////////////////////////////////
/*
*****************************************************************************
                            OOP244-Workshop-10
Full Name  : Travis Liu
e-mail     : tliu84@myseneca.ca
Student ID#: 156740201
Date       : 2 August, 2022
Section    : ZCC

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include <iostream>
#ifndef SDDS_PET_H_
#define SDDS_PET_H_
#include "Write.h"
namespace sdds {
    class Pet : public ReadWrite {
        char m_name[41];
        char m_type[41];
        int m_age;
    public:
        Pet();
        Pet(const char* name, const char* type, int age);
        void set(const char* name, const char* type, int age);
        std::ostream& display(std::ostream& os)const;
        bool operator==(const char* type)const;
        bool operator==(const int age)const;
    };
    std::ostream& operator<<(std::ostream& os, const Pet& Pet);
}
#endif // !SDDS_PET_H_
