//Student Name: Lara Fahmi
//Student Number: 109742197

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstring>
#include "Saiyan.h"

namespace sdds {

	using namespace std;

	
	////////////////////////////Constructs///////////////////////////////////
	Saiyan::Saiyan() {
		m_name = nullptr;
		setEmpty();
	}

	Saiyan::Saiyan(const char* name, int dob, int power) {		//3 argument construct

		m_name = nullptr;
		set(name, dob, power);
		
	}

	Saiyan::~Saiyan() { //right
		delete[] m_name;
		m_name = nullptr;
	}

	//////////////////////Functions////////////////////////////
	void Saiyan::set(const char* name, int dob, int power, int level, bool super) {

		if (m_name) {
			delete[] m_name;
			m_name = nullptr;
		}

		if (name && name[0] != '\0' && dob < 2020 && power > 0 && level >= 0)
		{
			int size = strlen(name) + 1;
			m_name = new char[size];
			strcpy(m_name, name);
			m_power = power;
			m_dob = dob;
			m_super = super;
				if (super) {
			m_level = level;
				}
				else  m_level = 0;
		}
		else {
			this->setEmpty();
		}
	}

	void Saiyan::powerUp() {
		if (!isSuper()) {
			(m_power = m_power * (m_level + 1));
		}
	}

	bool Saiyan::hasLost(Saiyan& other) {
		bool value;
		if (isValid() && other.isValid()) {
			powerUp();
			other.powerUp();
			if (other.m_power > m_power) {
				value = true;
			}
			else {
				value = false;
			}
		}
		return value;

		
	}

	bool Saiyan::isSuper() const {
		bool value;
		if (m_super != false) {
			value = false;
		}
		else {
			value = true;
		}
		return value;
	};

	bool Saiyan::isValid()const {
		bool value = false;
		if (m_name&& m_name[0] != '\0' && !(m_dob == 0) && !(m_power == 0)) {
			value = true;
		}
		//else value = false;

		return value;
	}


	void Saiyan::setEmpty() {
		if (m_name) {
			delete[] m_name;
			m_name = nullptr;
		}
		m_dob = 0;
		m_power = 0;
		//m_name[0] = '\0';
		//m_name = nullptr;
		m_super = false;

	}


void Saiyan::display() const {
	if (isValid()) {
		cout << m_name << endl;
		cout << "DOB: " << m_dob << " " << "Power: " << m_power << endl;
		if (m_super) {
			cout << "Super Saiyan Ability: Super Saiyan." << endl;
			cout << "Super Saiyan level is: " << m_level << endl;
		}
		else {
			cout << "Super Saiyan Ability: Not super Saiyan." << endl << endl;
		}
	}
	else {
		//if (isValid()) {

		cout << "Invalid Saiyan!" << endl;

	}
}

/*////////////////set functions//////////////
void Saiyan::setName(const char* name) {
	if (m_name) {
		delete[] m_name;
		m_name = nullptr;
	}
	if (name && name[0] != '\0') {
		int size = strlen(name) + 1;
		m_name = new char[size];
		strcpy(m_name, name);
	}
	else
	{
		m_name = nullptr;

	}

}

void Saiyan::setDob(int dob) {
	if (dob > 2020) {
		m_dob = 0;
	}
	else {
		m_dob = dob;
	}
}
void Saiyan::setPower(int power) {
	if (power > 0) {
		m_power = power;
	}
	else {
		m_power = 0;
	}
}
void Saiyan::setLevel(int lvl) {
	if (lvl > 0) {
		m_level = lvl;
	}
	else {
		m_level = 0;
	}
}
*/
}