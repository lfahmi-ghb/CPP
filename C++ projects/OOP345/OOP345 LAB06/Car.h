//Name: Lara Fahmi
//Student Number: 109742197

#pragma once
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
#include <exception>
#include "Vehicle.h"

using namespace std;

namespace sdds {

    class Car : public Vehicle {
        string m_make;
        string m_condition;
        //int m_topSpeed;
        double m_topSpeed;

    public:
     //   Car();
        Car(istream&);
        string condition() const;
        double topSpeed() const;
        void display(ostream& out) const;
    };

}