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

	Car::Car() {
		setEmpty();
	}
	
	Car::Car(const char* type, int year, int speed, int seats) : Vehicle(speed, seats) {
		if (year > MIN_YEAR || type != nullptr) {
			setType(type);
			setYear(year);
		}
		else {
		
			*this = Car();
		}
	}

	void Car::setYear(int year) {
		if (year > MIN_YEAR) {
			m_regYear = year;
		}
		else setEmpty(); 
	}

	void Car::setType(const char* ctype) {
		if (ctype != nullptr && strlen(ctype) <= MAX_CHAR) {
			strcpy(m_carType, ctype);
		}
		else setEmpty();
	
	}

	void Car::setEmpty() {
		m_carType[0] = '\0';
		m_regYear = 0;
	}

	void Car::finetune() {
		if (m_regYear >= MIN_YEAR) {
			Vehicle::setSpeed(MIN_SPEED);
			cout << "This car is finely tuned to default speed" << endl;
		}
		else {
			cout << "Car cannot be tuned and has to be scraped" << endl;
		}
	}

	ostream& Car::display(ostream& os) const {
		if (m_carType[0] == '\0') {
			os << "Car is not initiated yet" << endl;
		}
		else {
			os.width(20);
			os.setf(ios::left);
			os << m_carType;
			os << m_regYear;
			//os << m_carType << os.width(20)<< m_regYear;
			Vehicle::display(os);
		}
		return os;
	}

	std::istream& Car::input(std::istream& in) {

		char type[MAX_CHAR + 1];
		cout << "Enter the car type: ";
		in.getline(type, MAX_CHAR + 1);


		int year;
		cout << "Enter the car registration year: ";
		in >> year;


		if (type[0] != '\0' && year >= 2000) {
			strcpy(m_carType, type);
			m_regYear = year;
		}
		//&Vehicle::input;
		Vehicle::input(in);
		return in;
	}


	std::ostream& operator<<(std::ostream& os, const Car& C) {
		C.display(os);
		return os;
	}
	std::istream& operator>>(std::istream& in, Car& C) {
		C.input(in);
		return in;
	}
}

/*
	Car::Car(const char* type, int year, int speed, int seats) : Vehicle(speed, seats) {
		if (year > MIN_YEAR || type != nullptr) {
			setType(type);
			setYear(year);
			if (type != nullptr && strlen(type) <= MAX_CHAR) {
				strcpy(m_carType, type);
			}

			if (year > MIN_YEAR) {
				m_regYear = year;
			}

		else {

			*this = Car();
		}
	}*/