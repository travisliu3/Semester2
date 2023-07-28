// Workshop 10:
// Collection template
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
#ifndef SDDS_BOOK_H_
#define SDDS_BOOK_H_
#include "Write.h"
namespace sdds {
    class Book : public ReadWrite {
        int m_upc;
        char m_title[41];
        char m_author[41];
        double m_price;
    public:
        Book();
        Book(int upc, const char* title, const char* author, double price);
        void set(int upc, const char* title, const char* author, double price);
        std::ostream& display(std::ostream& os)const;
        bool operator==(int upc)const;
        bool operator==(const char* title)const;
    };
    std::ostream& operator<<(std::ostream& os, const Book& book);
}
#endif // !SDDS_BOOK_H_