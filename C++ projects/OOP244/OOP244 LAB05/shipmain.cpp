
// OOP244 Workshop 5: Operator Overloading
// File: mainTester.cpp
// Version: 1.0
// Date: 2/2/2020
// Author: Elnaz Delpisheh
// Description:
// This file tests lab section of your workshp
/////////////////////////////////////////////
#include <iostream>
#include "Ship.h"
#include "Engine.h"
using namespace std;
using namespace sdds;
int const MIN = 90;

int main()
{
	Engine engines[3] =
	{ Engine("V8",6.0),
	Engine("V8",8.0),
	Engine("Inline",4.2) };
	Engine engines2[4] =
	{ Engine("D3",7.0),
	Engine("D0",2.0),
	Engine("D1",3.2) };

	Ship titanic("liner", engines, 3);

	Ship rainbow;

	cout << "Testing Ship objects" << endl;
	titanic.display();
	cout << endl;
	rainbow.display();
	cout << endl;
	Ship aurora("apollo", engines2, 3);

	aurora.display();

	cout << endl << endl;

	//Adding an engine to the ship
	cout << "Adding an engine to Titanic" << endl;
	Engine engine = Engine("V10", 3.0);
	titanic += engine;
	titanic.display();

	cout << endl << endl;

	cout << "Adding an engine to Rainbow" << endl;

	Engine engine2 = Engine("V20", 40.0);
	rainbow += engine2;
	rainbow.display();

	cout << endl << endl;

	cout << "Adding an engine to Aurora" << endl;

	aurora += engine2;
	aurora.display();

	cout << endl << endl;
	//Comparing with the standards:
	cout << "Comparing Titanic with the standards:" << endl;
	if (titanic < MIN)
		cout << "Below average!" << endl;
	else
		cout << "Above average!" << endl;
	cout << endl << endl;
	cout << "Comparing the power of Titanic and Aurora:" << endl;
	if (titanic == aurora)
		cout << "The ships have the same power!" << endl;
	else
		cout << "The ships have different power!" << endl;
	return 0;
}