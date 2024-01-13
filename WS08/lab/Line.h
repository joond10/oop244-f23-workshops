#ifndef SDDS_LINE_H
#define SDDS_LINE_H
#include "LblShape.h"
namespace sdds {
	class Line : public LblShape{
		size_t m_length;
	public:
		Line();
		Line(const char* string, size_t length);
		void draw(std::ostream& ostr) const;
		void getSpecs(std::istream& istr);

	};
}
#endif // !SDDS_LINE_H

