//Name: Lara Fahmi
#pragma once
#ifndef SDDS_ENGINE_H 
#define SDDS_ENGINE_H

using namespace std;

namespace sdds {
#define MAX_TYPE 30

	class Engine {
		double size;
		char type[MAX_TYPE + 1];

	public:
		double get() const;
		void display() const;
		void setEmpty();
		Engine();
		Engine(const char*, double);

	};
}

#endif