/**********************************************************
// Workshop 3: Classes and Privacy
// CRA_Account.cpp
// Name: Jihyun Yoon
// email: jyoon31@myseneca.ca
// Student#: 124558172
// Revision History
///////////////////////////////////////////////////////////
// Name			Date		                         Reason
// Jihyun        2018/02/06                        file made
///////////////////////////////////////////////////////////
**********************************************************/

#include "CRA_Account.h"
#include <cstring>
#include <iostream>

namespace sict {
	char _familyName[max_name_length] = "";
	char _givenName[max_name_length] = "";
	int _sin = -1;
	void CRA_Account::set(const char* familyName, const char* givenName, int sin)
	{
		if (sin>max_sin||sin<min_sin)
		{
			_sin = -1;
			return;
		}
		else {
			_sin = sin;
		}
		strncpy(_familyName, familyName, max_name_length + 1);
		strncpy(_givenName, givenName, max_name_length + 1);
	}
	bool CRA_Account::isEmpty() const {
		if (_sin == -1) return true;
		else return false;
	}
	void CRA_Account::display() const{
		std::cout << "Family Name: " << _familyName << std::endl;
		std::cout << "Given Name : " << _givenName << std::endl;
		std::cout << "CRA Account: " << _sin << std::endl;
	}
}