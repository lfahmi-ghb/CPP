#pragma once

#ifndef SDDS_BASKET_H 
#define SDDS_BASKET_H
#include <iostream>

using namespace std;

namespace sdds {
	class Basket {
		char* m_fruitname;
		int m_qty;
		double m_price;

	public:
		Basket();
		~Basket();
		Basket(const char*, int, double);
		Basket(const Basket& src);
		void setEmpty();

		void setName(const char*);
		void setQty(int);
		void setPrice(double);
		bool isempty() const;
		bool addPrice(double);
		

		ostream& display(ostream& os) const;
		Basket& operator=(const Basket& other);
		bool operator==(const Basket&);
		bool operator!=(const Basket&);
	};

	ostream& operator<<(ostream& os, const Basket& bsk);
}
#endif