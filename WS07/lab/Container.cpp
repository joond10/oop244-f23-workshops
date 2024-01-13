#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Container.h"
using namespace std;
namespace sdds {

	Container& Container::setEmpty() {
		m_content = nullptr;
		m_capacity = 0;
		return *this;
	}
	size_t Container::capacity() const {
	
		return m_capacity;
	}
	size_t Container::volume() const {
	
		return m_volume;
	}
	Container::Container(const char* content, size_t capacity, size_t volume){
		if (content == nullptr || volume > capacity) {	
			setEmpty();
		}
		else {
			m_capacity = capacity;
			m_volume = volume;
			delete[] m_content;
			m_content = new char[50 + 1];
			strncpy(m_content, content, 50);
			m_content[50] = '\0';

		}
	}
	Container::~Container(){
		delete[] m_content;
	}
	size_t Container::operator+=(size_t addValue) {
	
		if ((m_volume + addValue) <= m_capacity) {
			m_volume += addValue;
		}
		else {
			addValue = (m_capacity - m_volume);
			m_volume = m_capacity;
		}
		return addValue;
	}
	size_t Container::operator-=(size_t subtractValue) {
	
		if (m_volume >= subtractValue) {
			m_volume -= subtractValue;
		}
		else {
			subtractValue = m_volume;
			m_volume = 0;
		}
		return subtractValue;
	}
	Container::operator bool() const {
		return (m_content != nullptr);
	}
	Container& Container::clear(size_t capacity, const char* content)
	{
		if (capacity > 0 && content != nullptr && strlen(content) > 0) {
			m_capacity = capacity;
			delete[] m_content;
			m_content = new char[50 + 1];
			strncpy(m_content, content, 50);
			m_content[50] = '\0';
		}
		return *this;
	}
	std::ostream& Container::print(std::ostream& ostr) const {
		if (*this) {
			ostr << m_content << ": " << "(" << m_volume << "cc/" << m_capacity << ")";
		}
		else {
			ostr << "****: (**cc/***)";
		}
		return ostr;
	}
	std::istream& Container::read(std::istream& istr){ //Implement Utils
		bool done = false;
		size_t value;

		if (*this) {
			print(cout << "Add to ") << endl;
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

				if (value < 1 || value > 220000) {
					cout << "Value out of range[1 <= val <= 999]: ";
				}
			} while (value < 1 || value > 220000);
			cout << "Added " << (*this += value) << " CCs" << endl;
		}
		else {
			cout << "Broken Container, adding aborted! Press <ENTER> to continue....";
			istr.ignore(1000, '\n');
		}
		return istr;
	}
	std::ostream& operator<<(std::ostream& ostr, const Container& contain){ 
		return contain.print(ostr);
	}
	std::istream& operator>>(std::istream& istr, Container& contain){
		return contain.read(istr);
	}
}