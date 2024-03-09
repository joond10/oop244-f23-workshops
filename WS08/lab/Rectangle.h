#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H
#include "LblShape.h"
namespace sdds {
	//Another concrete class derived of LblShape
	//It fully implements the interface meaning it can be instatiated
	class Rectangle : public LblShape {
		size_t m_width;
		size_t m_height;
	public:
		Rectangle();
		Rectangle(const char* label, size_t width, size_t height);
		void draw(std::ostream& ostr) const;
		void getSpecs(std::istream& istr);
	};
}
#endif // !SDDS_RECTANGLE_H

