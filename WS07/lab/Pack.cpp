#include "Pack.h" 
using namespace std;
namespace sdds {
	Pack::Pack(const char* content, size_t size, size_t unitSize, size_t numUnits) //Content is passed to base class Container, other parameters used to set Container
		: Container (content, size* unitSize, numUnits* unitSize), m_unitSize(unitSize) {	//Initalizer list intializes m_unitSize

		if (unitSize > 0) {
			m_unitSize = unitSize;
		}
		else {
			Container::setEmpty();
		}
	
	}

	size_t Pack::operator+=(size_t addUnits){
		
		return (Container::operator+=(addUnits * m_unitSize) / m_unitSize);
	}

	size_t Pack::operator-=(size_t subtractUnits){
	
		return (Container::operator-=(subtractUnits * m_unitSize) / m_unitSize);
	}

	size_t Pack::unit()const{
	
		return m_unitSize;
	}

	size_t Pack::noOfUnits()const{
	
		return Container::volume() / m_unitSize;
	}

	size_t Pack::size()const{
	
		return Container::capacity() / m_unitSize;
	}

	Pack& Pack::clear(size_t size, size_t unitSize, const char* content){
		if (unitSize > 0) {
			Container::clear(size * unitSize, content);
			m_unitSize = unitSize;
		}
		return *this;
	}

	std::ostream& Pack::print(std::ostream& ostr) const{
		Container::print(ostr);
		if (*this) {
			ostr << ", " << noOfUnits() << " in a pack of " << size();
		}
		return ostr;
	}

	std::istream& Pack::read(std::istream& istr) {	//Implement Untils
		bool done = false;
		size_t value;

		if (*this) {
			if (noOfUnits() < size()) {
				print(cout) << endl;
				cout << "> ";
				do {
					do {
						done = false;
						istr >> value;
						if (istr) {
							if (istr.get() != '\n') {
								cout << "Invalid Integer, retry: ";
							}
							else {
								done = true;
							}
						}
						else {
							istr.clear();
							cout << "Invalid Integer, retry: ";
						}
						if (!done) istr.ignore(10000, '\n');
					} while (!done);
					if (value < 1 || value > (size() - noOfUnits())) {
						cout << "Value out of range[1<=val<=" << (size() - noOfUnits()) << "]: ";
					}
				} while (value < 1 || value > (size() - noOfUnits()));
				cout << "Added " << (*this += value)<< endl;
			}
			else {
				cout << "Pack is full!, press <ENTER> to continue...";
				istr.ignore(1000, '\n');
			}
		}
		else {
			cout << "Broken Container, adding aborted! Press <ENTER> to continue....";
			istr.ignore(1000, '\n');
		}
		return istr;
	}
	std::ostream& operator<<(std::ostream& ostr, const Pack& pack) {

		return pack.print(ostr);
	}
	std::istream& operator>>(std::istream& istr, Pack& pack){

		return pack.read(istr);
	}
}