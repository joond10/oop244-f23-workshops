#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include "Phone.h"
#include "cStrTools.h"
using namespace std;



namespace sdds {

	// runs the phone directory application
	void phoneDir(const char* programTitle, const char* fileName) {

		char temp1[MAX_NAME_LEN + 1] = { '\0' };
		char temp2[MAX_NAME_LEN + 1] = { '\0' };
		char selection[MAX_NAME_LEN + 1] = { '\0' };
		phoneData phone = { '\0' };

		cout << programTitle << " phone direcotry search" << endl;
		cout << "-------------------------------------------------------" << endl;
		FILE* fp = NULL;
		fp = fopen(fileName, "r");

		if (fp != NULL) {
			do {
				cout << "Enter a partial name to search (no spaces) or enter '!' to exit" << endl;
				cout << ">"; 
				cin >> selection;

				while (fscanf(fp, "%[^\t]\t%s\t%s\t%s\n", phone.name, phone.area, phone.prefix, phone.number) == 4)
				{
					toLowerCaseAndCopy(temp1, phone.name);
					toLowerCaseAndCopy(temp2, selection);
					if (strStr(temp1, temp2))
					{
						cout << phone.name << ": " << "(" << phone.area << ") " <<  phone.prefix << "-" << phone.number << endl;
					}
				}
				rewind(fp);

			} while (strCmp("!", selection));
		}
		else {
			cout << fileName << "file not found!" << endl;
		}

		cout << "Thank you for using " << programTitle << " directory." << endl;
	}

}