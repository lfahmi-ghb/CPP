//Name: LARA FAHMI
//FINAL ADJUSTMENTS(MILESTONE 6)

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cctype>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <locale>
#include <fstream>
#include "Parking.h"

using namespace std;

namespace sdds {

	//SET TO SAFE EMPTY STATE///
	void Parking::setEmpty() {
		delete[] fileName;				
		fileName = nullptr;
		for (int i = 0; i < MAX_NO_SPOTS; i++) { //delete vehicles
			V[i] = nullptr;
		}
		n_spots = 0;
		n_parkedV = 0;
	}

	///CONSTRUCTION///
	Parking::Parking(){
		fileName = nullptr;
		setEmpty();
	}


	Parking::Parking(const char* name, int spots) {
		fileName = nullptr;
		setEmpty();

		if (spots >= 10 && spots <= 100) {
			n_spots = spots;
			fileName = new char[strlen(name) + 1];
			strcpy(fileName, name);
		}
		if (loadFile()) {
			m_main = Menu("Parking Menu, select an action:");
			m_main.add("Park Vehicle");
			m_main.add("Return Vehicle");
			m_main.add("List Parked Vehicles");
			m_main.add("Close Parking (End of day)");
			m_main.add("Exit Program");

			m_vehicle = Menu("Select type of the vehicle:", 1);
			m_vehicle.add("Car");
			m_vehicle.add("Motorcycle");
			m_vehicle.add("Cancel");
		}
		else {
			fileName = nullptr;
			setEmpty();
			cout << "Error in data file" << endl;
		}

	}

	Parking::~Parking() {
		saveData();	
		delete[] fileName;
		fileName = nullptr;
		for (int i = 0; i < n_spots; i++) {
			if (V[i] != nullptr) {   //check if vehicles is pointing to null
				delete V[i];
				V[i] = nullptr;
			}
		}
	}

	////PRIVATE MEMBER FUNCTIONS///

	bool Parking::isEmpty() const {
		return fileName == nullptr;
	}

	void Parking::parkingStatus() const {
		cout << "****** Seneca Valet Parking ******" << endl << "*****  Available spots: ";
		cout.width(4);
		cout << left << n_spots - n_parkedV << " *****" << endl;
			
	}

	void Parking::parkVehicle() {
		if (n_spots - n_parkedV > 0) {		
			
	 
			Vehicle* VTemp;
			switch (m_vehicle.run()) // Otherwise the function displays the submenu Vehicle Selection men
			{
			case 1:
				VTemp = new Car();					 // it will dynamically create an instance of a Car 
				VTemp->setCsv(false);			    //set it NOT to be in Comma Separated mode 
				VTemp->read(cin);				   //and reads it from the console
	
				
					for (int i = 0; i < n_spots; i++){				//the function will search through the Parking Spots array 
						if (V[i] == nullptr) {					   // finds the first available(null) Parking Spot
							V[i] = VTemp;						  //sets it to the Vehicle pointer
							V[i]->setParkingSpot(i + 1);		 //set the Parking Spot to the spot number it was parked in (index + 1)
							n_parkedV++;
							cout << "\nParking Ticket" << endl;
							V[i]->write(cout);				//and prints the Vehicle 
							cout << endl;
							break;
						}				
				}

				break;
			case 2:  //same thing here
				VTemp = new Motorcycle();
				VTemp->setCsv(false);
				VTemp->read(cin);				
					for (int i = 0; i < n_spots; i++) {
						if (V[i] == nullptr) {
							V[i] = VTemp;
							V[i]->setParkingSpot(i + 1);
							n_parkedV++;
							cout << "\nParking Ticket" << endl;
							V[i]->write(cout);
							cout << endl;
							break;
						}	
				}

				break;
			case 3:
				cout << "Parking cancelled" << endl;
				break;
			default:
				break;
			}
		}
		else {								// If there are no Parking Spots available, the function prints this 
			cout << "Parking is full" << endl;
		}

	}

	void Parking::returnVehicle() {
		cout << "Return Vehicle" << endl;
		cout << "Enter Licence Plate Number: ";
		char temp_lp[61];
		cin.getline(temp_lp, 60, '\n');

		while ((strlen(temp_lp) > 8 || strlen(temp_lp) < 0 || temp_lp [0] == '\0')) {
			cout << "Invalid Licence Plate, try again: ";
			cin.getline(temp_lp, 60, '\n');
		}
		
		for (string::size_type i = 0; i < strlen(temp_lp) + 1; i++) {

			temp_lp[i] = toupper(temp_lp[i]);
		}

			
				bool found = false;
				for (int i = 0; i < n_spots; i++)            //Searches through the parked Vehicles for a matching licence plate.
				{
					if (strcmp(V[i]->getLicensePlate(), temp_lp) == 0) {     //if found
						found = true;
						cout << endl;
						cout << "Returning: " << endl;
						V[i]->setCsv(false);  //set it to false
						V[i]->write(cout);    //write it out
						cout << endl;
						delete V[i];         //delete it from the array
						V[i] = nullptr;
						n_parkedV--;  
						break;
					}
				}
				if (!found) //if not found
				{
					cout << "Licence plate " << temp_lp << " Not found" << endl;
				}
			

		
		
	}

	void Parking::listParkVehicles() const {
		cout << "*** List of parked vehicles ***" << endl;
		for (int i = 0; i < n_spots; i++)
		{
			if (V[i] != nullptr) {
				V[i]->setCsv(false);
				V[i]->write(cout);
				cout << "-------------------------------" << endl;
			}
		}
	}
	bool Parking::closePark() {
		bool close = true;
		if (n_spots == 0){
			cout << "Closing Parking" << endl;
		}

		else{
			char choice[11];
			cout << "This will Remove and tow all remaining vehicles from the parking!" << endl;
			cout << "Are you sure? (Y)es/(N)o: ";
			cin.getline(choice, 10, '\n');
			while (choice[1] != '\0' && (tolower(choice[0]) != 'y' || tolower(choice[0]) != 'n'))
			{
				cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";                    // prompt to try again
				cin.getline(choice, 60, '\n');

			}
					if (tolower(choice[0]) == 'y')
					{

						cout << "Closing Parking" << endl;
						for (int i = 0; i < n_spots; i++) 
						{
							if (V[i] != nullptr) {
								cout << endl;
								cout << "Towing request" << endl<< "*********************" << endl;
								V[i]->write();
								delete V[i];	//DELETE VEHICLES AFTER CLOSING
								V[i] = nullptr;
							}
						}
					}
					else {
						close = false; 
					}							
				}
		if (!close){
			cout << "Aborted!" << endl;
		}	
		return close;
	}

	bool Parking::exitApp() const {
	
		   //char* choice;
			char choice[11];
			bool exit = false;
		//	bool flag = true;
	
			cout << "This will terminate the program!" << endl;
			cout << "Are you sure? (Y)es/(N)o: ";
			
			cin.getline(choice,10, '\n');
			/*if (temp && temp[0] != 0) {
					choice = new char[strlen(temp) + 1];
					strcpy(choice, temp);
					}
				else choice = nullptr;
			*/

			while (choice[1] != '\0' && (tolower(choice[0]) != 'y' || tolower(choice[0]) != 'n')) {			//validate
				cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";                    // prompt to try again
				cin.getline(choice, 60, '\n');

			}

			if (tolower(choice[0]) == 'y'){
				exit = true;
				cout << "Exiting program!" << endl;
			}

			return exit;
	}


	
	

	bool Parking::loadFile() {
		bool state = true;
		if (!isEmpty()){
			ifstream file(fileName);
			if (file.is_open()) {

				while (file && state&& !(file >> ws).eof() && n_parkedV < n_spots) //if everything is true
				{
					char temp;
					file.get(temp); //Read one Character from the file
					file.ignore();  //and ignore the next.
					if (temp == 'M' || temp == 'C') {
						Vehicle* tempV;
						if (temp == 'M') // If the Character is ‘M’ create a dynamic instance of a Motorcycle
						{
							tempV = new Motorcycle();
						}
						else{
							tempV = new Car();  // Otherwise If the Character is ‘C’ create a dynamic instance of a Car 
						}
						tempV->setCsv(true); //then set the Vehicle to Comma Separate Value mode
						tempV->read(file);     //and read it from the data file. 


						if (!file.fail()) //If the opening of the file was not successful this function is in a good state
						{
							state = true;

							for (int i = 0; i < n_spots; i++) {
								if (V[i] == nullptr) {
									V[i] = tempV;
									V[i]->setParkingSpot(i + 1);
									n_parkedV++;
									break;
								}
							}
						}
						else    //otherwise if read was unsuccessful deallocate the Vehicle
						{
							state = false;
							delete tempV;
						}
					}
				}
			}
		}
		else {
			state = false;
		}
		return state;   //At the end return the state of the function. 
	}


	void Parking::saveData() const {
		if (!isEmpty())
		{

			ofstream f(fileName); // Using an instance of ofstream class open the file	
			{
				for (int i = 0; i < n_spots; i++) //If the file is opened successfully go through all the elements of the Parking Spots 
				{
					if (V[i] != nullptr) {
						V[i]->setCsv(true);
						V[i]->write(f);

					}
				}
			}
		}
	}

	//PUBLIC MEMBER FUNCTION//
	int Parking::run() {
		//loadFile();
		if (!isEmpty()) {
			bool exit = false;
			do {
				parkingStatus();
				switch (m_main.run()) {
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
					//cout << "Exiting program!" << endl;
					exit = true;
					break;
				default:
					cout << "Invalid" << endl;

				}
			} while (!exit);

		}
		return isEmpty() == false;
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