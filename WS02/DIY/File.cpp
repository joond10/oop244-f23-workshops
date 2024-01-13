/***********************************************************************
// OOP244 Workshop #2 DIY (part 2):
//
// File  File.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//   To completed by students
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include "File.h"
#include "Population.h"

namespace sdds {
    FILE* fptr;
    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }
    void closeFile() {
        if (fptr) fclose(fptr);
    }

    int noOfRecords() {
        int noOfRecs = 0;
        char ch;
        while (fscanf(fptr, "%c", &ch) == 1) {
            noOfRecs += (ch == '\n');
        }
        rewind(fptr);
        return noOfRecs;
    }
    bool read(const char* partial_postal_code_prefix, Population& information) {
        bool ok = false;
        if (!strcmp("all", partial_postal_code_prefix)) {
            if (fscanf(fptr, "%[^,],%d\n", information.m_code, &information.m_population) == 2) {
                ok = true;
            }
        }
        else if (strcmp("all", partial_postal_code_prefix)) {
            if (fscanf(fptr, "%[^,],%d\n", information.m_code, &information.m_population) == 2) {
                if (startsWith(information.m_code, partial_postal_code_prefix)) {
                    ok = true;
                }
            }
        }
        return ok;
    }

    int findMatches(const char* filename, const char* partial_postal_code_prefix, int population) {
        char postalCode[4]{};
        int matches{};
        int recs{};
        int i{};

        if (openFile(filename)) {
            int recs = noOfRecords();

            for (i = 0; i < recs; i++) {
                if (!strcmp("all", partial_postal_code_prefix)) {
                    matches = recs;
                }
                else if (fscanf(fptr, "%[^,],%d\n", postalCode, &population) == 2) {
                    if (startsWith(postalCode, partial_postal_code_prefix)) {
                        matches++;
                    }

                }
            }
            closeFile();
        }
        return matches;
    }
}