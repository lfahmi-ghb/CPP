//Name: Lara Fahmi
//Student Number: 109742197

#ifndef SDDS_CUSTOMERORDER_H
#define SDDS_CUSTOMERORDER_H
#include <iostream>

struct Item
{
	std::string m_itemName;
	unsigned int m_serialNumber = 0;
	bool m_isFilled = false;

	Item(const std::string& src) : m_itemName(src) {};
};

class CustomerOrder
{
	std::string m_name;
	std::string m_product;
	unsigned int m_cntItem;
	Item** m_lstItem;
	static size_t m_widthField;

public:
	//constructor//
	CustomerOrder();
	CustomerOrder(const std::string&);
	~CustomerOrder();

	//copying//
	CustomerOrder(const CustomerOrder& cpy);
	CustomerOrder& operator=(const CustomerOrder& other) = delete;


	//moving//
	CustomerOrder(CustomerOrder&& cpy) noexcept;
	CustomerOrder& operator=(CustomerOrder&& cpy) noexcept;

	bool isOrderFilled() const;
	bool isItemFilled(const std::string& itemName) const;
	void fillItem(Station& station, std::ostream& os);
	void display(std::ostream& os) const;
};
#endif