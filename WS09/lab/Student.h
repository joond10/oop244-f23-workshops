#ifndef SDDS_STUDENT_H
#define SDDS_STUDENT_H
namespace sdds {
class Student {
	char* m_name;
	size_t m_age;
public:
	Student();
	Student(const char* name, size_t age);
	Student& operator=(const Student& anotherStudent);
	Student(const Student& anotherStudent);
	virtual ~Student();
	void display();
};

}

#endif // !SDDS_STUDENT_H
