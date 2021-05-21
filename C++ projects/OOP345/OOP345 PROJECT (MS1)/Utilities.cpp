// Name: Lara Fahmi
// Seneca Student ID: 109742197
// Seneca email: lfahmi1@myseneca.ca
// Date of completion: Nov 14th, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

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
	size_t beginPos = next_pos;
	next_pos = str.find(getDelimiter(), beginPos);
	temp = str.substr(beginPos);

	if (next_pos >= beginPos) {
		temp = str.substr(beginPos, next_pos - beginPos);
		setFieldWidth(max(temp.length(), getFieldWidth()));
		//setFieldWidth( getFieldWidth());
		more = true;
	}
	else if (beginPos == next_pos){
		throw "No token between delimiters!";
		more = false;
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