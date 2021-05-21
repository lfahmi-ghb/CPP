#pragma once

#ifndef SDDS_NUMBERSBOX_H 
#define SDDS_NUMBERSBOX_H


#include <iostream>
#include<cstring>
#include<iomanip>

using namespace std;

namespace sdds {

	template<class T>
	class NumbersBox {
		//MEMBER FUNCTIONS
		char name[15];
		int size;
		T* items;

	public:
		NumbersBox(int n_size, const char* n_name) {

			if (n_size > 0 && n_name != nullptr) {
				strcpy(name, n_name);
				size = n_size;
				items = new T[n_size];
			}
			else {
				*this = NumbersBox();
			}

		}

		NumbersBox()
		{
			name[0] = '\0';
			size = 0;
			items = nullptr;
		};



		~NumbersBox() {
			if (items != nullptr)
				delete[] items;
		}

		//	OPERATOR # 1
		T& operator[](int i) {
			return items[i];
		};


		//	OPERATOR # 2
		NumbersBox<T>& operator*=(const NumbersBox<T>& other) {
			if (size == other.size) {
				for (int i = 0; i < size; i++) {
					items[i] *= other.items[i];
				}
			}
			return *this;
		}

		//	OPERATOR # 3

		NumbersBox<T>& operator+=(T num) {
			T* temp = new T[size + 1]; //new temp var
			temp[size] = num; //assign it

			if (size > 1 && name != nullptr) {   //validate
				for (int i = 0; i < this->size; i++) {  //loop
					temp[i] = items[i]; 
				}
				delete[] items;  //deallocate
				items = temp;    
			}
			size++; //add
			return *this;
		}


		//other member functions
		//template <class T>
		ostream& display(ostream& os) const {
			if ((name == nullptr || name[0] == '\0') || size < 1) {
				os << "Empty Box\n";
			}
			else {
				os << "Box name: " << name << '\n';
				//os << items[0];
				for (int i = 0; i < size; i++) {
					os << items[i];
					if(i + 1 < size)
						os << ", ";
				}
				os << '\n';
			}
			return os;
		}

	};



	//OUTSIDE FRIEND OPERATOR
	template <class T>
	ostream& operator <<(ostream& os, NumbersBox<T>& box) {
		box.display(os);
		return os;
	}

}

#endif
