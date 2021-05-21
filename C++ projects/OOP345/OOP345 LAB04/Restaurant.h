#pragma once
//Name: Lara Fahmi
//Student Number: 109742197
#ifndef SDDS_RESTURANT_H
#define SDDS_RESTURANT_H
#include "Reservation.h"
using namespace std;
namespace sdds {

	class Restaurant{

		Reservation* reservation;
		int numOfreservations;


	public:

		Restaurant();
		Restaurant(Reservation** res, size_t cnt);
		Restaurant(const Restaurant&);
		Restaurant& operator=(const Restaurant&);
		Restaurant(Restaurant&&) noexcept;
		Restaurant& operator=(Restaurant&&) noexcept;
		~Restaurant();
		size_t size() const;
		ostream& display(ostream& os) const;
		void setEmpty();
	};

	std::ostream& operator<<(std::ostream&, const Restaurant&);
}


#endif
