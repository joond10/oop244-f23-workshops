#ifndef SDDS_SHAPE_H
#define SDDS_SHAPE_H
namespace sdds {
	class Shape { //Shape acts as an interface or a base abstract class for anything derived of a shape
	public:
		//Pure virtual functions 
		//No data members and no implementation
		virtual ~Shape() = default;
		virtual void draw(std::ostream& ostr) const = 0;
		virtual void getSpecs(std::istream& istr)  = 0;
	};
	//Helper functions to be implemented so that is OF a shape can use these
	std::ostream& operator<<(std::ostream& ostr, const Shape& shape);
	std::istream& operator>>(std::istream& istr, Shape& shape);
}
#endif // !SDDS_SHAPE_H

