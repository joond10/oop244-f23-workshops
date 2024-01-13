#include <iostream>
#ifndef SDDS_HEALTHCARD_H
#define SDDS_HEALTHCARD_H

namespace sdds {
   const int MaxNameLength = 55;
   class HealthCard {
      char* m_name{};
      long long m_number;
      char m_vCode[3];
      char m_sNumber[10];
       //Returns true if the four parts of the ID card are valid. 
       bool validID(const char* name, long long number, const char vCode[], const char sNumber[]) const;
       //Sets the HeathCard object to a recognizable empty (invalid) state by setting m_name to nullptr;
       void setEmpty();
       //Allocate and copy logic
       void allocateAndCopy(const char* name);
       //"peek()" and see if the next character in the keyboard buffer is the same as the ch argument
       void extractChar(std::istream& istr, char ch) const;
       //Display formatted like "1234567890-AB, XY7652341"
       std::ostream& printIDInfo(std::ostream& ostr)const;
       void set(const char* name, long long number, const char vCode[], const char sNumber[]);
   public:
       //Takes care of no values entered using default values and setting if 4 values provided
       HealthCard(const char* name = nullptr, long long number = 0, const char* vCode = "", const char* sNumber = "");
       //Rule of three
       HealthCard(const HealthCard& hc);
       //Copy Assignment overload
       HealthCard& operator=(const HealthCard& hc);
       //Destructor
       ~HealthCard();
       //Boolean type conversion operator
       operator bool()const;
       //Write 
       std::ostream& print(std::ostream& ostr, bool toFile = true) const;
       // Read in format of "Luke Skywalker,1231231234-XL,AF1234567"
       std::istream& read(std::istream& istr);
       //Public member function for helper function to access 
       bool isValid() const;
   };
       //Insertion operator overload - uses print method
       std::ostream& operator<<(std::ostream& ostr, const HealthCard& hc);
       //extraction operator overload - uses read method
       std::istream& operator>>(std::istream& istr, HealthCard& hc);
}
#endif // !SDDS_HealthCard_H


