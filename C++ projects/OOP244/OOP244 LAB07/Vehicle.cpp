//Name: Lara Fahmi 
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<cctype>
#include<iomanip>
#include "Vehicle.h"
#include"Car.h"

using namespace std;
using namespace sdds;

namespace sdds
{
	Vehicle::Vehicle() {
		setEmpty();
	}


	Vehicle::Vehicle(int speed, int seats) {
		if (speed >= MIN_SPEED && seats > 0) {
			m_speed = speed;
			m_noOfSeats = seats;
		}
		else {

			*this = Vehicle();
		}
	}

	void Vehicle::setEmpty() {
		m_speed = 0;
		m_noOfSeats = 0;
	}

	void Vehicle::setSpeed(int vspeed) {
		if (vspeed >= MIN_SPEED) {
			m_speed = vspeed;
		}
		else setEmpty();
		
	}

	bool Vehicle::finetune() {
		bool value = false;
		if (m_speed > MAX_SPEED) {
			m_speed = MIN_SPEED;
			value = true;
		}
		else {
			cout << "The car cannot be tuned" << endl;
		}
		return value;
	}


	std::ostream& Vehicle::display(std::ostream& os) const {
			if (m_speed >= MIN_SPEED && m_noOfSeats > 0) {
			os << "|" << m_speed << "|" << m_noOfSeats << endl;

			if (m_speed > MAX_SPEED) {
				os << "Car has to be fine tuned for speed limit" << endl;
			}}
			else { os << "This car is not initiated" << endl; }
	return os;
	}


	std::istream& Vehicle::input(std::istream& in) {
		int sp;
		cout << "Enter the Vehicle`s speed: ";
		in >> sp;

		int st;
		cout << "Enter no of seats: ";
		in >> st;

		Vehicle temp(sp, st);
		if (temp.m_speed != 0)
			* this = temp;
		else
			*this = Vehicle();
		return in;

	}

	std::ostream& operator<<(std::ostream& os, const Vehicle& v) {
		v.display(os);
		return os;
	}
	std::istream& operator>>(std::istream& in, Vehicle& V) {
		V.input(in);
		return in;
	}
}