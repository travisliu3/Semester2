/*
*****************************************************************************
							OOP244-Workshop-9
Full Name  : Travis Liu
e-mail     : tliu84@myseneca.ca
Student ID#: 156740201
Date       : 26 July, 2022
Section    : ZCC

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_NAME_H__
#define SDDS_NAME_H__

namespace sdds {

    class Name {
        char* m_value;
    public:
        Name();  // Creates an empty name
        Name(const char* name);  // Keeps a dynamic copy of the name in the Name object.
        // Rule of three:
        virtual ~Name();
        Name(const Name& name);
        void operator=(const Name& name);

        operator const char* ()const;  // Returns the address of the dynamic Cstring.
        virtual operator bool()const;  // Return true if name is not empty, otherwise, it returns false.
        virtual std::ostream& display(std::ostream& ostr = std::cout)const;  // Inserts the Cstring value into ostr without going to new line if the Name is valid and then returns the ostr;
        virtual std::istream& read(std::istream& istr = std::cin);  // Dynamically reads the Cstring from istr without any spaces(stops at space) and keeps the address in the m_value pointer.
	                                                                // If the read is successful it will ignore one character from istr.
	                                                                // returns istr at end.
    };

    std::ostream& operator<<(std::ostream& os, const Name& name);
    std::istream& operator>>(std::istream& is, Name& name);

}

#endif