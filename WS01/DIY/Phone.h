#ifndef SDDS_PHONE_H
#define SDDS_PHONE_H
namespace sdds {

#define MAX_NAME_LEN 50


	struct phoneData
	{
		char name[MAX_NAME_LEN + 1];
		char area[4];
		char prefix[4];
		char number[5];
	};

	// runs the phone directory application
	void phoneDir(const char* programTitle, const char* fileName);
}
#endif