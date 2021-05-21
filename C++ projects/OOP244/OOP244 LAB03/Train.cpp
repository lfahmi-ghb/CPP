#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstring>
#include "Train.h"

namespace sdds { 

	using namespace std;


	void Cargo::setWeight(double wght) {
		weight = wght;
	}
	double Cargo::getWeight() {
		return weight;
	}
	void Cargo::setDescription(char* desc) {
		strcpy(description, desc);
	}

	char* Cargo::getDescription() {
		return description;
	}

	void Cargo::init(const char* cargoId, double cargWht) {
		if (cargWht >= MIN_WEIGHT && cargWht <= MAX_WEIGHT) {
		weight = cargWht;
		
	}
		else {   		
			weight = MIN_WEIGHT;
		}

		if (strlen(cargoId) <= 20 && cargoId != nullptr) {
			 strcpy(description, cargoId);
		}
		
	}

	void Train::setTrain(const char* trainname, int num) {	

		if ((num >= 1) && (trainname != nullptr) /*&& (trainname[0] != '\0')*/) {
			id = num;
			strcpy(name, trainname);
			Train::cargo = nullptr;
		}
		else {
			id = 0;
			name[0] = '\0';
		}
	}

	bool Train::isEmpty() const{

		return !id;
	}

	void Train::display() const {
		cout << "***Train Summary***" << endl;
		
		
		
		if (isEmpty()) {
			cout << "This is an empty train." << endl;
		}
		if (!isEmpty()) {
			cout << "Name: " << name << " " << "ID: " << id << endl;

			if (cargo != nullptr) {
				cout << fixed << std::setprecision(2);
				cout << "Cargo: " << cargo->getDescription() << " " << "Weight: " << cargo->getWeight() << endl;
				

			}
			else {
				cout << "No cargo on this train." << endl;
			}
		}
	
	}

	void Train::loadCargo(Cargo& cPtr) {
		cargo = new Cargo;
		//strcpy(cargo->getDescription, n.getDescription);
		cargo->setDescription(cPtr.getDescription());
		cargo->setWeight(cPtr.getWeight());

	}
	void Train::unloadCargo() {
		
		delete cargo;
		cargo = nullptr;
	}

	
	bool Train::increaseCargo(double num) {
		bool value = true;
		if (cargo != nullptr) {

			double sum = cargo->getWeight() + num;
			if (sum < MAX_WEIGHT) {
				cargo->setWeight(sum);
				value = true;
			}
			else if (sum > MAX_WEIGHT && cargo->getWeight() != MAX_WEIGHT) {
				cargo->setWeight(MAX_WEIGHT);
				value = true;
			}
			else if (cargo->getWeight() == MAX_WEIGHT) {
				value = false;
			}
		}
			else {
				value = false;
			}
		
		return value;
	};

	bool Train::decreaseCargo(double num) {
		bool value = false;

		if (cargo != nullptr) {
			double sum = cargo->getWeight() - num;
			if (sum > MIN_WEIGHT && sum < MAX_WEIGHT) {
				cargo->setWeight(sum);
				value = true;
			}
			else if (sum < MIN_WEIGHT && cargo->getWeight() != MIN_WEIGHT) {
				cargo->setWeight(MIN_WEIGHT);
				value = true;
			}
			else if (cargo->getWeight() == MIN_WEIGHT) {
				value = false;
			}
		}
					else {
			value = false;
					}	
		return value;
	};


	void Cargo::copyCargo(Cargo* both) { // pointing to elements of cargo
		setDescription(both->description);
		setWeight(both->weight);

	}


	bool Train::swapCargo(Train& t) {
		bool value;
		if (cargo != nullptr && t.cargo != nullptr) {
			Cargo temp;
		
			temp.copyCargo(cargo);
			cargo->copyCargo(t.cargo);
			t.cargo->copyCargo(&temp);
			value = true;
		}
		else {
			value = false;
		}
		return value;
	};

}