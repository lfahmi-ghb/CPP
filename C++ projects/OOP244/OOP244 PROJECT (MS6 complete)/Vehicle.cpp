//NAME: LARA FAHMI
//FINAL ADJUSTMENTS

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <iostream>
#include <cctype>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <locale>
#include "Vehicle.h"

using namespace std;

namespace sdds {

	///SET TO AN EMPTY SAFE STATE///
	void Vehicle::setEmpty() {
		v_license[0] = '\0';
		v_model = nullptr;
		v_pSpotNum = -1; //the safe empty state is -1, because 0 is acceptable here
	}

	void Vehicle::destructModel() {
		if (!isEmpty()) {
			delete[] v_model;
			v_model = nullptr;
		}
	}

	///CONSTRUCTORS///

	Vehicle::Vehicle() {
		setEmpty();
	}
	Vehicle::Vehicle(const char* lp, const char* mm) {
		/*	if (v_model) {
				delete[] v_model;
				v_model = nullptr;
			}*/

		if (lp != nullptr && mm != nullptr && lp[0] != '\0' && mm[0] != '\0' && strlen(lp) < MAX_CHAR && strlen(mm) >= 2) {
			strcpy(v_license, lp);
			v_model = new char[strlen(mm) + 1];
			strcpy(v_model, mm);
			v_pSpotNum = 0; //INITIALIZE value
			//getParkingSpot();
		}
		else {
			*this = Vehicle();
		}
	}



	Vehicle::~Vehicle() {
		destructModel();
	}


	///MEMBER FUNCTIONS///

	const char* Vehicle::getLicensePlate() const {
		return v_license;
	}
	const char* Vehicle::getMakeModel() const {
		return v_model;
	}

	void Vehicle::setMakeModel(const char* mm) {

		if (mm != nullptr && mm[0] != '\0') {
			destructModel();
			v_model = new char[strlen(mm) + 1];
			strcpy(v_model, mm);
		}
		else {
			destructModel();
			setEmpty();
		}
	}



	int Vehicle::getParkingSpot() const {
		return v_pSpotNum;
	}
	void Vehicle::setParkingSpot(int p) {
		if (p >= 0) {
			v_pSpotNum = p;
		}
		else {

			setEmpty();
		}
	}


	bool Vehicle::operator==(const char* other)const {

		bool same = true;
		int licP = strlen(v_license);
		int otherLicP = strlen(other);
		if (strlen(v_license) == strlen(other)) {
			for (otherLicP = 0; otherLicP < licP; otherLicP++) {
				if (toupper(v_license[otherLicP]) != toupper(other[otherLicP])) {
					same = false;
					break;
				}
			}
		}
		else {
			same = false;
		}
		return same;
	}

	bool operator==(const Vehicle& og, const Vehicle& other) {
		return (og == other.getLicensePlate());
	}


	bool Vehicle::isEmpty() const {
		return (v_license[0] == '\0' || v_license == nullptr || v_model == nullptr || v_model[0] == '\0' || v_pSpotNum < 0);//v_pSpotNum == -1;
	}


	istream& Vehicle::read(istream& in) {
		if (isCsv())
		{

			char temp_ps[10];
			char temp_mm[61];

			in.getline(temp_ps, 10, ',');
			in.getline(v_license, 20, ',');
			in.getline(temp_mm, 61, ',');

			//PARKING SPOT NUMBER
			stringstream ss;
			ss << temp_ps;
			ss >> v_pSpotNum;

			//LICENSE PALATE
			for (string::size_type i = 0; i < strlen(v_license) + 1; i++) {
				v_license[i] = toupper(v_license[i]);
			}

			//MAKE MODEL
			setMakeModel(temp_mm);
		}
		else {

		cout << "Enter Licence Plate Number: ";
		//char temp_lp_[60];
		in.getline(v_license, 60, '\n');
		while (strlen(v_license) <= 0 || strlen(v_license) > MAX_CHAR) {
			cout <<  "Invalid Licence Plate, try again: ";
			in.getline(v_license, 60, '\n');
		}
		for (string::size_type i = 0; i < strlen(v_license) + 1; i++) {
			
			v_license[i] = toupper(v_license[i]);
		}
		//strcpy(v_license, temp_lp_);
		

			//MAKE MODEL
			char temp_mm_[80];
			cout << "Enter Make and Model: ";
			in.getline(temp_mm_, 80);
			while (strlen(temp_mm_) < 2 || strlen(temp_mm_) > 60) {
				cout << "Invalid Make and model, try again: ";
				in.getline(temp_mm_, 60);
			}
			setMakeModel(temp_mm_);

			/*	v_model = new char[strlen(temp_mm_) + 1];
				strcpy(v_model, temp_mm_); */

				//PARKING SPOT NUMBER
			setParkingSpot(0);
		}


		for (string::size_type i = 0; i < strlen(v_license) + 1; i++) {
			v_license[i] = toupper(v_license[i]);
		}

		//if invalid then set empty
		if (strlen(v_license) < 1 || v_model == nullptr || strlen(v_model) < 2)
		{
			if (v_model != nullptr) {
				destructModel();
			}
			setEmpty();
		}
		return in;
	}

	ostream& Vehicle::write(ostream& ostr)const {
		if (v_license[0] == '\0' || v_license == nullptr || v_model == nullptr || v_model[0] == '\0' || v_pSpotNum < 0) {
			ostr << "Invalid Vehicle Object" << endl;
		}

		else {
			if (isCsv()) {
				ostr << v_pSpotNum << "," << v_license << "," << v_model << ",";

			}
			else {
				//	ostr << "Parking Spot Number: " << v_pSpotNum << endl;

				ostr << "Parking Spot Number: ";
				if (v_pSpotNum == 0) {
					ostr << "N/A" << endl;
				}
				else if (v_pSpotNum > 0) {
					ostr << v_pSpotNum << endl;
				}

				ostr << "Licence Plate: " << v_license << endl;
				ostr << "Make and Model: " << v_model << endl;
			}
		}
		return ostr;
	}

}