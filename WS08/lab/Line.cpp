#include <iostream>
#include "Line.h"
using namespace std;
namespace sdds {

    Line::Line() {
        m_length = 0;
    }

    Line::Line(const char* cstr, size_t length) : LblShape(cstr) {
        m_length = length;
    }

    void Line::getSpecs(istream& istr)  {
        LblShape::getSpecs(istr);
        istr >> m_length;
        istr.ignore(10000, '\n');
    }

    void Line::draw(ostream& ostr) const {
        int i{};
        if (m_length > 0 && label() != nullptr) {
            ostr << label() << endl;
            for (i = 0; i < m_length; i++) {
                ostr << '=';
            }
        }    
    }
}
