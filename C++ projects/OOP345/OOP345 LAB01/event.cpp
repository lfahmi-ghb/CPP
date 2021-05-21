//Name : Lara Fahmi

#ifndef SDDS_EVENT_H 
#define SDDS_EVENT_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "event.h"

unsigned long g_sysClock = 0;

using namespace std;
using namespace sdds;


Event::Event() {
	description = nullptr;
	setEmpty();
};
	
Event::~Event() {
	delete[] description;
	description = nullptr;
}


Event& Event::operator=(const Event arg) {
	if (this != &arg) {
		time = arg.time;
		if (arg.description != nullptr) {

			int size = strlen(arg.description) + 1;
			description = new char[size];
			strcpy(description, arg.description);

		}
		else {
			description = nullptr;
			time = 0;
		}
	}
	return *this;
}

Event::Event(const Event& cpy) {
	if (cpy.description != nullptr && cpy.description[0] != '\0') {
		time = cpy.time;
		int size = strlen(cpy.description) + 1;
		description = new char[size];
		strcpy(description, cpy.description);
	}
	else {
		description = nullptr;
		time = 0;
	}
}



void Event::setDescription(const char* des) {
	//if (description[0] = '\0') {
	if (description) {
		delete[] description;
		description = nullptr;
	}
	if (des && des[0] != '\0') {
		int size = strlen(des) + 1;
		description = new char[size];
		strcpy(description, des);
		time = g_sysClock;

	}
	else {
		this->setEmpty();
	}

};

bool Event::isempty() const {
	return !description;
};

void Event::display() const {
	static unsigned int counter = 0;
	counter++;
	cout << setw(3) << counter << ". ";
	if (isempty()) {
		cout << "[ No Event ]" << endl;
		//}
	}
	else {

		int hr = time / 3600;
		int min = time % 3600 / 60;
		int sc = time % 60;

		cout << setw(2) << setfill('0') << hr << ":" << setw(2) << min << ":" << setw(2) << sc << " -> " << description << endl;
		cout << setfill(' ');

	}

};

void Event::setEmpty() {

	delete[] description;
	description = nullptr;
	time = 0;
}

#endif
