//Name: LARA FAHMI
//FINAL ADJUSTMENTS(MILESTONE 6)

#pragma once
#ifndef SDDS_READWRITABLE_H 
#define SDDS_READWRITABLE_H
#include <iostream>

using namespace std;

namespace sdds {

	class ReadWritable {
		bool flag;

	public:

		ReadWritable();
		virtual ~ReadWritable() {};
		bool isCsv() const;
		void setCsv(bool value);
		virtual std::ostream& write(std::ostream& ostr = std::cout)const = 0;
		virtual std::istream& read(std::istream& istr = std::cin) = 0;
	};

	ostream& operator<<(ostream& os, const ReadWritable& r);
	istream& operator>>(istream& in, ReadWritable& w);
}
#endif
