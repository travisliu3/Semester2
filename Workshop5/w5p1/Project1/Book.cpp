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
#include "Book.h"

using namespace std;
namespace sdds {

	// put the Book class to a safe empty state
	void Book::init_book() {
		m_title[0] = '\0';
		m_author[0] = '\0';
		m_num_chapters = 0;
		m_num_pages = 0;
	}

	// Default constructor
	Book::Book() {
		init_book();
	}

	// one argument constructor
	Book::Book(const char* title_) {
		init_book();
		strcpy(m_title, title_);
	}

	// three argument constructor
	Book::Book(const char* title_, const char* author_, double price_) {
		init_book();
		strcpy(m_title, title_);
		strcpy(m_author, author_);
		m_price = price_;
	}

	// display the chapter class info
	ostream& Book::display(ostream& os)const {
		os << "Title:'" << this->m_title << "'" << endl;
		os << "Author: '" << this->m_author << "'" << endl;
		for (int i = 0; i < this->m_num_chapters; i++)
		{
			os << this->m_chapters[i];
		}
		return os;
	}

	// allows printing of a book to the output console.
	std::ostream& operator<<(std::ostream& os, Book& book) {
		return book.display(os);
	}

	// increase the number of chapters by one
	void Book::operator++(int) {
		(this->m_num_chapters)++;
	}

	// It will return the number of chapters of a book object.
	Book::operator int() {
		return m_num_chapters;
	}

	// It will return true if title and author, and num_chapters are non-empty and there is at least one chapter with number of pages greater than zero.
	Book::operator bool() {
		if (m_title[0] != '\0' && m_author[0] != '\0' && m_num_chapters != 0)
		{
			for (int i = 0; i < MAX_NUM_CHAPTERS; i++)
			{
				if (m_chapters[i].getter())
				{
					return true;
				}
			}
		}
		return false;
	}

	// return true if any of the conditions mentioned for the bool operator overload are not true
	bool Book::operator!=(Book book) {
		if ((bool)book)
		{
			return false;
		}
		return true;
	}

	// It will return the book price.
	Book::operator double() {
		return m_price;
	}

	// It will return title of the book
	Book::operator const char* () {
		return m_title;
	}

	// add a new chapter to the Chapter class object array.
	int Book::add_chapter(Chapter* chapter) {
		this->m_chapters[++this->m_num_chapters - 1] = *chapter;
		return this->m_num_chapters;
	}
	
	// allow adding a chapter to a book.
	void Book::operator+=(Chapter chapter) {
		this->m_num_chapters = add_chapter(&chapter);
		this->m_num_pages += (int)chapter;
	}

	// apply a dollar value discount to the book price
	void Book::operator-=(double price) {
		this->m_price = this->m_price - price;
	}

	// Print a book summary
	void Book::summary() {
		cout.setf(ios::left);
		cout << "| ";
		cout.width(MAX_BOOK_TITEL);
		cout << m_title << " | ";
		cout.width(MAX_AUTHOR_NAME);
		cout << m_author << " | ";
		cout.width(3);
		cout << m_num_chapters << "  ";
		cout.width(4);
		cout << m_num_pages << " | ";
		cout.width(6);
		cout << m_price << " |" << endl;
	}

}