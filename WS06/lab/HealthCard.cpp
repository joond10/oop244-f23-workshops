#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "HealthCard.h"
using namespace std;
namespace sdds {
	bool HealthCard::validID(const char* name, long long number, const char vCode[], const char sNumber[]) const
	{
		bool valid = false;
		if (name != nullptr && strlen(name) > 0 && number > 999999999 && number < 9999999999 && strlen(vCode) == 2 && strlen(sNumber) == 9) {
			valid = true;
		}
		return valid;
	}
	void HealthCard::setEmpty() {
		m_name = nullptr;
		
	}
	void HealthCard::allocateAndCopy(const char* name) {
		delete[] m_name; 
		m_name = new char[strlen(name) + 1];
		strcpy(m_name, name);
	}
	void HealthCard::extractChar(istream& istr, char ch) const {

		if (istr.peek() == ch) {
			istr.ignore();
		}
		else {
			istr.ignore(1000, ch);
			istr.setstate(ios::failbit);
		}
	}
	ostream& HealthCard::printIDInfo(ostream& ostr) const {
		ostr << m_number << "-" << m_vCode << ", " << m_sNumber;

			return ostr;
	}
	void HealthCard::set(const char* name, long long number, const char vCode[], const char sNumber[]) {

		if (validID(name,number,vCode,sNumber)) {
			allocateAndCopy(name);
			m_number = number;
			strcpy(m_vCode, vCode);
			strcpy(m_sNumber, sNumber);
		}
		else {
			delete[] m_name;
			setEmpty();
		}	
	}
	HealthCard::HealthCard(const char* name, long long number, const char* vCode, const char* sNumber) {
		set(name, number, vCode, sNumber);
	}

	HealthCard::HealthCard(const HealthCard& hc) {
			set(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber);
	}
	HealthCard& HealthCard::operator=(const HealthCard& hc) {
		if (this != &hc) {
			set(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber);
		}
			return *this;
	}
	HealthCard::~HealthCard() {
		delete[] m_name;
	}

	HealthCard::operator bool() const {
		return (m_name != nullptr);
	}
	ostream& HealthCard::print(ostream& ostr, bool toFile)const {
		if (*this) { 
			if (toFile) {
				printIDInfo(ostr << m_name << ",");
				ostr << '\n';
			}
			else {
				ostr.width(50);
				ostr.setf(ios::left);
				ostr.fill('.');
				ostr << m_name;
				printIDInfo(ostr);
			}
		}

		return ostr;
	}
	istream& HealthCard::read(istream& istr) {
		char* name = new char[MaxNameLength + 1];
		long long number;
		char vCode[3];
		char sNumber[10];

		istr.get(name, MaxNameLength, ',');
		extractChar(istr, ',');
		istr >> number;
		extractChar(istr, '-');
		istr.get(vCode, 3, ',');
		extractChar(istr, ',');
		istr.get(sNumber, 10, '\n');
		if (!istr.fail()) { 
			set(name, number, vCode, sNumber);
		}
		istr.clear();
		istr.ignore(1000, '\n');
		return istr;
	}

	bool HealthCard::isValid() const {
	
		return validID(m_name,m_number,m_vCode,m_sNumber);
	}

	ostream& operator<<(ostream& ostr, const HealthCard& hc) {
		
		if (hc.isValid()){
			hc.print(ostr, false);
		} 
		else {
			ostr << "Invalid Card Number";
		}

			return ostr;
	}
	istream& operator>>(istream& istr, HealthCard& hc) {
		return hc.read(istr);
	}	

}
