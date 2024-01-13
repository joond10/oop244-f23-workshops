#ifndef SDDS_GRADUATE_H
#define SSDD_GRADUATE_H
#include"Student.h"
namespace sdds {
class Graduate : public Student {
	char* m_supervisor;
	char* m_thesis;
public:
	Graduate();
	Graduate(const char* name, size_t age, const char* thesis, const char* supervisor);
	Graduate(const Graduate& anotherGraduate);
	Graduate& operator=(const Graduate& anotherGraduate);
	void display();

};
}


#endif // !SDDS_GRADUATE_H
