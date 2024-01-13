#ifndef SDDS_LABELMAKER_H
#define SDDS_LABELMAKER_H
namespace sdds {


	class LabelMaker {
		Label* m_labels;
		int m_noOfLabels;
		
	public:
		LabelMaker(int noOfLabels);
		void readLabels();
		void printLabels();
		~LabelMaker();
	};


}
#endif // !SDDS_LABELMAKER_H
