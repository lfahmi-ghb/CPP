//Name: Lara Fahmi
//Student Number: 109742197
#define _CRT_SECURE_NO_WARNINGS
#include "Utilities.h"
#include "Station.h"
#include "Workstation.h"

using namespace std;


//***** CONSTRUCTING *****//
Workstation::Workstation(const std::string& str) : Station(str) {}

void Workstation::runProcess(std::ostream& os) {
	if (!m_orders.empty()) {
		// this function fills the order in the "front" at the current Workstation
		m_orders.front().fillItem(*this, os);
	}
}



//****Other Member Functions****//

bool Workstation::moveOrder() {
	//if the order at the front of the queue doesn't require service at the current station
	if (!m_orders.empty() && m_orders.front().isItemFilled(getItemName()) == true) {
	//move it to the next station on the assembly line and return true
		*m_pNextStation += std::move(m_orders.front());
		m_orders.pop_front();
		return true;
	}
	else  return false;
	
}

void Workstation::setNextStation(Workstation& station){
	m_pNextStation = &station;
}

const Workstation* Workstation::getNextStation() const
{
	return m_pNextStation;
}

bool Workstation::getIfCompleted(CustomerOrder& order) {
	//if the order at the front of the queue is completed
	if (!m_orders.empty() && m_orders.front().isOrderFilled()){
		order = move(m_orders.front());
		m_orders.pop_front();
		return true;
	}

	else return false;
	
}

void Workstation::display(std::ostream& os) const {
	if (m_pNextStation)
		os << getItemName() << " --> " << m_pNextStation->getItemName() << endl;

	else
		os << getItemName() << " --> END OF LINE" << endl;
}


//moves the parameter onto the back of the CustomerOrder queue.
Workstation& Workstation::operator+=(CustomerOrder&& ord) {
	m_orders.push_back(move(ord));
	return *this;
}