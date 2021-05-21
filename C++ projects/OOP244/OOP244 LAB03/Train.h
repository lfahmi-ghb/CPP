#ifndef SDDS_TRAIN_H
#define SDDS_TRAIN_H

namespace sdds {
#define MAX_NAME 30
#define MAX_DESC 20
#define MAX_WEIGHT 700.555
#define MIN_WEIGHT 40.444

	class Cargo {

		char description[MAX_DESC+1];
		double weight;

	public:
		void init(const char*, double);
		void setWeight(double);
		double getWeight();
		char* getDescription();
		void setDescription(char*);
		void copyCargo( Cargo*);
	};



	class Train {
		char name[MAX_NAME+1];
		int id;
		 Cargo* cargo;
	
	public:
		void setTrain(const char*, int);
		bool isEmpty() const;
		void display() const;
		void loadCargo(Cargo&);
		void unloadCargo();
		bool swapCargo(Train& );
		bool increaseCargo(double);
		bool decreaseCargo(double);
	};


}

#endif