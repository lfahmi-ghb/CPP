#pragma once
//Name: Lara Fahmi
//Student Number: 109742197
#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H

#include <vector>
using namespace std;
namespace sdds {

	class Reservation {
		string whole;
		string reservation_id;
		string r_reservationName;
		string r_email;
		int r_numOfPeople;
		int r_day;
		int r_hour;

	public:
		Reservation();
		Reservation(std::string& res);
		ostream& display(ostream& os) const;
		bool isEmpty() const;
		
	};
	std::ostream& operator << (std::ostream& os, Reservation const& r);

}
#endif
