/**********************************************************
// Workshop 3: Classes and Privacy
// CRA_Account.h
// Name: Jihyun Yoon
// email: jyoon31@myseneca.ca
// Student#: 124558172
// Revision History
///////////////////////////////////////////////////////////
// Name			Date		                         Reason
// Jihyun        2018/02/06                        file made
///////////////////////////////////////////////////////////
**********************************************************/

#ifndef CRA_ACCOUNT_H
#define CRA_ACCOUNT_H

#include <iomanip>
#include <cstring>
#include <iostream>
#include <math.h>

namespace sict {
	const int max_name_length = 40;
	const int min_sin = 100000000;
	const int max_sin = 999999999;
	const int max_yrs = 4;

	class CRA_Account
	{
		int tax_year[max_yrs];
		double tax_balance[max_yrs];
		int count_year;
		char _familyName[max_name_length];
		char _givenName[max_name_length];
		int _sin;
	public:
		bool check_sin(int sin);
		void set(int year, double balance);
		void set(const char* familyName, const char* givenName, int sin);
		bool isEmpty() const;
		void display() const;
	};
}
#endif // !CRA_ACCOUNT_H
