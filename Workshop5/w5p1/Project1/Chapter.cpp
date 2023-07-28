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
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "Chapter.h"

using namespace std;

namespace sdds {
	void Chapter::init_chapter() {
		m_title[0] = '\0';
		m_num_pages = 0;
		m_num_words = 0;
		m_chapter_number = 0;
	}

	// Default constructor
	Chapter::Chapter() {
		init_chapter();
	}

	// one argument constructor
	Chapter::Chapter(const char* title_) {
		init_chapter();
		strcpy(m_title, title_);
	}

	// three argument constructor
	Chapter::Chapter(const char* title_, int chapter_num, int n_pages, int n_words) {
		strcpy(m_title, title_);
		m_chapter_number = chapter_num;
		m_num_pages = n_pages;
		m_num_words = n_words;
	}

	// display the chapter class info
	ostream& Chapter::display(std::ostream& os)const
	{
		cout.setf(std::ios::left);
		os << "| Chapter ";
		os.width(2);
		os << m_chapter_number << " | ";
		os.width(MAX_CHAPTER_TITLE);
		os << m_title << " |" << endl;
		return os;
	}

	// allow printing of a chapter to the output console
	std::ostream& operator<<(std::ostream& os, const Chapter& chapter) {
		return chapter.display(os);
	}

	// It will return the number of the pages in the Chapter object.
	Chapter::operator int() {
		return m_num_pages;
	}

	// It will return the number of words per chapter
	Chapter::operator double() {
		return (double)m_num_words / m_num_pages;
	}

	// It will return the title of a chapter object.
	Chapter::operator const char* () {
		return m_title;
	}

	//  allows setting a chapter to another chapter object.
	const Chapter& Chapter::operator=(Chapter chapter) {
		this->m_chapter_number = chapter.m_chapter_number;
		this->m_num_pages = (int)chapter;
		this->m_num_words = chapter.m_num_words;
		strcpy(this->m_title, (const char*)chapter);
		return *this;
	}

	// It will increase the number of pages for a chapter object by one
	void Chapter::operator++() {
		m_num_pages++;
	}

	// It will decrease the number of pages for a chapter object by one
	void Chapter::operator--() {
		m_num_pages--;
	}

	// checks if m_num_pages is greater than 0.
	bool Chapter::getter() {
		if (m_num_pages > 0)
		{
			return true;
		}
		return false;
	}

}