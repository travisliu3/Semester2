#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

#include "Publication.h"
#include "Date.h"
#include "Utils.h"

namespace sdds {

    Publication::~Publication() {
        delete[] m_title;
    }

    Publication::Publication(const Publication& p) {
        if (p)
        {
            m_title = new char[strlen((const char*)p) + 1];
            strcpy(m_title, (const char*)p);
            strcpy(m_shelfId, p.getshelf());
            m_membership = p.getmember();
            m_libRef = p.getRef();
            m_date = p.checkoutDate();
        }
        else
        {
            m_title = nullptr;
            for (int i = 0; i < 5; i++)
            {
                m_shelfId[i] = '\0';
            }
            m_membership = 0;
            m_libRef = -1;
            resetDate();
        }
    }

    void Publication::operator=(Publication p) {
        if (p)
        {
            delete[] m_title;
            m_title = new char[strlen((const char*)p) + 1];
            strcpy(m_title, (const char*)p);
            strcpy(m_shelfId, p.getshelf());
            m_membership = p.getmember();
            m_libRef = p.getRef();
            m_date = p.checkoutDate();
        }
    }

    const char* Publication::getshelf()const {
        return m_shelfId;
    }

    int Publication::getmember()const {
        return m_membership;
    }

    Publication::Publication() {
        m_title = nullptr;
        for (int i = 0; i < 5; i++)
        {
            m_shelfId[i] = '\0';
        }
        m_membership = 0;
        m_libRef = -1;
        resetDate();
    }

    // Sets the membership attribute to either zero or a five-digit integer.
    void Publication::set(int member_id) {
        m_membership = member_id;
    }

    // Sets the **libRef** attribute value
    void Publication::setRef(int value) {
        m_libRef = value;
    }

    // Sets the date to the current date of the system.
    void Publication::resetDate() {
        m_date.currentdate();
    }

    //Returns the character 'P' to identify this object as a "Publication object"
    char Publication::type()const {
        return 'P';
    }

    //Returns true is the publication is checkout (membership is non-zero)
    bool Publication::onLoan()const {
        return (m_membership != 0);
    }

    //Returns the date attribute
    Date Publication::checkoutDate()const {
        return m_date;
    }

    //Returns true if the argument title appears anywhere in the title of the 
    //publication. Otherwise, it returns false; (use strstr() function in <cstring>)
    bool Publication::operator==(const char* title)const {
        return strstr(m_title, title);
    }

    //Returns the title attribute
    Publication::operator const char* ()const {
        return m_title;
    }

    //Returns the libRef attirbute.
    int Publication::getRef()const {
        return m_libRef;
    }

    bool Publication::conIO(ios& io)const {
        return (&io == &cin || &io == &cout);
    }

    ostream& Publication::write(ostream& os) const {
        if (conIO(os))
        {
            os << "| " << m_shelfId << " | ";
            if (strlen(m_title) > SDDS_TITLE_WIDTH)
            {
                for (int i = 0; i < SDDS_TITLE_WIDTH && m_title[i] != '\0'; i++)
                {
                    os << m_title[i];
                }
            }
            else
            {
                os.setf(ios::left);
                os.width(SDDS_TITLE_WIDTH);
                os.fill('.');
                os << m_title;
            }
            os << " | ";
            if (m_membership)
            {
                os << m_membership;
            }
            else
            {
                os << " N/A ";
            }
            os.unsetf(ios::left);
            os << " | " << m_date << " |";
        }
        else
        {
            os << type() << "\t" << m_libRef << "\t" << m_shelfId << "\t" << m_title << "\t" << m_membership << "\t" << m_date;
        }
        return os;
    }

    istream& Publication::read(istream& istr) {
        istr.setstate(ios::goodbit);
        char title[256 + 1] = { '\0' };
        char shelfId[SDDS_SHELF_ID_LEN + 1] = { '\0' };
        int membership = 0;
        int libRef = -1;
        Date date;
        m_title = nullptr;
        for (int i = 0; i < 5; i++)
        {
            m_shelfId[i] = '\0';
        }
        m_membership = 0;
        m_libRef = -1;
        publicationinput(istr, *this, libRef, title, shelfId, date, membership);
        if (!istr.fail())
        {
            m_libRef = libRef;
            m_title = new char[strlen(title) + 1];
            strcpy(m_title, title);
            strcpy(m_shelfId, shelfId);
            m_date = date;
            m_membership = membership;
        }
        return istr;
    }

    Publication::operator bool() const {
        return (m_title != nullptr && m_shelfId[0] != '\0');
    }

}