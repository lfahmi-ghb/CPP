//Name: Lara Fahmi

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cctype>
#include <cstring>
#include <iomanip>
#include "Parking.h"
using namespace std;

namespace sdds {

	void Parking::setEmpty() {
		m_main = nullptr;
		m_vehicle = nullptr;
	}

	///CONSTRUCTOR AND DESTUCTOR
	Parking::Parking(const char* name) {
		fileName = nullptr;
		if (name != nullptr && name[0] != 0) {
			fileName = new char[strlen(name) + 1];
			strcpy(fileName, name);
		}
		if (loadFile()) {
			//add to the main-menu
			m_main = new Menu("Parking Menu, select an action:");
			m_main->add("Park Vehicle");
			m_main->add("Return Vehicle");
			m_main->add("List Parked Vehicles");
			m_main->add("Close Parking (End of day)");
			m_main->add("Exit Program");
			//add vehicles sub-menu
			m_vehicle = new Menu("Select type of the vehicle:", 1);
			m_vehicle->add("Car");
			m_vehicle->add("Motorcycle");
			m_vehicle->add("Cancel");
		}
		else {
			cout << "Error in data file" << endl;
			setEmpty();
		}
	}

	Parking::~Parking() {
		saveData(); //saving data into -filname-
		delete[] fileName;
		fileName = nullptr;
		delete m_main;
		delete m_vehicle;
	}


	////PRIVATE MEMBER FUNCTIONS///

	bool Parking::isEmpty() const {
		return fileName == nullptr;
	}

	void Parking::parkingStatus() const {
		cout << "****** Seneca Valet Parking ******" << endl;
	}

	void Parking::parkVehicle() const {

		switch (m_vehicle->run()) {
		case 1: cout << "Parking Car" << endl;
			break;
		case 2: cout << "Parking Motorcycle" << endl;
			break;
		case 3: cout << "Cancelled parking" << endl;
			break;
		default:
			cout << "wrong entry" << endl;
		}
	}

	void Parking::returnVehicle() const {
		cout << "Returning Vehicle" << endl;
	}

	void Parking::listParkVehicles() const {
		cout << "Listing Parked Vehicles" << endl;
	}

	bool Parking::closePark() const {
		cout << "Closing Parking" << endl;
		return true;
	}

	bool Parking::exitApp() const {
		bool exit = false;			
		bool response = false;
		//char* temp;
		
		cout << "This will terminate the program!" << endl;
		cout << "Are you sure? (Y)es/(N)o: ";
		do {
			char choice[90];
			cin >> choice;			

			/*if (temp && temp[0] != 0) {
				choice = new char[strlen(temp) + 1];
				strcpy(choice, temp);
			}
			else choice = nullptr;
			*/

			if (strlen(choice) > 1 || (choice[0] != 'y' && choice[0] != 'n' && choice[0] != 'Y' && choice[0] != 'N')) {
				cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
			}
			else {
				if (choice[0] == 'y' && choice[0] == 'n' && choice[0] == 'Y' && choice[0] == 'N') {
					response = true;					
				}
				exit = true;
			}
		} while (!exit);

		return response;
	}

	bool Parking::loadFile() const {
		bool load = fileName != nullptr; 
		if (load) {
			cout << "loading data from " << fileName << endl;
		}
		return load;
	}

	void Parking::saveData() const {
		if (!isEmpty())
			cout << "Saving data into " << fileName << endl;
	}

	//PUBLIC MEMBER FUNCTION//
	int Parking::run() const {
		//loadFile();
		if (!isEmpty()) {
			bool exit = false;
			do {
				parkingStatus();
				switch (m_main->run()) {
				case 1:
					parkVehicle();
					break;

				case 2:
					returnVehicle();
					break;

				case 3:
					listParkVehicles();
					break;
				case 4:
					exit = closePark();

					break;
				case 5:
					if (exitApp());
					cout << "Exiting program!" << endl;
					exit = true;
					break;
				default:
					cout << "Invalid" << endl;

				}
			} while (!exit);

		}
		return isEmpty() == false ;
	}

}


/////////DRAFTS/////////////

/*
	bool Parking::exitApp() const {
		bool value;

		char response[5];
		cout << "This will terminate the program!" << endl;
		cout << "Are you sure ? (Y)es / (N)o : " ;
		cin >> response;

			switch (response[4]) {

			case 'Y': case 'y':
				value = true;

			case 'N': case 'n':
				value = false;
			default:
				cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
				//cin >> response;

			}

		while (response != 'y' || response != 'Y' || response != 'n' || response != 'N') {
			cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
			cin >> response;
	 }
		
		return (strcmp(response, 'y') == 0)

		return value;
	}
	*/