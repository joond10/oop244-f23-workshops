/***********************************************************************
// OOP244 Workshop #5 lab (part 1): tester program
//
// File  Flight.h
// Version 1.0
// Author   Asam Gulaid, revised by Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
#ifndef SDDS_FLIGHT_H
#define SDDS_FLIGHT_H
#include <iostream>

namespace sdds {

   const int Boen747Capacity = 388;
   const int FuelTankCapacity = 238840;

   class Flight {

      int m_passengers = 0;
      double m_fuel = 0;
      char m_title[16];
      void emptyPlane();

   public:
      Flight();
      Flight(int passengers, double fuel, const char* title);
      std::ostream& display()const;
      operator bool()const;
      operator int()const;
      operator double()const;
      operator const char* ()const;
      bool operator~()const;
      Flight& operator=(Flight& setPlane);
      Flight& operator=(int setPassenger);
      Flight& operator=(double setFuel);
      Flight& operator+=(double addFuel);
      Flight& operator+=(int addPassenger);
      Flight& operator-=(double reduceFuel);
      Flight& operator-=(int reducePassenger);
      Flight& operator<<(Flight& rightPlane);
      Flight& operator>>(Flight& leftPlane);
      int operator+(const Flight& rightPlane) const;
   };
      int& operator+=(int& left, const Flight& rightPlane);

}
#endif // SDDS_FLIGHT_H