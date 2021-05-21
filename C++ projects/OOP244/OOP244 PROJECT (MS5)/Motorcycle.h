#pragma once

#ifndef SDDS_MOTORCYCLE_H 
#define SDDS_MOTORCYCLE_H
#include <iostream>
#include "Vehicle.h"
#include"ReadWritable.h"

using namespace std;

namespace sdds {

	class Motorcycle : public Vehicle {
		bool sideCar = 0;

	public:
		//bool yesOrNo()const;
		Motorcycle();
		Motorcycle(const char* palate, const char* model);
		Motorcycle(const Motorcycle& src) = delete;
		Motorcycle& operator=(const Motorcycle&) = delete;
		std::istream& read(std::istream& istr = std::cin);
		std::ostream& write(std::ostream& ostr = std::cout)const;
	};
	

}
#endif
