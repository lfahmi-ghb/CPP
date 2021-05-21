//Name: LARA FAHMI
//FINAL ADJUSTMENTS(MILESTONE 6)

#pragma once
#ifndef SDDS_MENU_H 
#define SDDS_MENU_H

#include <iostream>
#include <string>
using namespace std;

namespace sdds {
#define MAX_NO_OF_ITEMS 10


	class MenuItem
	{
		char* m_item;
		//constructors and copy assignments

		MenuItem();
		MenuItem(const char*);
		~MenuItem();
		MenuItem(MenuItem&) = delete;

		//operators
		MenuItem& operator=(const MenuItem& src);
		std::ostream& display(std::ostream& os) const;

		//void setItem(const char*);
		//void display();

		friend class Menu;
	};

	class Menu {
		char* m_title;
		int m_indentation;
		MenuItem* m_menuItems;
		int nextItem;

	public:
		//constructors and destructors
		Menu();
		Menu(const char*, int = 0);
		Menu(const Menu&);
		~Menu();


		void add(const char*);
		void display() const;
		int run() const;
		bool isEmpty() const;

		//additional functions
		void setEmpty();
		void setTitle(const char*);
		void indenting() const;

		//Operators
		Menu& operator=(const Menu&);
		Menu& operator=(const char*);
		Menu& operator<<(const char*);
		operator int() const;
		explicit operator bool() const;
	};
}

#endif

