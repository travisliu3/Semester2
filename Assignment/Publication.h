#ifndef SDDS_PUBLICATION_H__
#define SDDS_PUBLICATION_H__

#include <iostream>
#include "Date.h"
#include "Streamable.h"
#include "Lib.h"

namespace sdds {

    class Publication : public Streamable {
        char* m_title;
        char m_shelfId[SDDS_SHELF_ID_LEN + 1];
        int m_membership;
        int m_libRef;
        Date m_date;
    public:
        Publication();
        virtual ~Publication();
        Publication(const Publication& p);
        void operator=(Publication p);
        const char* getshelf()const;
        int getmember()const;
        virtual void set(int member_id);  // Sets the membership attribute to either zero or a five-digit integer.
        void setRef(int value);  // Sets the **libRef** attribute value
        void resetDate();  // Sets the date to the current date of the system.
        virtual char type()const;  //Returns the character 'P' to identify this object as a "Publication object"
        bool onLoan()const;  // Returns true if the publication is checkout (membership is non-zero)
        Date checkoutDate()const;  //Returns the date attribute
        bool operator==(const char* title)const;  //Returns true if the argument title appears anywhere in the title of the 
        //publication. Otherwise, it returns false; (use strstr() function in <cstring>)
        operator const char* ()const;  //Returns the title attribute
        int getRef()const;  //Returns the libRef attirbute. 
        virtual std::ostream& write(std::ostream& os)const;
        virtual std::istream& read(std::istream& istr);
        bool conIO(std::ios& io)const;
        virtual operator bool()const;
    };

}
#endif