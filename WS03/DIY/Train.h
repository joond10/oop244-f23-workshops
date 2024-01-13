#ifndef SDDS_TRAIN_H
#define SDDS_TRAIN_H

namespace sdds {

	const int MIN_TIME = 700;
	const int MAX_TIME = 2300;
	const int MAX_NO_OF_PASSENGERS = 1000;

	class Train {
		char* m_name;
		int m_noOfPassengers;
		int m_departureTime;
	public:

		//Manager methods
		void initialize();
		void finalize();

		//Validation 
		bool validTime(int value)const;
		bool validNoOfPassengers(int value)const;
		
		//Set
		void set(const char* name);
		void set(int noOfPassengers, int departure);
		void set(const char* name, int noOfPassengers, int departure);
		bool isInvalid()const;

		//Query
		const char* getName() const;
		int noOfPassengers() const;
		int getDepartureTime() const;
		void display() const;

		//P2
		bool load(int& unboarded);
		bool updateDepartureTime();
		bool transfer(const Train& newTrain);
	};
}

#endif // !SDDS_TRAIN_H