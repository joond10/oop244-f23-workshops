#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H
#include "Shape.h"
namespace sdds {
	class LblShape : public Shape {
		char* m_label = nullptr;
	protected:
		const char* label() const;
	public:
		~LblShape();
		void getSpecs(std::istream& istr);
		LblShape();
		LblShape(const char* label);
		LblShape(const LblShape&) = delete;              
		LblShape& operator=(const LblShape&) = delete;

	};
}
#endif // !SDDS_LBLSHAPE_H
