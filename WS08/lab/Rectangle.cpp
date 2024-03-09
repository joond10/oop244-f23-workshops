#include <iostream>
#include "Rectangle.h"
using namespace std;
namespace sdds {

	Rectangle::Rectangle() {
		m_width = 0;
		m_height = 0;
	}

	Rectangle::Rectangle(const char* cstr, size_t width, size_t height) : LblShape(cstr) {
		if (height < 3 || width < strlen(label() + 2)) {
			m_width = 0;
			m_height = 0;
		}
		else {
			m_width = width;
			m_height = height;

		}
	}
	//Overrides the pure virtual version of the interface (Upgrades from abstract class by building off it)
	void Rectangle::getSpecs(std::istream& istr){
		LblShape::getSpecs(istr);
		istr >> m_width;
		istr.ignore();
		istr >> m_height;
		istr.ignore(1000, '\n');
	}
	//Overrides the pure virtual version of the interface
	void Rectangle::draw(std::ostream& ostr) const{
		if (m_width != 0) {
			int i{}, j{};
			ostr << '+';
			for (i = 0; i < m_width - 2; i++) {
				ostr << '-';
			}
			ostr << '+' << endl;
			ostr << '|';
			ostr.width(m_width - 2);
			ostr.setf(ios::left);
			ostr << label();
			ostr << "|" << endl;
			for (i = 0; i < m_height - 3; i++) {
				ostr << '|'; 
				for (j = 0; j < m_width - 2; j++) {
					ostr << ' ';
				}
				ostr << '|' << endl;
			}
			ostr << '+';
			for (i = 0; i < m_width - 2; i++) {
				ostr << '-';
			}
			ostr << '+';
			
		}
	
	}

}
