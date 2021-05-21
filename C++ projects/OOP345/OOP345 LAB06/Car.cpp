#include <fstream>
#include <iomanip>
#include <iostream>
#include <cstring>
#include<vector>
#include<sstream>
#include <string>
#include<algorithm>

#include "Car.h"

namespace sdds
{


    //REMOVE THE SPACES
    string& removeSpaces(string& whole) {
        whole.erase(whole.find_last_not_of(' ') + 1);
        whole.erase(0, whole.find_first_not_of(' '));
        return whole;
    }


        //CONSTRUCTORS


    Car::Car(istream& in) {       

        // extract all the information
        string first;
        getline(in, first, ',');

        string temp_make;
        getline(in, temp_make, ',');
        removeSpaces(temp_make);

        string temp_condition;
        getline(in, temp_condition, ',');
        removeSpaces(temp_condition);

         {
                 if (temp_condition.empty())   { temp_condition = "new";}
                 if (temp_condition[0] == 'n') { temp_condition = "new";  }
            else if (temp_condition[0] == 'b') { temp_condition = "broken"; }
            else if (temp_condition[0] == 'u') { temp_condition = "used"; }
                 //generate an exception to inform the client that this record is invalid
            else {
                string err = "Invalid record!";
                throw err;
            }
        }

         string temp_speed;
         getline(in, temp_speed, ',');
         removeSpaces(temp_speed);

        //assign
        m_make = temp_make;
        m_condition = temp_condition;
        try {         
            stringstream ssh;
            ssh << temp_speed;
            ssh >> m_topSpeed;
            m_topSpeed = stod(temp_speed);
        }
          //generate an exception to inform the client that this record is invalid
        catch (exception& e) {
            string err = "Invalid record!";
            throw err;
        }
    }

    string Car::condition() const  {
        return  m_condition;
    }

    double Car::topSpeed() const {
        return m_topSpeed;
    }

    void Car::display(ostream& out) const {
        out << "| " << setw(10) << right << m_make << " | ";;
        out << setw(6) << left << condition() << " | ";
        out << setw(6) << fixed << setprecision(2) << topSpeed() << " |";
    }

}