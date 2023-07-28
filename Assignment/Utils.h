#ifndef SDDS_UTILS_H__
#define SDDS_UTILS_H__
#include <iostream>
#include "Publication.h"
#include "Date.h"

namespace sdds {

    class Publication;
    class Date;

    void error(unsigned int& order);
    void publicationinput(std::istream& istr, Publication& p, int& libRef, char* title, char* shelfId, Date& date, int& membership);

}
#endif // !