/**********************************************************
// Workshop 3: Classes and Privacy
// w3_in_lab.cpp
// Version 2.0
// 2017/09/09
// Chris Szalwinski
// Description
// This workshop demonstrates classes in C++ and 
// how member variables are defined privately, but 
// accessed through public member functions
//
// Revision History
///////////////////////////////////////////////////////////
// Name			Date		                         Reason
///////////////////////////////////////////////////////////
**********************************************************/

#include <iostream>
#include "CRA_Account.h"

using namespace std;
using namespace sict;

int main()
{
	sict::CRA_Account myCRA;
	int sin;
	bool quit = false;
	char familyName[sict::max_name_length + 1];
	char givenName[sict::max_name_length + 1];

	cout << "Canada Revenue Agency Account App" << endl
		 << "=================================" << endl << endl;
	cout << "Please enter your family name: ";
	cin >> familyName;
	cin.ignore();
	cout << "Please enter your given name: ";
	cin >> givenName;
	cin.ignore();

	do {
		cout << "Please enter your social insurance number (0 to quit): ";
		cin >> sin;
		cin.ignore();
		if (sin != 0)
		{
			myCRA.set(familyName, givenName, sin);
			if (myCRA.isEmpty()) {
				cout << "Invalid input! Try again." << endl;
			}
			else {
				quit = true;
			}
		}
		else {
			quit = true;
		}
	} while (!quit);
	cout << "----------------------------------------" << endl;
	cout << "Testing the display function" << endl;
	cout << "----------------------------------------" << endl;
	myCRA.display();
	cout << "----------------------------------------" << endl;
	
	return 0;
}
