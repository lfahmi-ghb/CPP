//Name: Lara Fahmi
//Student Number: 109742197
#ifndef SDDS_TIMEDEVENTS_H 
#define SDDS_TIMEDEVENTS_H
#define _CRT_SECURE_NO_WARNINGS
#include "TimedEvents.h"
#include<iomanip>
#include <iostream>
#include <fstream>

using namespace std;

//************CONSTRUCTION****************
sdds::TimedEvents::TimedEvents() :counter{}, e_start{}, e_end{}, records{} {


}
//*************START AND END*********************
void sdds::TimedEvents::startClock(){
    e_start = std::chrono::steady_clock::now();
}

void sdds::TimedEvents::stopClock(){
    e_end = std::chrono::steady_clock::now();
}


//***************RECORDING********************
void sdds::TimedEvents::recordEvent(char const* name)
{
    if (counter >= std::size(records)) {
        return;
    }
    if (counter < std::size(records)) {
        records[counter].event = name;
        records[counter].unit = "nanoseconds";
        records[counter].rec_duration = std::chrono::duration_cast<std::chrono::nanoseconds>(e_end - e_start);
        ++counter;
    }
}

//**********DISPLAY*******************
std::ostream& sdds::operator<<(std::ostream& os, TimedEvents const& events)
{
    os << "--------------------------"<< std::endl;
    os << "Execution Times:" << std::endl;
    os << "--------------------------"<<std::endl;
    for (size_t i = 0; i < events.counter; ++i) {
        os << std::setw(20) << std::left;
        os << events.records[i].event;
        os << " " << std::setw(12) << std::right;
        os << events.records[i].rec_duration.count() << " ";
        os << events.records[i].unit << "\n";

    }
    os << "--------------------------\n";
    return os;
}

#endif