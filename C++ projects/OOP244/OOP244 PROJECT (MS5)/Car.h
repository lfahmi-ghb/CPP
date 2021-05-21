#pragma once

#ifndef SDDS_CAR_H 
#define SDDS_CAR_H
#include <iostream>
#include "ReadWritable.h"
#include "Vehicle.h"


using namespace std;

namespace sdds {

	class Car : public Vehicle {
		bool carWash = false;

	public:
		bool m_empty = false;
		Car();
		Car(const char* palate, const char* model);
		~Car();
		Car(const Car& src) = delete;
		Car& operator=(const Car&) = delete;
		std::istream& read(std::istream& istr = std::cin);
		std::ostream& write(std::ostream& ostr = std::cout)const;
	bool isEmpty()const ;

	};
}
#endif
