//Name: Lara Fahmi
//Student Number: 109742197
#ifndef SDDS_RECCORDSET_H 
#define SDDS_RECORDDSET_H
#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <iomanip>
#include <iostream>
#include <cstring>
#include<vector>
#include<sstream>
#include <string>
#include<algorithm>
#include "Reservation.h"

using namespace std;
using namespace sdds;


Reservation::Reservation() : r_reservationName{}, r_email{}, r_numOfPeople{}, r_hour{}
{
	reservation_id[0] = '\0';
	r_day = 0;

}


string removeSpaces(string& s)
{
	s.erase(std::remove_if(s.begin(), s.end(), ::isspace), s.end());
	remove(s.begin(), s.end(), ' ');
	return s;
}


Reservation::Reservation(std::string& res) : whole{res} {
	vector<string> result;
	removeSpaces(res);
//	whole.erase(std::remove_if(whole.begin(), whole.end(), ::isspace), whole.end());
	//rest.erase(remove_if(res.begin(), res.end(), isspace), res.end());
	//std::string::iterator end_pos = std::remove(whole.begin(), whole.end(), ' ');
	//whole.erase(end_pos, whole.end());
	//std::cout << s;

	stringstream ss (res);
	getline(ss, reservation_id, ':');
	result.push_back(reservation_id);
	
	getline(ss, r_reservationName, ',');
	result.push_back(r_reservationName);


	getline(ss, r_email, ',');
	result.push_back(r_email);

	string temp_num;
	getline(ss, temp_num, ',');
	result.push_back(temp_num);
	stringstream ssn;
	ssn << temp_num;
	ssn >> r_numOfPeople;

	string temp_day;
	getline(ss, temp_day, ',');
	result.push_back(temp_day);
	stringstream ssd;
	ssd << temp_day;
	ssd >> r_day;

	string temp_hr;
	getline(ss, temp_hr, ',');
	result.push_back(temp_hr);
	stringstream ssh;
	ssh << temp_hr;
	ssh >> r_hour;
}

bool Reservation::isEmpty() const {
	if (whole.size() < 1)
		return true;
	else
		return false;
}

///******DISPLAY******/// 


ostream& Reservation::display(ostream& os) const {

	string formated_email = "<" + r_email + ">";



	if (r_hour >= 6 && r_hour <= 9) {

		os << "Reservation " << reservation_id << ": " << std::setw(10) << std::right << r_reservationName;
		os << "  " << std::left << setw(24) << formated_email << "Breakfast on day " << r_day << " @ " << r_hour << ":00 for " << r_numOfPeople << " people." << endl;
	}

	else if (r_hour >= 11 && r_hour <= 15) {
		os << "Reservation " << reservation_id << ": " << std::setw(10) << std::right << r_reservationName;
		os  << "  " << std::left << setw(24) << formated_email << "Lunch on day " << r_day << " @ " << r_hour << ":00 for " << r_numOfPeople << " people." << endl;
	
	}

	else if (r_hour >= 17 && r_hour <= 21) {
		os << "Reservation " << reservation_id << ": " << std::setw(10) << std::right << r_reservationName;
		os 	<< "  " << std::left << setw(24) << formated_email << "Dinner on day " << r_day << " @ " << r_hour << ":00 for " << r_numOfPeople << " people." << endl;
	}

	
	else {

		os << "Reservation " << reservation_id << ": " << std::setw(10) << std::right << r_reservationName;
		os << "  " << std::left << setw(24) << formated_email << "Drinks on day " << r_day << " @ " << r_hour << ":00 for " << r_numOfPeople << " people." << endl;

	}

	return os;
}


#endif

std::ostream& sdds::operator<<(std::ostream& os, Reservation const& r)
{
	// TODO: insert return statement here

	r.display(os);
	return os;
}
