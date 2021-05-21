//Name: Lara Fahmi

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cctype>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <locale>
#include "Car.h"
using namespace std;

namespace sdds {

	Car::Car() {
		Vehicle::setEmpty();
	}


	Car::Car(const char* palate, const char* model) : Vehicle(palate, model) {
	//	Vehicle::Vehicle(palate, model);

	}

	std::istream& Car::read(std::istream& istr ) {
		
		if (isCsv()) {
			Vehicle::read(istr);
			char temp [10];
			istr.getline(temp, 10);
			stringstream ss;
			ss << temp;
			ss >> carWash;
		}

		else {
			if (!isCsv()) {
				bool exit = false;
				carWash = false;
				cout << endl;
				cout << "Car information entry" << endl;
				Vehicle::read(istr);
				cout << "Carwash while parked? (Y)es/(N)o: " ;

				do {
					char choice[90];
					cin >> choice;


					if (strlen(choice) > 1 || (choice[0] != 'y' && choice[0] != 'n' && choice[0] != 'Y' && choice[0] != 'N')) {
						cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
					}
					else {
						if (choice[0] == 'y'  || choice[0] == 'Y' ) {
							carWash = 1;
						}
						else if (choice[0] == 'n' || choice[0] == 'N') {
							carWash = 0;
						}
						exit = true;
					}
				} while (!exit);


			}
		}
		return istr;
	}

	


	Car::~Car() {
		Vehicle::deleteMakeModel();
	}

	std::ostream& Car::write(std::ostream& ostr)const {
		if (Vehicle::isEmpty()){

			//if (Car(getLicensePlate(), getMakeModel()) = nullptr)
			cout << "Invalid Car Object" << endl;
	}
		else
		{
			if (isCsv()) {
				cout << "C,";

				Vehicle::write(ostr);

				cout << carWash <<endl;
			}
			if (!isCsv()) {
				cout << "Vehicle type: Car" << endl;
				Vehicle::write(ostr);
				if (carWash) {
					cout << "With Carwash" << endl;

				}
				if (!carWash) {
					cout << "Without Carwash" << endl;
				}
			}
		}
		return ostr;
	}
}