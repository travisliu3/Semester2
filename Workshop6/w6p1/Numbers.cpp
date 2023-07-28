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
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include "Numbers.h"
#include "Numbers.h"  // intentional
using namespace std;
namespace sdds {


    Numbers::Numbers() {
        setEmpty();
        m_isOriginal = false;
    }

    Numbers::Numbers(const char* filename) {
        setEmpty();
        m_isOriginal = true;
        setFilename(filename);
        m_numCount = numberCount();
        if (m_numCount == 0 || !load()) {
            delete[] m_numbers;
            delete[] m_filename;
            setEmpty();
            m_isOriginal = false;
        }
        else {
            sort();
        }
    }

    Numbers::Numbers(const Numbers& num) {
        setEmpty();
        m_isOriginal = false;
        *this = num;
    }

    Numbers& Numbers::operator=(const Numbers& num) {
        delete[] m_numbers;
        m_numbers = nullptr;
        m_numbers = new double[num.m_numCount];
        delete[] m_filename;
        m_filename = nullptr;
        m_filename = new char[strlen(num.m_filename) + 1];
        strcpy(m_filename, num.m_filename);
        m_numCount = num.m_numCount;
        for (int i = 0; i < num.m_numCount; i++)
        {
            m_numbers[i] = num.m_numbers[i];

        }
        return *this;
    }

    Numbers::~Numbers() {
        save();
        delete[] m_numbers;
        delete[] m_filename;
    }

    bool Numbers::isEmpty() const {
        return m_numbers == nullptr;
    }

    void Numbers::setEmpty() {
        m_numbers = nullptr;
        m_filename = nullptr;
        m_numCount = 0;
    }
    void Numbers::setFilename(const char* filename) {
        delete[] m_filename;
        m_filename = new char[strlen(filename) + 1];
        strcpy(m_filename, filename);
    }
    void Numbers::sort() {
        int i, j;
        double temp;
        for (i = m_numCount - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (m_numbers[j] > m_numbers[j + 1]) {
                    temp = m_numbers[j];
                    m_numbers[j] = m_numbers[j + 1];
                    m_numbers[j + 1] = temp;
                }
            }
        }
    }

    double Numbers::average() const {
        double aver = 0.0;
        if (!isEmpty()) {
            for (int i = 0; i < m_numCount; i++)
                aver += m_numbers[i];
            aver = aver / m_numCount;
        }
        return aver;
    }
    double Numbers::min() const {
        double minVal = 0.0;
        if (!isEmpty()) {
            minVal = m_numbers[0];
            for (int i = 1; i < m_numCount; i++)
                if (minVal > m_numbers[i]) minVal = m_numbers[i];
        }
        return minVal;
    }
    double Numbers::max() const {
        double maxVal = 0.0;
        if (!isEmpty()) {
            maxVal = m_numbers[0];
            for (int i = 1; i < m_numCount; i++)
                if (maxVal < m_numbers[i]) maxVal = m_numbers[i];
        }
        return maxVal;
    }

    int Numbers::numberCount()const {
        std::ifstream f(m_filename);
        int numCount = -1;
        char newline;
        while (f)
        {
            f.get(newline);
            if (newline == '\n')
            {
                numCount++;
            }
        }
        if (!numCount)
        {
            return 0;
        }
        return numCount;
    }

    bool Numbers::load() {
        if (m_numCount > 0)
        {
            m_numbers = new double[m_numCount];
            std::ifstream f;
            f.open(m_filename);
            for (int i = 0; f; i++)
            {
                f >> m_numbers[i];
            }
            return true;
        }
        return false;
    }

    void Numbers::save() {
        if (m_isOriginal && !isEmpty())
        {
            std::ofstream of(m_filename);
            if (of.is_open())
            {
                for (int i = 0; i < m_numCount; i++)
                {
                    of << m_numbers[i] << std::endl;
                }
            }
        }
    }

    Numbers& Numbers::operator+=(double num) {
        double* temp = nullptr;
        temp = new double[m_numCount + 1];
        for (int i = 0; i < m_numCount; i++)
        {
            temp[i] = m_numbers[i];
        }
        m_numCount++;
        delete[] m_numbers;
        m_numbers = nullptr;
        m_numbers = temp;
        m_numbers[m_numCount - 1] = num;
        sort();
        return *this;
    }

    ostream& Numbers::display(ostream& ostr) const {
        if (isEmpty())
        {
            ostr << "Empty list";
            return ostr;
        }
        ostr << "=========================" << endl;
        if (m_isOriginal)
        {
            ostr << m_filename << endl;
        }
        else
        {
            ostr << "*** COPY ***" << endl;
        }
        for (int i = 0; i < m_numCount; i++)
        {
            ostr << m_numbers[i];
            if (i != m_numCount - 1)
            {
                ostr << ", ";
            }
            else
            {
                ostr << endl;
            }
        }
        ostr << "-------------------------" << endl;
        ostr << "Total of " << m_numCount << " number(s)" << endl;
        ostr << "Largest number:  " << max() << endl;
        ostr << "Smallest number: " << min() << endl;
        ostr << "Average :        " << average() << endl;
        ostr << "=========================";
        return ostr;
    }

    ostream& operator<<(ostream& os, const Numbers& N) {
        return N.display(os);
    }

    istream& operator>>(istream& istr, Numbers& N) {
        double temp;
        istr >> temp;
        N += temp;
        return istr;
    }

}