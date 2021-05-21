//Name: Lara Fahmi
//Student Number: 109742197
#ifndef SDDS_RECCORDSET_H 
#define SDDS_RECORDDSET_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include "RecordSet.h"

using namespace std;
using namespace sdds;


//*** CONSTRUCTING AND DESTRUCTING ****

sdds::RecordSet::RecordSet(){
	rec_str = nullptr;
	counter = 0;
}

sdds::RecordSet::RecordSet(char const* name)
{
	std::ifstream file(name);
	if (name == nullptr && !file) {
		rec_str = nullptr;
		counter = 0;
	}

	else {
		int white;
		//std::string buff = {};
		counter = 0;
		if (file.is_open()) {
			//while (white=std::getline(file, buffer)) {
			while ((white=file.get()) != EOF) {
				if(white==' ')				
					++counter;
			}
		}
		++counter;

		//clean
		file.clear();
		//next string
		file.seekg(std::ios::beg);
		rec_str = new std::string[counter];
		for (size_t i = 0; i < counter; ++i) {
			std::getline(file, rec_str[i], ' ');
		}

	}

}

RecordSet::~RecordSet() {
	delete[] rec_str;
	rec_str = nullptr;
	counter = 0;
}


	//********COPYING**********


sdds::RecordSet::RecordSet(RecordSet const& cpy){

	counter = cpy.counter;
	rec_str = new string[cpy.counter];
	for (size_t i = 0; i < counter; ++i) {
		rec_str[i] = cpy.rec_str[i];
	}
	
}

RecordSet const& RecordSet::operator=(RecordSet const& cpy){
	if (this != &cpy) {

		delete[] rec_str;
		rec_str = nullptr;
		counter = 0;

		counter = cpy.counter;
		rec_str = new std::string[cpy.counter];
		for (size_t i = 0; i < counter; ++i) {
			rec_str[i] = cpy.rec_str[i];
		}
	}
	return *this;
}



//************MOVING****************

//"This kind of function may not throw. Declare it 'noexcept'."
RecordSet::RecordSet(RecordSet&& cpy) noexcept :rec_str{ cpy.rec_str }, counter{ cpy.counter } {
	cpy.rec_str = nullptr;
	cpy.counter = 0;

}


sdds::RecordSet const& sdds::RecordSet::operator=(RecordSet&& cpy) noexcept {
	if (this != &cpy) {
		counter = cpy.counter;
		cpy.counter = 0;
		rec_str = cpy.rec_str;
		cpy.rec_str = nullptr;
		//delete[]m_records;
	}
	return *this;
}



//*******RECORDS SIZE**********

size_t RecordSet::size() const {
	return counter;
}

string RecordSet::getRecord(size_t size) const {
	if (size < counter) {
		return  rec_str[size];
	}
	return "";
}

#endif