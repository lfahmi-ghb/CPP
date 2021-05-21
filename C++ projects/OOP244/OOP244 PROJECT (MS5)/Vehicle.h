#pragma once

#ifndef SDDS_VEHICLE_H 
#define SDDS_VEHICLE_H
#include <iostream>
#include "ReadWritable.h"

using namespace std;

namespace sdds {
#define MAX_CHAR 8
	class Vehicle : public ReadWritable {

		char v_license[MAX_CHAR + 1];
		char* v_model;
		int v_pSpotNum;

	public:
		Vehicle();
		Vehicle(const char*, const char*);
		Vehicle(const Vehicle& src) = delete;
		~Vehicle();
		
	protected:
		void setEmpty();
		bool isEmpty()const;
		const char* getLicensePlate() const;
		const char* getMakeModel() const;
		void setMakeModel(const char*);
	public:
		
		
		void setLicensePalate(const char* );
		int getParkingSpot() const;
		void setParkingSpot(int);
		bool operator==(const char* other)const;
		//	bool operator==(const Vehicle&)const;
		friend bool operator==(const Vehicle& v1, const Vehicle& v2);
		std::istream& read(std::istream& istr = std::cin);
		std::ostream& write(std::ostream& ostr = std::cout)const;

		//other member functions
		//void setEmpty();
		void deleteMakeModel();
	};

	ostream& operator<<(ostream& os, const ReadWritable& r);
	istream& operator>>(istream& in, ReadWritable& w);
}

#endif
