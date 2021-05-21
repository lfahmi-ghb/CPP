//Name: Lara Fahmi
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<iomanip>
#include "Basket.h"

using namespace std;
namespace sdds {
	
	Basket::Basket() {
		setEmpty();
	}

	Basket::Basket(const char* name, int qty, double prc) {
		setEmpty();
		if (name != nullptr && name[0] != '\0' && qty > 0 && prc > 0) {
			setName(name);
			setQty(qty);
			setPrice(prc);
		}
	else
		*this = Basket();
	}


	Basket::~Basket() {
		delete[] m_fruitname;
		m_fruitname = nullptr;
	}


	Basket::Basket(const Basket& cpy) {
		setQty(cpy.m_qty);
		setPrice(cpy.m_price) ;

		if (cpy.m_fruitname != nullptr && cpy.m_fruitname[0] != '\0') {
			m_fruitname = new char[strlen(cpy.m_fruitname) + 1];
			setName(cpy.m_fruitname);
		}

		else	m_fruitname = nullptr;
	}

	
	void Basket::setName(const char* name) {
		delete[] m_fruitname;
		//if (name && name[0] != '\0') 
		if (name != nullptr && name[0] != '\0') {
			m_fruitname = new char[strlen(name) + 1];
			strcpy(m_fruitname, name);
		}
		else m_fruitname = nullptr;
	}


	void Basket::setQty(int qty) {
		if (qty > 0) {
			m_qty = qty;
		}
		else m_qty = 0;
	}

	void Basket::setPrice(double prc) {
		if (prc > 0) {
			m_price = prc;
		}
		else m_price = 0;
	}

	void Basket::setEmpty() {
		m_fruitname = nullptr;
		m_qty = 0;
		m_price = 0;

	}

	bool Basket::isempty() const {
		bool value;
		if (m_fruitname == nullptr && m_qty == 0 && m_price == 0) {
			value = true;
		}
		else {
			value = false;
		}
		return value;
	}

	bool Basket::addPrice(double p) {
		bool value = true;
		if (!isempty()) {
			double sum = m_price + p;
			if (sum > 0) {
					setPrice(sum);
					value = true;
			}

		}
		return value;
	}

	ostream& Basket::display(ostream& os) const {
		os << fixed << std::setprecision(2);

		if (isempty()) {
			os << "The Basket has not yet been filled" << endl;
		}
		else {
			os << "Basket Details" << endl;
			os << "Name: " << m_fruitname << endl;
			os << "Quantity: " << m_qty << endl;
			os << "Price: " << m_price << endl;
		}
		return os;

	}


	Basket& Basket::operator=(const Basket& other) {
		if (this != &other) {

			setQty(other.m_qty);
			setPrice(other.m_price);
			delete[] m_fruitname;
			if (other.m_fruitname != nullptr) {
				m_fruitname = new char[strlen(other.m_fruitname) + 1];

				setName(other.m_fruitname);
			}
			else {
				m_fruitname = nullptr;
			}
		}
		return *this;
	}

	bool Basket::operator==(const Basket& other) {
		if (isempty()) {
			return false;
		}
		return (strcmp(m_fruitname, other.m_fruitname) == 0 && other.m_qty == m_qty && other.m_price == m_price);

	}

	bool Basket::operator!=(const Basket& other) {

		if (strcmp(m_fruitname, other.m_fruitname) == 1 || other.m_qty != m_qty || other.m_price != m_price)
			return true;
		else
			return false;

	}

	ostream& operator<<(ostream& os, const Basket& bsk) {
		bsk.display(os);
		return os;
	}


}