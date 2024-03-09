#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H
#include "Shape.h"
namespace sdds {
	//An abstract class derived from that of a Shape
	//It implements getSpecs but does not implement draw, therefore it is an abstract class that cannot be instantiated
	class LblShape : public Shape {
		char* m_label = nullptr;
	protected:
		const char* label() const;
	public:
		~LblShape();
		//Overrides the pure virtual version from the interface
		void getSpecs(std::istream& istr);
		LblShape();
		LblShape(const char* label);
		//The copy constructor and assignment operator are deleted to prevent copying or assignment of instances of this class.
		LblShape(const LblShape&) = delete;              
		LblShape& operator=(const LblShape&) = delete;

	};
}
#endif // !SDDS_LBLSHAPE_H
