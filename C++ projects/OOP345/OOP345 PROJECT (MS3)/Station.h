// Name: Lara Fahmi
// Seneca Student ID: 109742197
// Seneca email: lfahmi1@myseneca.ca
// Date of completion: Nov 14th, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#pragma once
#ifndef SDDS_STATION_H
#define SDDS_STATION_H
#include <iostream>
#include <iomanip>
#include <cstring>
#include<sstream>
#include <string>
#include <utility>
#include <stack>
#include<algorithm>
#include "Utilities.h"

class Station
{
	int st_id;
	std::string st_name;
	std::string st_description;
	int st_serialNum;
	//int st_nextSerialNum;
	int st_currentItems;
	//Static Data
	static size_t m_widthField;
	static int id_generator;

public:
	Station(const std::string&);
	void display(std::ostream& os, bool full) const;
	const std::string& getItemName() const;
	unsigned int getNextSerialNumber();
	unsigned int getQuantity() const;
	void updateQuantity();
	
};

#endif