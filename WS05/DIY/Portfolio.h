/***********************************************************************
// OOP244 Workshop #5 DIY (part 2): tester program
//
// File  Portfolio.h
// Version 1.0
// Author   Asam Gulaid, revised by Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
#ifndef SDDS_Portfolio_H_
#define SDDS_Portfolio_H_
#include <iostream>


namespace sdds {

   class Portfolio {
      double m_value = 0;
      char m_stock[16];
      char m_type;
      void emptyPortfolio();
   public:
       Portfolio();
       Portfolio(double value, const char* stock, char type);
       std::ostream& display() const;
       void dispPortfolio() const;
       operator double() const;
       operator const char*() const;
       operator char() const;
       operator bool() const;
       Portfolio& operator+=(double addValue);
       Portfolio& operator-=(double subtractValue);
       bool operator~()const;
       Portfolio& operator<<(Portfolio& rightPortfolio);
       Portfolio& operator>>(Portfolio& leftPortfolio);
   };
   double operator+(const Portfolio& leftPortfolio, const Portfolio& rightPortfolio);
   double operator+=(double& left, const Portfolio& rightPortfolio);
}
#endif // SDDS_Portfolio_H_