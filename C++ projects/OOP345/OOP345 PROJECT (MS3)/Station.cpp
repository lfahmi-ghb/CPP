// Name: Lara Fahmi
// Seneca Student ID: 109742197
// Seneca email: lfahmi1@myseneca.ca
// Date of completion: Nov 14th, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#define _CRT_SECURE_NO_WARNINGS
#include "Station.h"

using namespace std;

size_t Station::m_widthField = 0;
int Station::id_generator = 0;

Station::Station(const std::string& str) {
	Utilities ut;
	size_t next_pos = 0;
	bool more = true;
	
	    st_id = ++id_generator;
		st_name = ut.extractToken(str, next_pos, more);
		st_serialNum = stoi(ut.extractToken(str, next_pos, more));
		st_currentItems = stoi(ut.extractToken(str, next_pos, more));
		m_widthField = max(ut.getFieldWidth(), m_widthField);
		//st_description = str;
		st_description = ut.extractToken(str, next_pos, more);

}

const std::string& Station::getItemName() const {
	return st_name;
}

unsigned int Station::getNextSerialNumber() {
	return st_serialNum++;
}

unsigned int Station::getQuantity() const {
	return st_currentItems;
}

void Station::updateQuantity()
{

	if (st_currentItems < 0) {
		st_currentItems = 0;
	}
	else {
		st_currentItems--;
	}
}

void Station::display(std::ostream& os, bool full) const
{
	os << "[" << right << setw(3) << setfill('0') << st_id << setfill(' ') << "]";
	os << " Item: " << left << setw(m_widthField) << getItemName() << " ";
	os << "[" << right << setw(6) << setfill('0') << st_serialNum << setfill(' ') << "]";
	if (full) {
		os << " Quantity: " << setw(m_widthField);
		os << left << st_currentItems << " Description: " << st_description;
	}
	os << endl;
}