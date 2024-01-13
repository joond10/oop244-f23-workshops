#include <iostream>
#ifndef SDDS_LABEL_H
#define SDDS_LABEL_H
namespace sdds {
	class Label {
		char* m_content;
		char m_topLeft;
		char m_topLine;
		char m_topRight;
		char m_rightLine;
		char m_bottomRight;
		char m_bottomLine;
		char m_bottomLeft;
		char m_leftLine;

		void init();
		void deallocate();
	public:
		Label();
		Label(const char* frameArg);
		Label(const char* frameArg, const char* content);
		~Label();
		std::istream& readLabel();
		std::ostream& printLabel()const;
		Label& text(const char* content);
	};
}
#endif // !SDDS_LABEL_H
