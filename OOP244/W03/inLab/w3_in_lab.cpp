/**********************************************************
// Workshop 3: Classes and Privacy
// w3_in_lab.cpp
// Name: Jihyun Yoon
// email: jyoon31@myseneca.ca
// Student#: 124558172
// Revision History
///////////////////////////////////////////////////////////
// Name			Date		                         Reason
// Jihyun        2018/02/06                        file made
///////////////////////////////////////////////////////////
**********************************************************/

#include <iostream>
#include "CRA_Account.h"

using namespace std;
using namespace sict;

int main() {
	const int size = 1000;
	char familyName[size];
	char givenName[size];
	sict::CRA_Account myCRA;
	int sin;
	bool quit = false;
	if (sict::max_name_length + 1 > size) {
		cerr << "Increase size to value greater than " 
			<< sict::max_name_length + 1 << endl;
		return 1;
	}

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
