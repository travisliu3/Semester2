/*
*****************************************************************************
                        OOP244-Workshop-6, part-1
Full Name  : Travis Liu
e-mail     : tliu84@myseneca.ca
Student ID#: 156740201
Date       : 23 June, 2022
Section    : ZCC

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_
#include <iostream>
namespace sdds {
    class Numbers {
        double* m_numbers;
        char* m_filename;
        bool m_isOriginal;
        int m_numCount;
        bool isEmpty()const;
        void setEmpty();
        void setFilename(const char* filename);
        void sort();
    public:
        Numbers();
        Numbers(const char* filename);
        Numbers(const Numbers& num);
        Numbers& operator=(const Numbers& num);
        double average()const;
        double max()const;
        double min()const;
        int numberCount()const;
        bool load();
        void save();
        Numbers& operator+=(double num);
        std::ostream& display(std::ostream& ostr) const;
        ~Numbers();
        friend void test3();
        friend std::istream& operator>>(std::istream& istr, Numbers& N);
    };
    std::ostream& operator<<(std::ostream& os, const Numbers& N);
    std::istream& operator>>(std::istream& istr, Numbers& N);
}
#endif // !SDDS_NUMBERS_H_