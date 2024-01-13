#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "Train.h"

using namespace std;
namespace sdds {

    void Train::initialize() {
        m_name = nullptr;
        m_noOfPassengers = -1;
        m_departureTime = -1;
    }

    bool Train::validTime(int value) const {
        return (value >= 700 && value <= 2300 && value % 100 <= 59);
    } 


    bool Train::validNoOfPassengers(int value) const {
        return (value > 0 && value < MAX_NO_OF_PASSENGERS);
    }

    void Train::set(const char* name) {

        delete[] m_name;    // deallocate existing name
        m_name = nullptr;   // reinitalize to nullptr so it's not garbage
        if (name != nullptr && (strcmp(name, "\0"))) {
            m_name = new char[strlen(name) + 1];    
            strcpy(m_name, name);
        }
    }

    void Train::set(int noOfPassengers, int departure) {
        if (validNoOfPassengers(noOfPassengers) && validTime(departure)) {
            m_noOfPassengers = noOfPassengers;
            m_departureTime = departure;
        }
        else {
            m_noOfPassengers = -1;
            m_departureTime = -1;
        }
    }

    void Train::set(const char* name, int noOfPassengers, int departure) {
        set(name);
        set(noOfPassengers, departure);
    }

    void Train::finalize() {
        delete[] m_name;
    }

    bool Train::isInvalid() const {
        bool invalid = false;
        if  (m_name == nullptr || m_departureTime == -1 || m_noOfPassengers == -1 ){
            invalid = true;
        }
        return invalid;
    }   

    const char* Train::getName() const {
        return m_name;
    }

    int Train::noOfPassengers() const {
        return m_noOfPassengers;
    }

    int Train::getDepartureTime() const {
        return m_departureTime;
    }

    void Train::display() const {
        if (!isInvalid()) {
            cout << "NAME OF THE TRAIN:    " << m_name << endl;
            cout << "NUMBER OF PASSENGERS: " << m_noOfPassengers << endl;
            cout << "DEPARTURE TIME:       " << m_departureTime << endl;
        }
        else {
            cout << "Train in an invalid State!" << endl;
        }
    }
}
