/***********************************************************************
// OOP244 Workshop #2 lab (part 1)
//
// File  Employee.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//    To be completed by students
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
***********************************************************************/
#include <iostream>
#include "Employee.h"
#include "File.h"
using namespace std;
namespace sdds {

   int noOfEmployees;
   Employee* employees;


   void sort() {
      int i, j;
      Employee temp;
      for (i = noOfEmployees - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
            if (employees[j].m_empNo > employees[j + 1].m_empNo) {
               temp = employees[j];
               employees[j] = employees[j + 1];
               employees[j + 1] = temp;
            }
         }
      }
   }

   // TODO: Finish the implementation of the 1 arg load function which
   // reads one employee record from the file and loads it into the employee reference
   // argument
   bool load(Employee& employee) {
      bool ok = false;
      // return the combined success result of the three read functions. These read 
      // functions should set the properties of the reference argument of the load function

      if (read(employee.m_empNo) && read(employee.m_salary) && read(employee.m_name)) {
        ok = true;
      }

      return ok;
   }
   // TODO: Finish the implementation of the 0 arg load function 
   bool load() {
      bool ok = false;
      int i = 0;
      int flag = 0;

      if (!openFile(DATAFILE)) {
          cout << "Could not open data file: " << DATAFILE << endl;
      }
      else {
          noOfEmployees = noOfRecords();
          employees = new Employee[noOfEmployees];
          while (i < noOfEmployees && flag == 0) {
              if (load(employees[i])) {
                  i++;
                  ok = true;
              }

              else {
                  ok = false;
                  flag = 1;
                  cout << "Error: incorrect number of records read; the data is possibly corrupted." << endl;
              }
          }
      }
      closeFile();
 
      return ok;
   }

   // TODO: Implementation for the display functions go here
   void display(const Employee& employee) {
       cout << employee.m_empNo << ": " << employee.m_name << ", " << "$" << employee.m_salary << endl;
   }

   void display() {
       int i;

       cout << "Employee Salary report, sorted by employee number\n"
           "no - Empno, Name, Salary\n"
           "------------------------------------------------" << endl;

       sort();

       for (i = 0; i < noOfEmployees; i++) {
           cout << i + 1  << "- ";
           display(employees[i]);
       }
   }

   // TODO: Implementation for the deallocateMemory function goes here
   void deallocateMemory() {
       for (int i = 0; i < noOfEmployees; i++) {
           delete[] employees[i].m_name;
       }
       delete[] employees;
   }
}