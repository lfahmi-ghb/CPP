//Name: Lara Fahmi
//Student Number: 109742197
#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H
#include <fstream>
#include <iomanip>
#include <iostream>
#include <cstring>
#include<vector>
#include<sstream>
#include <string>
#include <utility>
#include <stack>
#include<algorithm>
#include <list>

#include "Vehicle.h"

using namespace std;

namespace sdds {
    class Autoshop {
        vector<Vehicle*> m_vehicles;

    public:
        ~Autoshop();

        Autoshop& operator+=(Vehicle*);

        void display(ostream&) const;

        template <typename T>

        void select(T test, list<const Vehicle*>& v) {
            for (auto& m_vehicles : m_vehicles) {
                //the first parameter (test) can be a lambda expression
                if (test(m_vehicles)) {
                    v.push_back(m_vehicles);
                }
            }
        }
    };
}
#endif
