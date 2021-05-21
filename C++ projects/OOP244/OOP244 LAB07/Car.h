#pragma once
#include <iostream>
#ifndef SDDS_CAR_H 
#define SDDS_CAR_H
#include "Vehicle.h"
using namespace std;

namespace sdds {
#define MAX_CHAR 20
#define MIN_YEAR 2000

	class Car : public Vehicle{
		char m_carType[MAX_CHAR];
		int m_regYear;

	public:

		Car();
		Car(const char* type, int regYear, int speed, int seats);
		void finetune();
		bool isEmpty();
		ostream& display(ostream& os) const;
		istream& input(istream& in);

		///additional functions
		void setEmpty();
		void setType(const char*);
		void setYear(int);

	};

	ostream& operator<<(ostream& os, const Car& C);
	istream& operator>>(istream& in, Car& C);
}
#endif
