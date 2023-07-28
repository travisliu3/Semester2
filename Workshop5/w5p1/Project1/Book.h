/*
*****************************************************************************
                        OOP244-Workshop-5, part-1
Full Name  : Travis Liu
e-mail     : tliu84@myseneca.ca
Student ID#: 156740201
Date       : 15 June, 2022
Section    : ZCC

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_BOOK_H_
#define SDDS_BOOK_H_
#include <iostream>
#include "Chapter.h"

namespace sdds {
    const int MAX_NUM_CHAPTERS = 10;
    const int MAX_BOOK_TITEL = 40;
    const int MAX_AUTHOR_NAME = 20;
    class Book
    {
        char m_title[MAX_BOOK_TITEL + 1];
        char m_author[MAX_AUTHOR_NAME + 1];
        int m_num_chapters;
        int m_num_pages;
        double m_price;
        Chapter m_chapters[MAX_NUM_CHAPTERS];

        void init_book();  // put the Book class to a safe empty state
        int add_chapter(Chapter* chapter);  // add a new chapter to the Chapter class object array.
    public:
        Book();  // Default constructor
        Book(const char* title_);  // one argument constructor
        Book(const char* title_, const char* author_, double price_);  // three argument constructor
        void operator++(int);  // increase the number of chapters by one
        std::ostream& display(std::ostream& = std::cout)const;  // display the chapter class info
        operator int();  // It will return the number of chapters of a book object.
        operator bool();  // It will return true if title and author, and num_chapters are non-empty and there is at least one chapter with number of pages greater than zero.
        operator double();  // It will return the book price.
        operator const char* ();  // It will return title of the book
        bool operator!=(Book);  // return true if any of the conditions mentioned for the bool operator overload are not true
        void operator+=(Chapter);  // allow adding a chapter to a book.
        void operator-=(double book_price);  // apply a dollar value discount to the book price
        void summary(); // Print a book summary
    };
    std::ostream& operator<<(std::ostream& os, Book& book);  // allows printing of a book to the output console.

}

#endif