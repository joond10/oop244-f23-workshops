/***********************************************************************
// OOP244 Workshop #2 lab (part 1)
//
// File  File.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//    To be completed by students
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include "File.h"
#include "Employee.h"

namespace sdds {
   FILE* fptr;
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
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
   void closeFile() {
      if (fptr) fclose(fptr);
   }
   // TODO: read functions go here    
   bool read(int& number) {

       bool ok = false;

       if (fscanf(fptr, "%d,", &number) == 1) {
           ok = true;
       }

       return ok;
   }
   bool read(double& salary) {

       bool ok = false;

       if (fscanf(fptr, "%lf,", &salary) == 1) {
            ok = true;
       }

       return ok;
   }
  
   bool read(char*& name) {

       char empName[128]{};
       bool ok = false; 

        if (fscanf(fptr, "%127[^\n]\n", empName) == 1) {
            name = new char[strlen(empName) + 1];
            strcpy(name, empName);
            ok = true;
        }
       return ok;
   }
   
}