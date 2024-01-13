#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Graduate.h"
using namespace std;
namespace sdds {

	Graduate::Graduate() {
		m_supervisor = nullptr;
		m_thesis = nullptr;
	}

	Graduate::Graduate(const char* name = nullptr, size_t age = 0, const char* thesis = nullptr, const char* supervisor = nullptr)
		: m_thesis(nullptr), m_supervisor(nullptr), Student(name, age) {

		if (supervisor != nullptr) {
			delete[] m_supervisor;
			m_supervisor = new char[strlen(supervisor) + 1];
			strcpy(m_supervisor, supervisor);
		}
		if (thesis != nullptr) {
			delete[] m_thesis;
			m_thesis = new char[strlen(thesis) + 1];
			strcpy(m_thesis, thesis);
		}
	}

	Graduate::Graduate(const Graduate& anotherGraduate) 
		: m_thesis(nullptr), m_supervisor(nullptr), Student(anotherGraduate) {
		if (this != &anotherGraduate);
		*this = anotherGraduate;
	}

	Graduate& Graduate::operator=(const Graduate& anotherGraduate)  {
		Student::operator=(anotherGraduate);
		if (anotherGraduate.m_supervisor != nullptr) {
			delete[] m_supervisor;
			m_supervisor = new char[strlen(anotherGraduate.m_supervisor) + 1];
			strcpy(m_supervisor, anotherGraduate.m_supervisor);
		}
		if (anotherGraduate.m_thesis != nullptr) {
			delete[] m_thesis;
			m_thesis = new char[strlen(anotherGraduate.m_thesis) + 1];
			strcpy(m_thesis, anotherGraduate.m_thesis);
		}
		return *this;
	}

	void Graduate::display() {
		Student::display();
		cout << "Thesis title: " << m_thesis << endl;
		cout << "Supervisor: " << m_supervisor << endl;
		cout << "---------------------------------------------" << endl;
	}
}
