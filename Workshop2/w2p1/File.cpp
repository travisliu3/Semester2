/*
*****************************************************************************
                        OOP244-Workshop-2, part-1
Full Name  : Travis Liu
e-mail     : tliu84@myseneca.ca
Student ID#: 156740201
Date       : 25 May, 2022
Section    : ZCC

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds {
    FILE* fptr;

    // Opens the data file for reading
    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }

    // Returns an integer that is the number of records in the file
    int noOfRecords() {
        int noOfRecs = 0;
        char ch;
        while (fscanf(fptr, "%c", &ch) == 1) {
            noOfRecs += (ch == '\n');
        }
        rewind(fptr);
        return noOfRecs;
    }

    // Closes the data file
    void closeFile() {
        if (fptr) fclose(fptr);
    }

    // read function for the student name
    bool read(char* m_name) {
        if (fscanf(fptr, "%[^,],", m_name))
        {
            return true;
        }
        return false;
    }

    // read function for the student number
    bool read(int &m_studentNumber) {
        if (fscanf(fptr, "%d,", &m_studentNumber))
        {
            return true;
        }
        return false;
    }

    // read function for the student grade
    bool read(char &m_grade) {
        if (fscanf(fptr, "%c\n", &m_grade))
        {
            return true;
        }
        return false;
    }

}