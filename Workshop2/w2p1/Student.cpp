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
#include <iostream>
#include <string.h>
#include "File.h"
#include "Student.h"

using namespace std;

namespace sdds {
    // student info structure
    struct Student {
        char* m_name;
        int m_studentNumber;
        char m_grade;
    };

    int noOfStudents;
    Student* students = nullptr;

    // This overload of the load function returns a bool and receives a Student reference 
    // and read from the file to initialize Student reference with student data.
    bool load(struct Student &student) {
        char studentname[128];
        if (read(studentname))
        {
            student.m_name = new char[strlen(studentname) + 1];
            strcpy(student.m_name, studentname);
        }
        else
            return false;
        if (read(student.m_studentNumber))
        {
            if (read(student.m_grade))
            {
                return true;
            }
            else
                return false;
        }
        else
            return false;
    }

    // This overload of the load function loads all the student records into
    // the Student array and returns a bool for successand has no arguments.
    bool load(const char* filename) {
        openFile(filename);
        noOfStudents = noOfRecords();
        students = new Student[noOfStudents];
        int i = 0;
        for ( i = 0; i < noOfStudents; i++)
        {
            if (!load(students[i])) 
            {
                cout << "Error: Load unsuccessful" << endl;
                closeFile();
                return false;
            }
        }
        if (noOfStudents != i)
        {
            cout << "Error: incorrect number of records read; the data is possibly corrupted." << endl;
            closeFile(); 
            return false;
        }
        else
            closeFile();
            return true;
    }

    // First sort the array of Studentsand then display them one by one with a row number.
    void display() {
        sort();
        for (int i = 0; i < noOfStudents; i++)
        {
            cout << i + 1 << ": ";
            display(students[i]);
        }
    }

    // This overload of display function receives a constant student reference and prints it.
    void display(const struct Student& student) {
        cout << student.m_name << ", " << student.m_studentNumber << ": " << student.m_grade << endl;
    }

    // This function sorts the dynamic array of students based on the Grade of the students.
    void sort() {
        struct tempStudent {
            char* studentname;
            int studentNumber;
            char studentgrade;
        }student;
        for (int i = 0; i < noOfStudents - 1; i++)
        {
            for (int j = 0; j < noOfStudents - 1 - i; j++)
            {
                if (students[j].m_grade > students[j + 1].m_grade)
                {
                    student.studentgrade = students[j].m_grade;
                    students[j].m_grade = students[j + 1].m_grade;
                    students[j + 1].m_grade = student.studentgrade;
                    student.studentname = students[j].m_name;
                    students[j].m_name = students[j + 1].m_name;
                    students[j + 1].m_name = student.studentname;
                    student.studentNumber = students[j].m_studentNumber;
                    students[j].m_studentNumber = students[j + 1].m_studentNumber;
                    students[j + 1].m_studentNumber = student.studentNumber;
                }
            }
        }
    }

    // In a loop go through all the elements of the student array and deallocate the dynamic
    // name of each student. Then deallocate the whole student array.
    void deallocateMemory() {
        for (int i = 0; i < noOfStudents; i++)
        {
            delete[] students[i].m_name;
        }
        delete[] students;
        students = nullptr;
    }

}