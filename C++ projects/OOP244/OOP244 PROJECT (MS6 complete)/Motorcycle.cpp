//Name: LARA FAHMI
//FINAL ADJUSTMENTS(MILESTONE 6)

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cctype>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <locale>
#include "Motorcycle.h"

using namespace std;

namespace sdds {
	Motorcycle::Motorcycle() : Vehicle() {

		Vehicle::setEmpty();

	}

	Motorcycle::Motorcycle(const char* palate, const char* model) : Vehicle(palate, model) {

	}

	istream& Motorcycle::read(istream& in) {
		if (isCsv()) {
			Vehicle::read(in);
			char temp[10];
			in.getline(temp, 10);
			stringstream ss;
			ss << temp;
			ss >> sideCar;
		}

		else {
			if (!isCsv()) {
				bool exit = false;

				cout << endl;
				cout << "Motorcycle information entry" << endl;
				Vehicle::read(in);
				cout << "Does the Motorcycle have a side car? (Y)es/(N)o: ";

				do {
					char choice[90];
					cin >> choice;


					if (strlen(choice) > 1 || (choice[0] != 'y' && choice[0] != 'n' && choice[0] != 'Y' && choice[0] != 'N')) {
						cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
					}
					else {
						if (choice[0] == 'y' || choice[0] == 'Y') {
							sideCar = 1;
						}
						else if (choice[0] == 'n' || choice[0] == 'N') {
							sideCar = 0;
						}
						exit = true;
					}
				} while (!exit);


			}

		}
		return in;
	}




	std::ostream& Motorcycle::write(std::ostream& ostr)const {
		if (Vehicle::isEmpty()) {
			cout << "Invalid Motorcycle Object" << endl;
		}
		else
		{
			if (isCsv()) {
				ostr << "M,";

				Vehicle::write(ostr);

				ostr << sideCar << endl;
			}
			if (!isCsv()) {
				cout << "Vehicle type: Motorcycle" << endl;
				Vehicle::write(ostr);
				if (sideCar) {
					cout << "With Sidecar" << endl;

				}

			}
		}
		return ostr;
	}


}