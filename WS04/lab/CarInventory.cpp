#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "CarInventory.h"
using namespace std;
namespace sdds {
	void CarInventory::resetInfo() {
		m_type = nullptr;
		m_brand = nullptr;
		m_model = nullptr;
		m_year = 0;
		m_code = 0;
		m_price = 0;
	}

	void CarInventory::deallocate() {
		delete[] m_type;
		delete[] m_brand;
		delete[] m_model;
		m_type = nullptr;
		m_brand = nullptr;
		m_model = nullptr;
	}

	CarInventory::CarInventory() {
		resetInfo();
	}

	CarInventory::CarInventory(const char* type, const char* brand, const char* model, int year, int code, double price) {
		resetInfo();
		if (type != nullptr && brand != nullptr && model != nullptr) { 
			m_type = new char[strlen(type) + 1];
			m_brand = new char[strlen(brand) + 1];
			m_model = new char[strlen(model) + 1];
		}
		setInfo(type, brand, model, year, code, price);
	}

	CarInventory::~CarInventory() {
		deallocate();
	}

	CarInventory& CarInventory::setInfo(const char* type, const char* brand, const char* model, int year, int code, double price) {

		deallocate();
		m_type = new char[strlen(type) + 1];
		m_brand = new char[strlen(brand) + 1];
		m_model = new char[strlen(model) + 1];
		strcpy(m_type, type);
		strcpy(m_brand, brand);
		strcpy(m_model, model);
		m_year = year;
		m_code = code;
		m_price = price;

		return *this;
	}

	void CarInventory::printInfo() const { 
		cout << "| ";
		cout.width(10); 
		cout.setf(ios::left);
		cout << m_type;
		cout << " | ";

		cout.width(16);
		cout << m_brand; 
		cout << " | ";

		cout.width(16);
		cout << m_model; 
		cout << " | ";

		cout.width(4);
		cout << m_year; 
		cout << " | ";
		cout.unsetf(ios::left);

		cout.width(4);
		cout << m_code; 
		cout << " |";

		cout.width(10);
		cout.setf(ios::fixed);
		cout.precision(2); 
		cout << m_price; 
		cout << " | ";

		cout << endl;
	}

	bool CarInventory::isValid() const {

		return (m_type != nullptr && m_brand != nullptr && m_model != nullptr && m_year >= 1990 && m_code >= 100 && m_code <= 999 && m_price > 0);
	}

	bool CarInventory::isSimilarTo(const CarInventory& car) const {
	
		bool valid = false;
		if (m_type != nullptr) { //Just need to interrogate m_type. If it's null, we don't compare
			if ((strcmp(m_type, car.m_type) == 0) && (strcmp(m_model, car.m_model) == 0) && (strcmp(m_brand, car.m_brand) == 0) && m_year == car.m_year) {
				valid = true;
			}
		}
		return valid;
	}

	int sdds::find_similar(CarInventory car[], const int num_cars) {

		int match{};
		for (int i = 0; i < num_cars; i++) {
			for (int j = i + 1; j < num_cars; j++) {
				if (car[i].isSimilarTo(car[j])) {
					match = i;
				}
			}
		}
		return match;
	}
}