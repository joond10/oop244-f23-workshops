#define _CRT_SECURE_NO_WARNINGS
#include "Label.h"
using namespace std;
namespace sdds {
	void Label::init() {
		m_topLeft = '+';
		m_topLine = '-';
		m_topRight = '+';
		m_rightLine = '|';
		m_bottomRight = '+';
		m_bottomLine = '-';
		m_bottomLeft = '+';
		m_leftLine = '|';
	}
	void Label::deallocate() {
		delete[] m_content;
		m_content = nullptr;
	}

	Label::Label() {
		init();
		m_content = nullptr;
	}

	Label::Label(const char* frameArg) {
		init();
		if (frameArg != nullptr) {
			m_topLeft = frameArg[0];
			m_topLine = frameArg[1];
			m_topRight = frameArg[2];
			m_rightLine = frameArg[3];
			m_bottomRight = frameArg[4];
			m_bottomLine = frameArg[5];
			m_bottomLeft = frameArg[6];
			m_leftLine = frameArg[7];
		}
	}

	Label::Label(const char* frameArg, const char* content) {
		init();
		if (frameArg != nullptr) {
			m_topLeft = frameArg[0];
			m_topLine = frameArg[1];
			m_topRight = frameArg[2];
			m_rightLine = frameArg[3];
			m_bottomRight = frameArg[4];
			m_bottomLine = frameArg[5];
			m_bottomLeft = frameArg[6];
			m_leftLine = frameArg[7];
		}
		deallocate();
		if (content != nullptr) {
			m_content = new char[71]; 
			strncpy(m_content, content, 70);
			m_content[70] = '\0'; 
		}
	}

	Label::~Label() {
		deallocate();
	}

	std::istream& Label::readLabel() {
		
		char inputLabel[71];

		deallocate();
		cin.getline(inputLabel, 71);
		m_content = new char[strlen(inputLabel) + 1];
		strcpy(m_content, inputLabel);
		return cin;
	}

	std::ostream& Label::printLabel() const {

		if (m_content != nullptr) {	//If there is a message, print label with message
			cout << m_topLeft;
			cout.width(strlen(m_content)+ 3); //1 for null terminator and 2 for space padding
			cout.fill(m_topLine);
			cout << m_topRight << endl;

			cout << (m_leftLine);
			cout.width(strlen(m_content) + 3);
			cout.fill(' ');
			cout << (m_rightLine) << endl;

			cout << (m_leftLine) << " ";
			cout.width(strlen(m_content));
			cout.setf(ios::left);
			cout << m_content;
			cout << " " << (m_rightLine) << endl;
			cout.unsetf(ios::left);

			cout << (m_leftLine);
			cout.width(strlen(m_content) + 3);
			cout  << (m_rightLine) << endl;

			cout << m_bottomLeft;
			cout.width(strlen(m_content) + 3);
			cout.fill(m_bottomLine);
			cout << m_bottomRight;
		}
		else {
			cout << m_topLeft;	//If there is no message, print empty label
			cout.width(20);
			cout.fill(m_topLine);
			cout << m_topRight << endl;

			cout << (m_leftLine);
			cout.width(20);
			cout.fill(' ');
			cout << (m_rightLine) << endl;

			cout << (m_leftLine);
			cout.width(20);
			cout << (m_rightLine) << endl;

			cout << (m_leftLine);
			cout.width(20);
			cout << (m_rightLine) << endl;

			cout << m_bottomLeft;
			cout.width(20);
			cout.fill(m_bottomLine);
			cout << m_bottomRight << endl;
		}
		return cout;
	}

	Label& Label::text(const char* content) {

		deallocate();
		m_content = new char[71];  
		strncpy(m_content, content, 70);
		m_content[70] = '\0';  

		return *this;
	}

}