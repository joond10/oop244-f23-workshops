#ifndef SDDS_PACK_H
#define SDDS_PACK_H
#include <iostream>
#include "Container.h"
namespace sdds {
	class Pack : public Container {
		size_t m_unitSize;
	public:
	Pack(const char* content, size_t size, size_t unitSize = 330, size_t numUnits = 0);
	size_t operator+=(size_t addUnits);
	size_t operator-=(size_t subtractUnits);
	size_t unit()const;
	size_t noOfUnits()const;
	size_t size()const;
	Pack& clear(size_t size, size_t unitSize, const char* content);
	std::ostream& print(std::ostream& ostr) const;
	std::istream& read(std::istream& istr);
	};
	std::ostream& operator<<(std::ostream& ostr, const Pack& pack);
	std::istream& operator>>(std::istream& istr, Pack& pack);

}
#endif // !SDDS_PACK_H
