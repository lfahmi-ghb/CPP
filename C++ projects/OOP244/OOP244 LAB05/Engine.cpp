// Name: Lara Fahmi
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include "Engine.h"

using namespace std;
namespace sdds {
	/////////////////////constructs///////////////////
	Engine::Engine() {
		setEmpty();
	}

	Engine::Engine(const char* e_type, double e_size) {
		if (e_size > 0 || e_type[0] != '\0') {
			strcpy(type, e_type);
			size = e_size;
		}
		else {
			setEmpty();
		}
	}
	////////////////functions////////////////
	double Engine::get() const { return size; }

	void Engine::setEmpty() {
		size = 0;
		type[0] = '\0';
	}

	void Engine::display() const {
		if (size != 0 && type[0] != '\0') {
			cout << size << " liters" " - " << type << endl;
		}

	}

}