#pragma once

#ifndef SDDS_VEHICLE_H 
#define SDDS_VEHICLE_H
#include <iostream>

using namespace std;

namespace sdds {

	#define MIN_SPEED 100
	#define MAX_SPEED 140
	class Vehicle{
	int m_speed;
	int m_noOfSeats;

public:
	Vehicle();
	Vehicle(int, int);
	bool finetune();
	ostream& display(ostream& os) const;
	istream& input(istream& in);


	////additional functions
	void setEmpty();
	void setSpeed(int);
	//void setSeats(int);

	};
	ostream& operator<<(ostream& os, const Vehicle& v);
	istream& operator>>(istream& in, Vehicle& V);

	
	





}
#endif
