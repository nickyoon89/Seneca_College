// TODO: add file header comments here
/**********************************************************
// Workshop 3: Classes and Privacy
// Passenger.cpp
// Name: Jihyun Yoon
// email: jyoon31@myseneca.ca
// Student#: 124558172
// Revision History
///////////////////////////////////////////////////////////
// Name			Date		                         Reason
// Jihyun        2018/02/13                       file made
///////////////////////////////////////////////////////////
**********************************************************/

// TODO: add your headers here
#include "Passenger.h"
#include <cstring>
#include <iostream>
using namespace std;
// TODO: continue your namespace here
namespace sict {
	// TODO: implement the default constructor here
	Passenger::Passenger()
	{
		p_name[0] = '\0';
		p_dest[0] = '\0';
	}
	// TODO: implement the constructor with 2 parameters here
	Passenger::Passenger(const char* name, const char* dest)
	{
		if (name!=nullptr&&name[0]!='\0'&& dest!=nullptr&&dest!='\0') {
			strcpy(p_name, name);
			strcpy(p_dest, dest);
		}
		else {
			*this = Passenger();
		}
	}
	// TODO: implement isEmpty query here
	bool Passenger::isEmpty() const {
		if ((p_name == nullptr || p_name[0] == '\0')||(p_dest == nullptr || p_dest[0] == '\0')) {
			return true;
		}
		else {
			return false;
		}
	}
	// TODO: implement display query here
	void Passenger::display() const {
		if (isEmpty()) cout << "No passenger!" << std::endl;
		else cout << p_name << " - " << p_dest << endl;
	}
}