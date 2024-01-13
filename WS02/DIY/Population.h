/***********************************************************************
// OOP244 Workshop #2 DIY (part 2):
//
// File  Population.h
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//   To completed by students
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
***********************************************************************/
#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_

namespace sdds {
	struct Population {
		char m_code[4];
		int m_population;
	};
   void sort();
   bool startsWith(const char* cString, const char* subString);
   void display();
   bool getPostalCode(char* postal_code_prefix);
   bool load(const char* filename, const char* partial_postal_code_prefix);
   bool read(const char* partial_postal_code_prefix, Population& information);
   void deallocateMemory();
}
#endif // SDDS_POPULATION_H_