#ifndef SDDS_SHAPE_H
#define SDDS_SHAPE_H
namespace sdds {
	class Shape { //interface
	public:
		virtual ~Shape() = default;
		virtual void draw(std::ostream& ostr) const = 0;
		virtual void getSpecs(std::istream& istr)  = 0;
	};
	std::ostream& operator<<(std::ostream& ostr, const Shape& shape);
	std::istream& operator>>(std::istream& istr, Shape& shape);
}
#endif // !SDDS_SHAPE_H

