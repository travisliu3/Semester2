#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

#include "Streamable.h"

namespace sdds {

    Streamable::~Streamable() {}

    ostream& operator<<(ostream& os, const Streamable& stream) {
        if (stream)
        {
            stream.write(os);
        }
        return os;
    }

    istream& operator>>(istream& istr, Streamable& stream) {
        stream.read(istr);
        return istr;
    }

}