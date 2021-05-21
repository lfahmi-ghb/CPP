#pragma once
//Name: Lara Fahmi
//Student Number: 109742197
#ifndef TIMEDEVENTS_H
#define TIMEDEVENTS_H
#include<chrono>
#include<string>
#include<iostream>

namespace sdds {

	class TimedEvents;
	std::ostream& operator << (std::ostream& os, TimedEvents const& events);
	const int MAX_RECORDS = 7;
	template<class Clock, class Duration = typename Clock::duration> class time_point;
	
	class TimedEvents {
	private:
		size_t counter;
		std::chrono::steady_clock::time_point e_start;
		std::chrono::steady_clock::time_point e_end;

		struct {
			std::string event;
			std::string unit;
			std::chrono::steady_clock::duration rec_duration{};
		}records[7];

	public:

		TimedEvents();
		void startClock();
		void stopClock();
		void recordEvent(char const*);
		friend std::ostream& sdds::operator << (std::ostream& os, TimedEvents const& events);
	};

}
#endif

