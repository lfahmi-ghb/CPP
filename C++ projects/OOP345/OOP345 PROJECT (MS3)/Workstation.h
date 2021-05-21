//Name: Lara Fahmi
//Student Number: 109742197
#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H
#include <iomanip>
#include <iostream>
#include <cstring>
#include <string>
#include <utility>
#include <stack>
#include<algorithm>
#include <numeric>
#include <functional>
#include <list>
#include <iostream>
#include <deque>
#include <string>
#include "Station.h"
#include "CustomerOrder.h"
class Workstation : public Station {
	std::deque<CustomerOrder> m_orders;
	Workstation* m_pNextStation = nullptr;

public:
	//***** CONSTRUCTING *****//
	Workstation(const std::string&);

	//***** COPYING *****//
	Workstation(const Workstation& cpy) = delete;
	Workstation& operator=(const Workstation& other) = delete;

	//***** MOVING*****//
	Workstation(Workstation&& cpy) noexcept = delete;
	Workstation& operator=(Workstation&& cpy) noexcept = delete;

	//****Other Member Functions****//
	void runProcess(std::ostream&);
	bool moveOrder();
	void setNextStation(Workstation& station);
	const Workstation* getNextStation() const;
	bool getIfCompleted(CustomerOrder& order);
	void display(std::ostream&) const;
	Workstation& operator+=(CustomerOrder&&);
};

#endif

