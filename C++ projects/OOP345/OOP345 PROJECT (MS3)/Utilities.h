// Name: Lara Fahmi
// Seneca Student ID: 109742197
// Seneca email: lfahmi1@myseneca.ca
// Date of completion: Nov 14th, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#pragma once
#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
#include <iostream>
#include <iomanip>
#include <cstring>
#include<sstream>
#include <string>
#include <utility>
#include <stack>
#include<algorithm>

class Utilities
{
	size_t m_widthField = 1;
	static char m_delimiter;

public:
	void setFieldWidth(size_t newWidth);
	size_t getFieldWidth() const;
	std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
	static void setDelimiter(char newDelimiter);
	static char getDelimiter();
};

#endif