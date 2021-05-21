#include "Racecar.h"

namespace sdds
{

    Racecar::Racecar(istream& in) : Car(in) {
        in >> m_booster;
    }

    void Racecar::display(ostream& out) const
    {
        Car::display(out);
        out << "*";
    }

    double Racecar::topSpeed() const {
        auto speed = (Car::topSpeed() * (m_booster + 1));
        return speed;
    }
} 