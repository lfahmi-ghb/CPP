//Name: Lara Fahmi
//Student Number: 109742197
#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <iomanip>
#include <iostream>
#include <cstring>
#include<vector>
#include<sstream>
#include <string>
#include <utility>
#include <stack>
#include"ConfirmationSender.h"

using namespace std;
using namespace sdds;


ConfirmationSender::ConfirmationSender()
	: confReservation{ nullptr }
	, conNumOfreservations{ 0 }
{


}


void ConfirmationSender::setEmpty() {
	conNumOfreservations = 0;
	confReservation = nullptr;
}

///*****COPYING****////

ConfirmationSender::ConfirmationSender(const ConfirmationSender& cpy)
{
	conNumOfreservations = cpy.conNumOfreservations;
	confReservation = new const Reservation * [cpy.conNumOfreservations];
	for (auto i = 0u; i <cpy.conNumOfreservations; i++) {
		confReservation[i] = cpy.confReservation[i];
	}

}


ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& other) {
		if (this != &other) {
			delete[] confReservation;
			confReservation = nullptr;
			conNumOfreservations = 0;

			conNumOfreservations= other.conNumOfreservations;
			confReservation = new const Reservation * [other.conNumOfreservations];
			
			for( auto i = 0u; i < other.conNumOfreservations; i++)
				confReservation[i] = other.confReservation[i];
		}
		return *this;
	}


///*****MOVING****////
ConfirmationSender::ConfirmationSender(ConfirmationSender&& other) noexcept {
		*this = std::move(other);
	}


ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& other) noexcept {
		if (this != &other) {

			confReservation = other.confReservation;
			conNumOfreservations = other.conNumOfreservations;

			other.confReservation = { nullptr };
			other.conNumOfreservations= { 0 };
		}
		return *this;
	}


ConfirmationSender::~ConfirmationSender(){
		delete[] confReservation;
		confReservation =  nullptr;
	}

///****OPERATORS*****////

ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) {
		bool found = false;
		
		for (auto i = 0u; i < conNumOfreservations; i++) {
			found = confReservation[i] == &res;
		}

		if (!found) {
			const Reservation** temp = nullptr;
			temp = new const Reservation * [conNumOfreservations + 1];
			for (auto i = 0u; i < conNumOfreservations; i++) {
				temp[i] = confReservation[i];
			}
			temp[conNumOfreservations] = &res;
			conNumOfreservations++;
			delete[] confReservation;
			confReservation = temp;
		}
		return *this;
	}


	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) {
		bool found = true;
		size_t idx;

		for (auto i = 0u; i < conNumOfreservations; i++) {
			found = confReservation[i] == &res;
			idx = i;
		}
		if (found) {
		
			auto temp = confReservation;
			confReservation = new Reservation const*[conNumOfreservations - 1];
			for (auto x = 0u; x < idx; ++x) {
					confReservation[x] = temp[x];
			}

			conNumOfreservations--;
			delete[] temp;
			temp = nullptr;
	}
		return *this;
	}
	
	///******DISPLAY******/// 

	void ConfirmationSender::display(std::ostream& os) const {

		if (conNumOfreservations > 0) {

			os << "--------------------------" << endl;
			os << "Confirmations to Send" << endl;
			os << "--------------------------" << endl;

			for (auto i = 0u; i < conNumOfreservations; i++) {
				//os << confReservation[i];
				(*confReservation[i]).display(os);
			}

			os << "--------------------------" << endl;
		}
		else {

			os << "--------------------------" << endl;
			os << "Confirmations to Send" << endl;
			os << "--------------------------" << endl;
			os << "The object is empty!" << endl;
			os << "--------------------------" << endl;

		}
		//return os;

	}

	std::ostream& sdds::operator<<(std::ostream& os, ConfirmationSender& conf)
	{
		conf.display(os);
		return os;
	}

	size_t ConfirmationSender::size() const {
		return conNumOfreservations;
	}




///////////////////////*
