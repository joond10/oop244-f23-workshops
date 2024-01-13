/***********************************************************************
// OOP244 Workshop #5 lab (part 1): tester program
//
// File  Flight.cpp
// Version 1.0
// Author   Asam Gulaid, revised by Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Flight.h"

using namespace std;
namespace sdds {

    void Flight::emptyPlane() {
        m_passengers = 0;
        m_fuel = 0;
        strcpy(m_title , "EmptyPlane");
    }

    // New Flight
    Flight::Flight() {
        emptyPlane();
    }
    Flight::Flight(int passengers, double fuel, const char* title) {
        emptyPlane();
        if (passengers > 0 && passengers <= Boen747Capacity && fuel >= 0 &&
            fuel <= FuelTankCapacity) {
            m_passengers = passengers;
            m_fuel = fuel;
            strcpy(m_title,title);
        }
    }
    std::ostream& Flight::display() const {

        if (*this) {
            cout << " Flight  |  Ready to Depart";
            cout << " ";
            cout.width(10);
            cout << std::string(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        else if (~*this) {
            cout << " Flight  |  Empty Plane    ";
        }
        else {
            cout << " Flight  |  Low Fuel       ";
            cout << " ";
            cout.width(10);
            cout << (const char *)(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        return cout;
    }

    Flight::operator bool() const{
        return(m_passengers && m_fuel >= (m_passengers * 600));
    }

    Flight::operator int() const{
        return(m_passengers);
    }

    Flight::operator double() const{
        return(m_fuel);
    }

    Flight::operator const char* () const{
        return(m_title);
    }

    bool Flight::operator~() const{
    
        return (!m_passengers);
    }

    Flight& Flight::operator=(Flight& setPlane){
        m_passengers = setPlane.m_passengers;
        m_fuel = setPlane.m_fuel;
        strcpy(m_title, setPlane.m_title);
        setPlane.emptyPlane();
        return *this;
    }

    Flight& Flight::operator=(int setPassenger){
    
        if (setPassenger > 0 && setPassenger <= Boen747Capacity) {
            m_passengers = setPassenger;
        }
        return *this;
    }

    Flight& Flight::operator=(double setFuel){

        if (setFuel > 0 && setFuel <= FuelTankCapacity) {
            m_fuel = setFuel;
        }
        return *this;
    }

    Flight& Flight::operator+=(double addFuel){
        if (addFuel > 0 && m_fuel != FuelTankCapacity) {
            m_fuel += addFuel;
            if (m_fuel > FuelTankCapacity) {
                m_fuel = FuelTankCapacity;
            }
        }
        return *this;
    }

    Flight& Flight::operator+=(int addPassenger){

        if (addPassenger > 0 && m_passengers != Boen747Capacity) {
            m_passengers += addPassenger;
            if (m_passengers > Boen747Capacity) {
                m_passengers = Boen747Capacity;
            }
        }
        return *this;
    }

    Flight& Flight::operator-=(double reduceFuel){

        if (reduceFuel > 0) {
            m_fuel -= reduceFuel;
            if (m_fuel < 0) {
                m_fuel = 0;
            }
        }
        return *this;
    }

    Flight& Flight::operator-=(int reducePassenger){
        if (reducePassenger > 0) {
            m_passengers -= reducePassenger;
            if (m_passengers < 0) {
                m_passengers = 0;
            }
        }
        return *this;
    }

    Flight& Flight::operator<<(Flight& rightPlane){
        if (*this && rightPlane) {
            m_passengers += rightPlane.m_passengers;
            if (m_passengers > Boen747Capacity) {
                rightPlane.m_passengers = (m_passengers - Boen747Capacity);
                m_passengers = Boen747Capacity;
            }
            else { //If everyone from right flight fits onto the plane
                rightPlane.m_passengers = 0;
            }
        }
        return *this;
    }

    Flight& Flight::operator>>(Flight& leftPlane){
        if (*this && leftPlane) {
            leftPlane.m_passengers += m_passengers;
            if (leftPlane.m_passengers > Boen747Capacity) {
                m_passengers = (leftPlane.m_passengers - Boen747Capacity);
                leftPlane.m_passengers = Boen747Capacity;
            }
            else {
                m_passengers = 0;
            }
        }
        return *this;
    }

    int Flight::operator+(const Flight& rightPlane) const{
        int total{};
        if (*this && rightPlane) {
            total = m_passengers + rightPlane.m_passengers;
        }

        return total;
    }

    int& operator+=(int& left, const Flight& rightPlane) {
        left += (int)rightPlane;
        return left;
    }

}