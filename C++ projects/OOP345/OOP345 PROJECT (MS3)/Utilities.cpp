// Name: Lara Fahmi
// Seneca Student ID: 109742197
// Seneca email: lfahmi1@myseneca.ca
// Date of completion: Nov 14th, 2020

#define _CRT_SECURE_NO_WARNINGS
#include "Utilities.h"

using namespace std;
char Utilities::m_delimiter = '\0';

void Utilities::setFieldWidth(size_t newWidth) {
	m_widthField = newWidth;
}

size_t Utilities::getFieldWidth() const {
	return m_widthField;
}


//This function uses the delimiter to extract the next token from str starting at next_pos.
std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {

	string temp = "";
	size_t pos = next_pos;

	next_pos = str.find(m_delimiter, pos);

	if (next_pos == string::npos) {
		temp = str.substr(pos);
		setFieldWidth(max(temp.length(), getFieldWidth()));
		more = false;
	}
	//If successful, it returns the extracted token found and sets more to true
	else if (next_pos >= pos) {
		temp = str.substr(pos, next_pos - pos);
		setFieldWidth(max(temp.length(), getFieldWidth()));
		//setFieldWidth( getFieldWidth());
		more = true;
		
	}
	//This function reports an exception if there are two delimiters with no token between them.
	else if (pos == next_pos) {
		more = false;
		throw "No token between delimiters!";
	}
	next_pos++;
	return temp;
}

void Utilities::setDelimiter(char newDelimiter) {
	m_delimiter = newDelimiter;
}

char Utilities::getDelimiter() {
	return m_delimiter;
}