//Name: Lara Fahmi

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cctype>
#include <cstring>
#include <iomanip>
#include "ReadWritable.h"
using namespace std;

namespace sdds {
	ReadWritable::ReadWritable() {
		flag = false;
	}

	bool ReadWritable::isCsv() const {
		return flag;
	}

	void ReadWritable::setCsv(bool value) {
		flag = value;
		
	}

	ostream& operator<<(ostream& os, const ReadWritable& r) {
		r.write(os);
		return os;
	}
	istream& operator>>(istream& in,  ReadWritable& w) {
		w.read(in);
		return in;
	}


}