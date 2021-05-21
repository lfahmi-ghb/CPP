#pragma once
//Name: Lara Fahmi
#ifndef SDDS_PARKING_H 
#define SDDS_PARKING_H

#include <iostream>
#include <string>
#include "Menu.h"
using namespace std;

namespace sdds {

	class Parking {

		char* fileName;
		Menu *m_main;
		Menu *m_vehicle;

		bool isEmpty() const; 
		void parkingStatus() const;
		void parkVehicle() const;
		void returnVehicle() const;
		void listParkVehicles() const;
		bool closePark() const;
		bool exitApp() const;
		bool loadFile() const;
		void saveData() const;

	public:
		Parking(const char* name);
		~Parking();
		Parking(const Parking& src) = delete;
		Parking& operator=(const Parking&) = delete;
		int run() const;

		//other functions
		void setEmpty();
	};
}

#endif