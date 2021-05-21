#pragma once
#pragma once
//Name: Lara Fahmi
//Student Number: 109742197
#ifndef SDDS_CONFORMATIONSENDER_H
#define SDDS_CONFORMATIONSENDER_H

#include <iostream>
#include "Reservation.h"


namespace sdds {
	class ConfirmationSender : public Reservation {
		const sdds::Reservation** confReservation;
		unsigned int conNumOfreservations;
	public:
		ConfirmationSender();
		ConfirmationSender(const ConfirmationSender&);
		ConfirmationSender& operator=(const ConfirmationSender&);
		ConfirmationSender(ConfirmationSender&&) noexcept;
		ConfirmationSender& operator=(ConfirmationSender&&)noexcept;
		~ConfirmationSender();
		
		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);
		size_t size() const;

		void display(std::ostream& os) const;	
		void setEmpty();
	};
	std::ostream& operator<<(std::ostream&,  ConfirmationSender&);

}
#endif