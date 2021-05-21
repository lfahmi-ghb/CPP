//Name: LARA FAHMI
//FINAL ADJUSTMENTS(MILESTONE 6)


#ifndef SDDS_PARKING_H__
#define SDDS_PARKING_H__
#include "Menu.h"
#include "Motorcycle.h"
#include "Car.h"

namespace sdds {
	const int MAX_NO_SPOTS = 100;
	class Parking {
	private:
		char* fileName;
		Menu m_main;
		Menu m_vehicle;
		int n_spots;
		int n_parkedV;
		Vehicle* V[MAX_NO_SPOTS];


		
		bool isEmpty() const;
		void parkingStatus() const;
		void parkVehicle();
		void returnVehicle();
		void listParkVehicles() const;
		bool closePark();
		bool exitApp() const;
		bool loadFile();
		void saveData() const;

	public:
		Parking();
		Parking(const char*, int);
		~Parking();
		Parking(const Parking& src) = delete;
		Parking& operator=(const Parking&) = delete;
		int run();

		//other functions
		void setEmpty();

	};

}



#endif