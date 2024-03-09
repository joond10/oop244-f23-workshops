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
    //Overrides the pure virtual version of the interface (Upgrades from abstract class by building off it)
    void Line::getSpecs(istream& istr)  {
        LblShape::getSpecs(istr);
        istr >> m_length;
        istr.ignore(10000, '\n');
    }

    //Overrides the pure virtual version of the interface
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
