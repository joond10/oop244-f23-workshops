#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Student.h"
using namespace std;
namespace sdds {

	Student::Student() {
		m_name = nullptr;
		m_age = 0;
	}

	Student::Student(const char* name, size_t age) {
		delete[] m_name;
		m_name = new char[strlen(name) + 1];
		strcpy(m_name, name);
		m_age = age;
	}

	Student& Student::operator=(const Student& anotherStudent) {
		if (this != &anotherStudent) {
			m_age = anotherStudent.m_age;
			delete[] m_name;
			if (anotherStudent.m_name != nullptr) {
				m_name = new char[strlen(anotherStudent.m_name) + 1];
				strcpy(m_name, anotherStudent.m_name);
			}
			else {
				m_name = nullptr;
			}
		}
		return *this;
	}

	Student::Student(const Student& anotherStudent) :m_name(nullptr) {
		*this = anotherStudent;
	}

	Student::~Student() {
		delete[] m_name;
	}

	void sdds::Student::display() {
		cout << "Name: " << m_name << endl;
		cout << "Age: " << m_age << endl;
	}
}