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
#include "Car.h"

namespace sdds
{
    class Racecar : public Car
    {
        double m_booster;

    public:
        Racecar(istream& in);
        void display(ostream& out) const;
        double topSpeed() const;
    };
} 

