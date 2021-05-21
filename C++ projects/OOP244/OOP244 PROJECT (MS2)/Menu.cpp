//Name: Lara Fahmi

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cctype>
#include <cstring>
#include <iomanip>
#include "Menu.h"
using namespace std;
namespace sdds {

	/*******************MENUITEMS******************/


	MenuItem::MenuItem() {
		m_item = nullptr;
	}

	MenuItem::MenuItem(const char* item) {

		if (item != nullptr) {
			m_item = new char[strlen(item) + 1];
			strcpy(m_item, item);
		}
		else item = nullptr;
	}

	MenuItem::~MenuItem() {

		delete[] m_item;
		m_item = nullptr;

	}

	std::ostream& MenuItem::display(std::ostream& os) const {
		if (m_item != nullptr) {
			os << m_item << endl;
		}
		return os;
	}

	MenuItem& MenuItem::operator=(const MenuItem& other) {
		if (this != &other) {

			delete[] m_item;
			if (other.m_item != nullptr) {
				m_item = new char[strlen(other.m_item) + 1];
				strcpy(m_item, other.m_item);
			}
			else {
				m_item = nullptr;
			}
		}
		return *this;
	}

	/*******************MENUITEMS END******************/


	/**********************MENU***********************/

	void Menu::setEmpty() {
		m_title = nullptr;
		m_indentation = 0;
		m_menuItems = nullptr;
		m_menuItems = new MenuItem[MAX_NO_OF_ITEMS];
	}

	Menu::Menu() {
		setEmpty();
	}

	Menu::Menu(const char* title, int indentation) {
		m_title = nullptr;
		if (title[0] != '\0' && indentation >= 0 && title != nullptr) {
			setTitle(title);
			m_menuItems = new MenuItem[MAX_NO_OF_ITEMS];
			m_indentation = indentation;
		}
		else setEmpty();

	}


	Menu::~Menu() {
		delete[] m_title;
		m_title = nullptr;

		delete[] m_menuItems;
		m_menuItems = nullptr;
	}

	Menu::Menu(const Menu& other) {
		m_title = nullptr;
		m_indentation = 0;
		m_menuItems = new MenuItem[MAX_NO_OF_ITEMS];
		//return *this
		*this = other;
	}

	Menu& Menu::operator=(const Menu& other) {
		if (this != &other) {
			if (*this) {
				delete[] m_title;
				m_title = nullptr;
				delete[] m_menuItems;
				m_menuItems = nullptr;
				setEmpty();
			}
			if (other) {
				if (other.m_title[0] != '\0' && other.m_title != nullptr && other.m_indentation >= 0) {
					setTitle(other.m_title);
					m_indentation = other.m_indentation;
					for (int i = 0; i < MAX_NO_OF_ITEMS; i++) {
						m_menuItems[i] = other.m_menuItems[i];
					}
				}
			}
		}
		return *this;
	}

	Menu& Menu::operator=(const char* newTitle) {
		if (newTitle[0] != '\0') {
			delete[] m_title;
			m_title = nullptr;
			setTitle(newTitle);
		}
		else {
			if (*this) {
				delete[] m_title;
				m_title = nullptr;
				delete[] m_menuItems;
				m_menuItems = nullptr;
				setEmpty();
			}

		}
		return *this;
	}


	void Menu::setTitle(const char* title) {
		if (title != nullptr && title[0] != '\0') {
			m_title = new char[strlen(title) + 1];
			strcpy(m_title, title);
		}
		else m_title = nullptr;
	}

	bool Menu::isEmpty() const {
		return !(*this);
	}


	Menu::operator bool() const {
		return m_title != nullptr;
	}

	Menu::operator int() const {
		return run();
	}



	void Menu::indenting() const {
		for (int i = 0; i < m_indentation; i++) {
			cout << "    ";
		}
	}

	void Menu::display() const {
		if (isEmpty()) {
			cout << "Invalid Menu!" << endl;
		}
		else {
			//cout << "    ";
			indenting();
			cout << m_title << endl;
			if (m_menuItems[0].m_item == nullptr) {
				cout << "No Items to display!" << endl;
			}
			else {
				for (int i = 0; i < MAX_NO_OF_ITEMS; i++) {
					if (m_menuItems[i].m_item == nullptr) {
						break;
					}
					//cout << "    ";
					indenting();
					cout << i + 1 << "- " << m_menuItems[i].m_item << endl;
				}
				//cout << "    ";
				indenting();
				cout << "> ";

			}
		}

	}


	void Menu::add(const char* other) {
		if (*this && other != nullptr) {
			if (other != nullptr) {
				for (int i = 0; i < MAX_NO_OF_ITEMS; i++) {
					if (this->m_menuItems[i].m_item == nullptr) {
						m_menuItems[i] = MenuItem(other);
						break; //break when added
					}
				}
			}
		}
		else {
			delete[] m_title;
			m_title = nullptr;
			delete[] m_menuItems;
			m_menuItems = nullptr;
			setEmpty();

		}
	}


	Menu& Menu::operator<<(const char* newTitle) {
		this->add(newTitle);
		return *this;
	}
	/*
	void Menu::counter() {
	int count = 0;
		for (int i = 0; i < MAX_NO_OF_ITEMS; i++) {
			if (MenuItems[i].item != nullptr) {
				++count;
			}
		}
	}
	*/
	int Menu::run() const {
		char selection = '0';
		int count = 0;
		bool flag = true;

		//counter();
		for (int i = 0; i < MAX_NO_OF_ITEMS; i++) {
			if (m_menuItems[i].m_item != nullptr) {
				++count;
			}
		}
		display();
		//while (flag = true && numberOfMenuItems < MAX_NO_OF_ITEMS) {
		while (flag && count) {
			cin >> selection;
			cin.ignore(10000, '\n');
			if (!isdigit(selection)) {
				cout << "Invalid Integer, try again: ";
			}
			else if ((int)selection - 48 <= 0 || (int)selection - 48 > count) {
				cout << "Invalid selection, try again: ";
				//cin.clear();
				//cin.ignore(10000, '\n');
			}
			else  flag = false;
		}
		return (int)selection - 48;
	}

}

/*
int Menu::run() const {
	int selection = 0; //initialize
	bool  = display();
	int count = 0;

	for (int i = 0; i < MAX_NO_OF_ITEMS; i++) //COUNT ITEMS
	{
		if (m_menuItems[i].m_item != nullptr) {
			++count;
		}
	}

	display();
	do
	{
		cin >> choice;
		cin.ignore(10000, '\n');
		if (!isdigit(selection))
		{
			cout << "Invalid Integer, try again: ";
					cin.clear();
					cin.ignore(10000, '\n');
		}
		else if ((int)selection  > numberOfMenuItems || (int)selection <= 0)\\????????????
		{
			cout << "Invalid selection, try again: ";
					cin.clear();
					cin.ignore(10000, '\n');
		} while(value && numberOfMenuItems)
		else
		{
			value = false;
		}

	}

	return (int) selection ;

}*/
