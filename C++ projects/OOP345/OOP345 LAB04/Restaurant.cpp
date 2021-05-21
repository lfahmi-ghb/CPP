//Name: Lara Fahmi
//Student Number: 109742197
#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <iomanip>
#include <iostream>
#include <cstring>
#include<vector>
#include<sstream>
#include <string>
#include<algorithm>
#include "Restaurant.h"

using namespace std;
using namespace sdds;


Restaurant::Restaurant() : reservation{ nullptr }, numOfreservations{ 0 } {

}

Restaurant::Restaurant(Reservation** res, size_t cnt) {

	if (cnt > 0 && res != nullptr) {
		numOfreservations = cnt;
		reservation = new Reservation[cnt];
			for (int i = 0; i < numOfreservations; i++) {
				reservation[i] = *res[i];
			}
	}
	else {
		setEmpty();
	}
}


///******COPYING*******/// 

Restaurant::Restaurant(const Restaurant& cpy) {
	numOfreservations = cpy.numOfreservations;
	reservation = new Reservation[cpy.numOfreservations];
	for (int i = 0; i < numOfreservations; i++) {
		reservation[i] = cpy.reservation[i];
	}
}

Restaurant& Restaurant::operator=(const Restaurant& cpy) {
	if (this != &cpy) {
		delete[] reservation;
		reservation = nullptr;
		numOfreservations = 0;

		numOfreservations = cpy.numOfreservations;
		reservation = new Reservation[cpy.numOfreservations];
		for (int i = 0; i < numOfreservations; i++) {
			reservation[i] = cpy.reservation[i];
		}
	}
	return *this;
}

///*****MOVING*****/// 
Restaurant::Restaurant(Restaurant&& cpy) noexcept {
	*this = move(cpy);
}

Restaurant& Restaurant::operator=(Restaurant&& cpy)noexcept {
	if (this != &cpy) {
		reservation = cpy.reservation;
		cpy.reservation = { nullptr };
		numOfreservations = cpy.numOfreservations;
		cpy.numOfreservations = 0;
	}
	return *this;
}

Restaurant::~Restaurant() {
	delete[] reservation;
	reservation = nullptr;

}


void Restaurant::setEmpty() {
	numOfreservations = 0;
	reservation = nullptr;

}


size_t Restaurant::size() const {
	return numOfreservations;
}

///****DISPLAY****/// 
ostream& Restaurant::display(ostream& os) const {
	if (numOfreservations > 0 && reservation != nullptr) {

		os << "--------------------------" <<endl;
		os << "Fancy Restaurant" << endl;
		os << "--------------------------"<<endl;
		for (int i = 0; i < numOfreservations; i++){
			os << reservation[i] ;
		}
		os << "--------------------------" << endl;

	}

	else {

		os << "--------------------------" <<endl;
		os << "Fancy Restaurant" <<endl;
		os << "--------------------------" <<endl;
		os << "The object is empty!"<<endl;
		os << "--------------------------"<<endl;
	}
	return os;
}


std::ostream& sdds::operator<<(std::ostream& os, const Restaurant& res)
{
	res.display(os);
	return os;
}
