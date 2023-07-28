#include <iostream>
#include <cstring>
using namespace std;
#include "Utils.h"
namespace sdds {

    void error(unsigned int& order)
    {
        cout << "Invalid Selection, try again: ";
        cin.clear();
        cin.ignore(2000, '\n');
        cin >> order;
    }

    void publicationinput(istream& istr, Publication& p, int& libRef, char* title, char* shelfId, Date& date, int& membership) {

        if (p.conIO(istr))
        {
            cout << "Shelf No: ";
            istr >> shelfId;
            if (strlen(shelfId) != 4)
            {
                cout << "Title: Date: ";
                istr.setstate(ios::failbit);
            }
            else
            {
                istr.ignore(1000, '\n');
                cout << "Title: ";
                istr.get(title, 1000, '\n');
                cout << "Date: ";
                istr >> date;
                if (date)
                {
                    istr.setstate(ios::failbit);
                }
            }
        }
        else
        {
            istr >> libRef;
            istr >> shelfId;
            if (strlen(shelfId) != 4)
            {
                istr.setstate(ios::failbit);
            }
            istr.ignore();
            istr.get(title, 1000, '\t');
            istr >> membership;
            istr >> date;
            if (date)
            {
                istr.setstate(ios::failbit);
            }
        }
    }

}