/***********************************************************************
// OOP244 Workshop #5 DIY (part 2): tester program
//
// File  Portfolio.cpp
// Version 1.0
// Author   Asam Gulaid, revised by Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include "Portfolio.h"

using namespace std;
namespace sdds {


    Portfolio::Portfolio() {
       emptyPortfolio();
    }

    void Portfolio::emptyPortfolio()
    {
        m_value = 0;
        m_stock[0] = 0;
        m_type = 'E';
    }
    Portfolio::Portfolio(double value, const char* stock, char type) {
        emptyPortfolio();
        if (value >= 0 && ( type == 'V' || type == 'G' || type == 'I') ) {
            m_value = value;
            m_type = type;
            strcpy(m_stock, stock);
        }
    }

    void Portfolio::dispPortfolio() const{
            cout << " ";
            cout.width(10);
            cout << (const char*)(*this);
            cout << " | ";
            cout << "Value: ";
            cout.width(10);
            cout << double(*this);
            cout << " | ";
            cout << " Type: ";
            cout << char(*this);
    }
    std::ostream& Portfolio::display() const {

        if (~*this) {
            cout << " Portfolio  |  Bad-NG |";
            dispPortfolio();
        }
        else if (*this) {
            cout << " Portfolio  |  Active |";
            dispPortfolio();

        }
        else {
            cout << " Portfolio  |  EMPTY  |";
            dispPortfolio();
        }
        return cout;
    }

    Portfolio::operator double() const {
        return (m_value);
    }

    Portfolio::operator const char*() const {
        return (m_stock);
    }

    Portfolio::operator char() const {
        return (m_type);
    }

    Portfolio::operator bool() const {
        return (m_type == 'G' || m_type == 'V' || m_type == 'I');
    }

    Portfolio& Portfolio::operator+=(double addValue) {
        if (*this && addValue >= 0) {
            m_value += addValue;
        }
        return *this;
    }

    Portfolio& Portfolio::operator-=(double subtractValue) {
        if (*this && subtractValue >= 0) {
            m_value -= subtractValue;
        }
        return *this;
    }

    bool Portfolio::operator~() const { 
    
        return (m_value < 0);
    }

    Portfolio& Portfolio::operator<<(Portfolio& rightPortfolio) {
        if (*this && rightPortfolio) {
            m_value += rightPortfolio.m_value;
            rightPortfolio.emptyPortfolio();
        }
        return *this;
    }

    Portfolio& Portfolio::operator>>(Portfolio& leftPortfolio) {
        if (*this && leftPortfolio) {
            leftPortfolio += m_value;
            emptyPortfolio();
        }
        return *this;
    }

    double operator+(const Portfolio& leftPortfolio, const Portfolio& rightPortfolio) {

        double result;
        if (leftPortfolio && rightPortfolio) {
            result = (double)leftPortfolio + double(rightPortfolio);
        }
        else {
            result = 0.0;
        }
    
        return result;
    }

    double operator+=(double& left, const Portfolio& rightPortfolio) {
    
        left += double(rightPortfolio);
        return left;
    }

}