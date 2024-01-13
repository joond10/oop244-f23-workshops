/***********************************************************************
// OOP244 Workshop #2 DIY (part 2):
//
// File  Population.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//   To completed by students
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
***********************************************************************/
#include "Population.h"
#include "File.h"
#include <cstring>
#include <iostream>

using namespace std;
namespace sdds {

    Population* population = nullptr;
    int recs{};
    int matches{};

    void sort(){
        int i, j;
        Population temp;
        for (i = matches - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (population[j].m_population > population[j + 1].m_population) {
                    temp = population[j];
                    population[j] = population[j + 1];
                    population[j + 1] = temp;
                }
            }
        }
    }

    bool startsWith(const char* cstring, const char* subString) {
        return std::strstr(cstring, subString) == cstring;
    }
    void display() {
        int i;
        int totalPopulation{};

        cout << "Postal Code: population\n"
            << "-------------------------" << endl;

        sort();
        for (i = 0; i < matches; i++) {
            cout << i + 1 << "- " << population[i].m_code << ":  " << population[i].m_population << endl;
            totalPopulation += population[i].m_population;
        }

        cout << "-------------------------\n"
            << "Population of the listed areas: " << totalPopulation << "\n" << endl;
    }


    bool getPostalCode(char* postal_code_prefix)
    {
        bool ok = true;

        cout << "Population Report\n"
            "-----------------\n"
            "Enter postal code: \n"
            "> ";
        cin >> postal_code_prefix;
        if (!strcmp("!", postal_code_prefix)) {
            ok = false;
        }

        return ok;
    }

    bool load(const char* filename, const char* partial_postal_code_prefix)
    {
        bool ok = false;
        int i{};
        int j{};
        int currentPopulation{};

        matches = findMatches(filename, partial_postal_code_prefix, currentPopulation);
        population = new Population[matches];

        if (openFile(filename)) {
            recs = noOfRecords();
            for (i = 0, j = 0; i < recs && j < matches; i++) {
                if (read(partial_postal_code_prefix, population[j])) {
                    j++;
                    ok = true;
                }
            }

            closeFile();
        }
        if (!ok) {
            cout << "Postal Code: population\n"
                "-------------------------\n"
                "-------------------------\n"
                "Population of the listed areas: 0\n" << endl;
        }
        return ok;
    }
    void deallocateMemory() {

        delete[] population;
    }
}