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
#ifndef SDDS_CHAPTER_H_
#define SDDS_CHAPTER_H_
#include <iostream>
namespace sdds {
    const int MAX_CHAPTER_TITLE = 20;
    class Chapter
    {
        char m_title[MAX_CHAPTER_TITLE + 1];
        int m_num_pages;
        int m_num_words;
        unsigned int m_chapter_number;
        void init_chapter();
    public:
        Chapter();  // Default constructor
        Chapter(const char* title_);  // one argument constructor
        Chapter(const char* title_, int chapter_num, int n_pages, int n_words);  // three argument constructor
        std::ostream& display(std::ostream&)const;  // display the chapter class info
        operator int();  // It will return the number of the pages in the Chapter object.
        operator double();  // It will return the number of words per chapter
        operator const char* ();  // It will return the title of a chapter object.
        const Chapter& operator=(Chapter chapter);  //  allows setting a chapter to another chapter object.
        void operator++();  // It will increase the number of pages for a chapter object by one
        void operator--();  // It will decrease the number of pages for a chapter object by one
        bool getter();  // checks if m_num_pages is greater than 0.
    };
    std::ostream& operator<<(std::ostream& os, const Chapter& chapter);  // allows printing of a chapter to the output console.
}
#endif