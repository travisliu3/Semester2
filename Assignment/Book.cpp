#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

#include "Book.h"
#include "Utils.h"

using namespace std;

namespace sdds {

    Book::Book() {
        authorname = nullptr;
    }

    Book::~Book() {
        delete[] authorname;
    }

    Book::Book(const Book& b): Publication(b) {
        if (b)
        {
            authorname = new char[strlen(b.getauthor()) + 1];
            strcpy(authorname, b.getauthor());
        }
        else
        {
            authorname = nullptr;
        }
    }

    void Book::operator=(Book b) {
        Publication::operator=(b);
        if (b)
        {
            delete[] authorname;
            authorname = new char[strlen(b.getauthor()) + 1];
            strcpy(authorname, b.getauthor());
        }
    }

    const char* Book::getauthor()const {
        return authorname;
    }

    // Returns the character "B".
    char Book::type()const {
        return 'B';
    }

    // writes author name.
    ostream& Book::write(ostream& os)const {
        Publication::write(os);
        if (Publication::conIO(os))
        {
            os << ' ';
            if (strlen(authorname) > SDDS_AUTHOR_WIDTH)
            {
                for (int i = 0; i < SDDS_AUTHOR_WIDTH && authorname[i] != '\0'; i++)
                {
                    os << authorname[i];
                }
            }
            else
            {
                os.setf(ios::left);
                os.width(SDDS_AUTHOR_WIDTH);
                os.fill(' ');
                os << authorname;
                os.unsetf(ios::left);
            }
            os << " |";
        }
        else
        {
            os << '\t' << authorname;
        }
        return os;
    }

    // Read the author name
    istream& Book::read(std::istream& istr) {
        char author[256 + 1];
        Publication::read(istr);
        delete[] authorname;
        if (Publication::conIO(istr))
        {
            istr.ignore();
            cout << "Author: ";
            istr.get(author, 256, '\n');
        }
        else
        {
            istr.ignore();
            istr.get(author, 256, '\n');
        }
        if (!istr.fail())
        {
            authorname = new char[strlen(author) + 1];
            strcpy(authorname, author);
        }
        return istr;
    }

    // set member ID and set the date to currentdate
    void Book::set(int member_id) {
        Publication::set(member_id);
        Publication::resetDate();
    }

    // return true if the author's name exists and is not empty and the base class's operator bool() has returned true
    Book::operator bool()const {
        return (authorname != nullptr && Publication::operator bool());
    }

}