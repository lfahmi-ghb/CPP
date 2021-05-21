//Name: Lara Fahmi
//Student Number: 109742197
#define _CRT_SECURE_NO_WARNINGS
#include "Utilities.h"
#include "Station.h"
#include "LineManager.h"

using namespace std;
LineManager::LineManager(const std::string& filename, std::vector<Workstation*>& workstation, std::vector<CustomerOrder>& customerOrder) 
	:m_cntCustomerOrder((unsigned)customerOrder.size() )
{
	Utilities utility;
	size_t pos = 0;
	bool more = true;

	string line;
	string firstStation;
	string secondStation;
	std::ifstream file(filename);
	//read the records from file and setup all the m_pNextStation references in the Workstation objects, linking each Workstation object together to form the assembly line
	while (!file.eof()) {
		getline(file, line);
			firstStation = utility.extractToken(line, pos, more);

			for (size_t i = 0u; i < workstation.size(); i++) {
				if (firstStation == workstation[i]->getItemName()) {
					if (more) {
						secondStation = utility.extractToken(line, pos, more);
						
						for (size_t j = 0u; j < workstation.size(); j++) {
							if (secondStation == workstation[j]->getItemName()) {
								workstation[i]->setNextStation(*workstation[j]);
							}
						}
					}
				}
			}
	}	//the while loop ends here
	

	//Copy all the Workstation objects into the AssemblyLine container

	for (std::size_t i = 0; i < workstation.size(); ++i) {
		AssemblyLine.push_back(workstation[i]);
	}

	AssemblyLine = workstation;

	//Move all the CustomerOrder objects onto the back of the ToBeFilled queue
	for (std::size_t i = 0; i < customerOrder.size(); ++i) {
		ToBeFilled.push_back(std::move(customerOrder[i]));
	}
	
	
}

bool LineManager::run(std::ostream& os) {
	static size_t counter = 0;
	//how many times this function has been called by the client; use only local variables to count
	os << "Line Manager Iteration: " << ++counter << std::endl;


	//f there are any CustomerOrder objects in the ToBeFilled queue
	if (!ToBeFilled.empty()) {
		int startPoint = 1;
		for (unsigned int i = 0; i < AssemblyLine.size(); ++i) {
		//for (auto&& i : AssemblyLine) {
			startPoint = i;
			for (unsigned int j = 0; j < AssemblyLine.size(); ++j) {

				if (AssemblyLine[j]->getNextStation()
					&& AssemblyLine[i]->getItemName().compare(AssemblyLine[j]->getNextStation()->getItemName()) == 0) {
					startPoint = 0;
				}
			}
			if (startPoint != 0) {
				break;
			}
		}
		//move the one at the "front" of the queue onto the starting point 
		*AssemblyLine[startPoint] += std::move(ToBeFilled.front());
		ToBeFilled.pop_front();
	}
	//Loop through all stations on the assembly line and run one cycle of the station's process
	for (auto&& i : AssemblyLine) {
		i->runProcess(os);
	}

	//Loop through all stations on the assembly line and move the CustomerOrder objects down the line.
	for (std::size_t i = 0; i < AssemblyLine.size(); ++i) {
		if (AssemblyLine[i]->getNextStation() == nullptr) {
			CustomerOrder tmp;
			//completed orders should be moved into the Completed queue.
			if (AssemblyLine[i]->getIfCompleted(tmp)) {
				Completed.push_back(std::move(tmp));
			}
		}
		else {
			AssemblyLine[i]->moveOrder();
		}
	}
	//return true if all customer orders have been filled
	return(Completed.size() == m_cntCustomerOrder);
	
}



void LineManager::displayCompletedOrders(std::ostream& os) const {
	for (std::size_t i = 0; i < Completed.size(); ++i) {
		Completed[i].display(os);
	}
}

void LineManager::displayStations() const {
	for (std::size_t i = 0; i < AssemblyLine.size(); ++i) {
		AssemblyLine[i]->display(std::cout);
	}
}

void LineManager::displayStationsSorted() const {

	//you have to identify which station is the starting point of your assembly line
	int m_startPoint = 1;
	for (std::size_t i = 0; i < AssemblyLine.size(); ++i) {
		m_startPoint = i;
		for (std::size_t j = 0; j < AssemblyLine.size(); ++j) {
			if (AssemblyLine[j]->getNextStation() != nullptr && AssemblyLine[i]->getItemName().compare(AssemblyLine[j]->getNextStation()->getItemName()) == 0) {
				m_startPoint = 0;
			}
		}
		if (m_startPoint != 0) { break; }
	}
	const Workstation* start = AssemblyLine[m_startPoint];
	while (start != nullptr) {
		start->display(std::cout);
		start = start->getNextStation();
	}
}