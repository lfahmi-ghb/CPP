#include "Autoshop.h"

namespace sdds {

    Autoshop& Autoshop::operator+=(Vehicle* theVehicle) {
       m_vehicles.push_back(theVehicle);
        return *this;
    }

    void Autoshop::display(ostream& os) const {
        os << "--------------------------------\n";
        os << "| Cars in the autoshop!        |\n";
        os << "--------------------------------\n";
        for //(int i = 0; i < m_vehicles.size(); i++) {
            (auto _vehicle : m_vehicles) {
            _vehicle->display(os);
            os << endl;
        }
        os << "--------------------------------\n";
    }

    Autoshop::~Autoshop() {
        for (auto& as_vehicle : m_vehicles) {
            delete as_vehicle;
        }
    }
}