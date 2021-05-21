#pragma once

#ifndef SDDS_SHIP_H 
#define SDDS_SHIP_H
#include"Engine.h"

using namespace std;

namespace sdds {


	class Ship {
		Engine* engine;
		char* shipType;
		int engNum;

	public:
		Ship();
		~Ship();
		Ship(const char* , Engine* , int );
		bool empty() const;
		float calculatePower() const;
		void display() const;
		void set(const char*, Engine* , int );
		void setEmpty();

		Ship& operator+=(Engine e);

	};
	bool operator==(const Ship&, const Ship&);
	bool operator<(const Ship&, double);
}

#endif