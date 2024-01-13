#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "LblShape.h"
namespace sdds {

    const char* LblShape::label() const {
        return m_label;
    }

    LblShape::~LblShape() {
        delete[] m_label;
    }

    void LblShape::getSpecs(std::istream& istr) {
        char label[1000];
        istr.getline(label, 1000, ',');
        if (label) {
            delete[] m_label;
            m_label = new char[strlen(label) + 1];
            strcpy(m_label, label);
        }
    }

    LblShape::LblShape(){

    }

    LblShape::LblShape(const char* cstr) {
        delete[] m_label;
        m_label = new char[strlen(cstr) + 1];
        strcpy(m_label, cstr);
    }
}