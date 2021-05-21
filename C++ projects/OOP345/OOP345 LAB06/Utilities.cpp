#define _CRT_SECURE_NO_WARNINGS
#include "Utilities.h"
#include "Racecar.h"

namespace sdds
{
    //REMOVE THE SPACES
    string& removeSpace(string& whole) {
        whole.erase(whole.find_last_not_of(' ') + 1);
        whole.erase(0, whole.find_first_not_of(' '));
        return whole;
    }

    Vehicle* createInstance(istream& is) {
        stringstream s;
        string type;
        getline(is, type, '\n');
        s << type;
        removeSpace(type);
        //str = the first letter before ','      
        type = type.substr(0, type.find(','));
        //getline(is, str, ',');
       /* string temp;
        getline(is, temp, ',');
        removeSpaces(temp);
        */
        if (type.empty()) {
            return nullptr;
        }

    if (type[0] != '\0' && (type[0] == 'c' || type[0] == 'C' || type[0] == 'r' || type[0] == 'R')) {
        if (type[0] == 'C' || type[0] == 'c')
        {
            Car* c = nullptr;
            c = new Car(s);
            return c;
        }
        else if (type[0] == 'R' || type[0] == 'r')
        {
            Racecar* rc = nullptr;
            rc = new Racecar(s);
            return rc;
        }
        else
        {
            return nullptr;
        }
      /*  switch (type[0]) {
        case 'C':
            return new Car(s);
        case 'c':
            return new Car(s);

        case 'R':
            return new Racecar(s);
        case 'r':          
            return new Racecar(s);

        default: 
            return nullptr;
        }*/
       }

        else {
            throw type[0];
        }
    }
}