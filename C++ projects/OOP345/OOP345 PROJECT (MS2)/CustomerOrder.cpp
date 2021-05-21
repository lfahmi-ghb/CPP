//Name: Lara Fahmi
//Student Number: 109742197

#define _CRT_SECURE_NO_WARNINGS
#include "Utilities.h"
#include "Station.h"
#include "CustomerOrder.h"

using namespace std;
//using namespace sdds;
size_t CustomerOrder::m_widthField = 0;


/******* CONSTRUCTION ******/
CustomerOrder::CustomerOrder(): m_name{nullptr}, m_product{nullptr}, m_cntItem{0}, m_lstItem{nullptr}
{

}

CustomerOrder::CustomerOrder(const std::string& str) {
	Utilities  ut;
	size_t next_pos = 0;
	bool more = true;

		m_name = ut.extractToken(str, next_pos, more);
		m_product = ut.extractToken(str, next_pos, more);
		m_cntItem = std::count(str.begin(), str.end(), ut.getDelimiter());
		m_lstItem = new Item* [m_cntItem];
		
		for (size_t i = 0; i < m_cntItem; i++) {
			m_lstItem[i] = new Item(ut.extractToken(str, next_pos, more));
		}
		// if the value stored there is smaller than the value stored then:
		m_widthField = max(ut.getFieldWidth(), m_widthField);
	//	m_lstItem.pop_back();
		--m_cntItem;
}

/******* COPY ******/
CustomerOrder::CustomerOrder(const CustomerOrder& cpy) {
	throw "ERROR: Cannot make copies.";
};

/***** MOVING *******/
CustomerOrder::CustomerOrder(CustomerOrder&& cpy) noexcept {
	m_lstItem = nullptr;
	*this = std::move(cpy);

	//a.m_lstItem = nullptr;
	/*m_name = a.m_name;
	m_product = a.m_product;
	m_cntItem = a.m_cntItem;

	m_lstItem = a.m_lstItem;
	a.m_lstItem = nullptr;
	*/

}

CustomerOrder& CustomerOrder::operator=(CustomerOrder&& cpy) noexcept {

	if (m_lstItem != nullptr) {
		for (unsigned int i = 0; i < m_cntItem; i++)
		{
			delete m_lstItem[i];
		}
	}

	if (&cpy != this) {

		delete[] m_lstItem;

		m_name = cpy.m_name;
		cpy.m_name = "";

		m_product = cpy.m_product;
		cpy.m_product = "";

		m_cntItem = cpy.m_cntItem;
		cpy.m_cntItem = 0;

		m_lstItem = cpy.m_lstItem;
		cpy.m_lstItem = nullptr;
	}

	return *this;
}



CustomerOrder::~CustomerOrder() {
	//for (auto& i : m_lstItem) {
	for (size_t i = 0; i < m_cntItem; i++) {
		delete m_lstItem[i];
	}
	delete[] m_lstItem;
	
};


/******* MEMBER FUNCTIONS ******/
bool CustomerOrder::isOrderFilled() const {
	bool flag = true;
	for (unsigned int i = 0; i < m_cntItem; i++) {
		if (!m_lstItem[i]->m_isFilled) {
			flag = false;
		}
	}
	return flag;
}

bool CustomerOrder::isItemFilled(const std::string& itemName) const {
	bool flag = true;
	for (unsigned int i = 0; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_itemName.compare(itemName) == 0) {
			flag = true;
		}
	}
	return flag;
}

void CustomerOrder::fillItem(Station& station, std::ostream& os) {
	for (size_t i = 0; i < m_cntItem; i++) {
		if (station.getItemName() == m_lstItem[i]->m_itemName) {
			auto itemLst  = m_lstItem[i];
			if (station.getQuantity() > 0){
				station.getQuantity();
				station.updateQuantity();
				itemLst->m_serialNumber = station.getNextSerialNumber();
				itemLst->m_isFilled = true;
				os  << "    Filled " << m_name << ", " 
					<< m_product 
					<< " [" << itemLst->m_itemName << "]" << endl;
			}
		
			else {
				os << "    Unable to fill " << m_name 
				   << ", " << m_product 
				   << " [" << itemLst->m_itemName << "]" << endl;
			}
		}
	}
	
}

void CustomerOrder::display(std::ostream& os) const {
	std::string state;
	os << m_name << " - " << m_product << endl;
	for (size_t i = 0; i < m_cntItem; ++i) {
			
		os << "[" << setfill('0') << right << setw(6) << m_lstItem[i]->m_serialNumber << "]" ;

		os << " " << setfill(' ') << left << setw(m_widthField) << m_lstItem[i]->m_itemName << " - ";
		
		if (m_lstItem[i]->m_isFilled) { state = "FILLED"; }
		else { state = "MISSING"; }
				
		os << state << endl;
	}
}