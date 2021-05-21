//Name: Lara Fahmi
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<iomanip>
#include "Engine.h"
#include"Ship.h"


using namespace std;
namespace sdds {
	/////////////////////constructs///////////////////
	Ship::Ship() {
		engine = nullptr;
		shipType = nullptr;		
		engNum = 0;

	}

	Ship::~Ship() {
		delete[] shipType;
		shipType = nullptr;
		delete[] engine;
		engine = nullptr;
	}


	Ship::Ship(const char* type, Engine* e, int length)
	{
		shipType = nullptr;
		set(type, e, length);
	}
	////////////////functions////////////////
	void Ship::set(const char* type, Engine* e, int s)
	{

		if (type && type[0] != '\0' && s > 0)
		{
			int size = strlen(type) + 1;			
			shipType = new char[size];
			strcpy(shipType, type);
			
			engNum = s;
			engine = new Engine[engNum];
			for (int i = 0; i < engNum; i++)
			{

				engine[i] = e[i];
			}
		}
		else
		{
			setEmpty();

		}
	}


	void Ship::setEmpty() {
		engNum = 0;
		shipType[0] = '\0';
		engine = nullptr;
}

	bool Ship::empty() const {
		bool value;
		if (shipType[0] == '\0' && engNum == 0) {
			value = true;
		}
		else {
			value = false;
		}
		return value;
	}


	float Ship::calculatePower() const {
		float sum = 0;
		for (int i = 0; i < engNum; i++) {
			sum += (float)engine[i].get();
		}
		return (float)sum * 5;

	}


	void Ship::display() const
	{
		cout << fixed << std::setprecision(2);
		

		if (shipType == nullptr)	{
			cout << "No available data" << endl;
		}
		else
		{
			cout << shipType << '-';
			cout.width(6);
			cout << calculatePower() << endl;
			for (int i = 0; i < engNum; i++)
			{
				engine[i].display();
			}
		}
	}

	Ship& Ship::operator+=(Engine newEng) {
		
		if (engNum != 0 && engNum < 10) {
			Engine* newEngine = new Engine[engNum];
			for (int i = 0; i < engNum; i++) {	
				newEngine[i] = engine[i];
			}
			delete[] engine;
			engine = nullptr;

			engine = new Engine[engNum + 1];
			
			for (int i = 0; i < engNum; i++) {
				engine[i] = newEngine[i];
			}
			delete[] newEngine;
			newEngine = nullptr;

			engine[engNum] = newEng;
			engNum++;

		}
		else {
			cout << "The ship doesn't have a type! Engine cannot be added!" << endl;

		}
		return *this;
	}



	bool operator==(const Ship& one, const Ship& other) {
		if (one.calculatePower() == other.calculatePower()) {
			return true;
		}
		else {
			return false;
		}

	}
	bool operator<(const Ship& ship, double val) {
		if (ship.calculatePower() < val) {
			return true;
		}
		else {
			return false;
		}

	}


}