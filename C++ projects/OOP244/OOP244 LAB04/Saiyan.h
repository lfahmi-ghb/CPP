//Student Name: Lara Fahmi
//Student Number: 109742197
#pragma once
#ifndef SDDS_SAIYAN_H
#define SDDS_SAIYAN_H

namespace sdds {


	class Saiyan {
		char* m_name;
		int m_dob;
		int m_power;
		int m_level;
		bool m_super;
		//char* ptr = nullptr;
	public:
		~Saiyan();
		Saiyan();
		Saiyan(const char* name, int dob, int power);
		bool isSuper() const;
		bool isValid()const;
		void setEmpty();
		void display() const; 
		void set(const char* name, int dob, int power, int level = 0, bool super = false);
		bool hasLost(Saiyan& other) ;
		void powerUp();

		//set functions
		//void setLevel(int lvl);
		//void setName(const char* name);
		//void setDob(int dob);
		//void setPower(int power);
		

	};
	}

#endif 
