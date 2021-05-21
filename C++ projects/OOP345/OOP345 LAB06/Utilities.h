//Name: Lara Fahmi
//Student Number: 109742197

#pragma once
#ifndef SDDS_UTILITY_H
#define SDDS_UTILITY_H
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
#include "Vehicle.h"
#include "Car.h"

namespace sdds {

	Vehicle* createInstance(std::istream& in);

}

#endif