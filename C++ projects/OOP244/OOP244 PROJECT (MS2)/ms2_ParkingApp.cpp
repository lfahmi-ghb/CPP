/* ------------------------------------------------------
Final Project Milestone 2
Module: Parking
Filename: ms2_ParkingApp.cpp
Version 1.0
Author Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Date Reason
2020/3/12 Preliminary release
-----------------------------------------------------------*/
#include "Parking.h"
#include <iostream>
using namespace sdds;
int main() {
	Parking P("ParkingData.csv"), bad1(nullptr), bad2("");
	bad1.run();
	bad2.run();
	P.run();
	std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << std::endl;
	P.run();
	return 0;
}