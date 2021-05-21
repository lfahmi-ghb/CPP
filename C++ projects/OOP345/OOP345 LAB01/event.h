#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <iomanip>
using namespace std;

extern  unsigned long g_sysClock;

namespace sdds {

	class Event {
		char* description;
		unsigned long time;

	public:
		Event();

		~Event();

		Event& operator=(const Event arg);

		Event(const Event& cpy);

		void setEmpty();

		bool isempty() const;

		void display() const;

		void setDescription(const char* des);

	};

}
