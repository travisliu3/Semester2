#ifndef SDDS_BOOK_H__
#define SDDS_BOOK_H__

#include <iostream>
#include "Publication.h"

using namespace sdds;

namespace sdds {

    class Book : public Publication {
        char* authorname;
    public:
        Book();
        ~Book();
        Book(const Book& b);
        void operator=(Book b);
        const char* getauthor()const;
        char type()const;  // Returns the character "B".
        std::ostream& write(std::ostream& os)const;  // writes author name.
        std::istream& read(std::istream& istr);  // Read the author name
        void set(int member_id);  // set member ID and set the date to currentdate
        operator bool()const;  // return true if the author's name exists and is not empty and the base class's operator bool() has returned true
    };

}
#endif