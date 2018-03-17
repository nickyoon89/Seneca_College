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

namespace sict {
	bool CRA_Account::check_sin(int sin) {
		int sinNum[8];
		int sum = 0;
		int alt = 0;
		bool returnVal;
		for (int i = 0; i < 8; i++)
		{
			if (i % 2 == 0) {
				sinNum[i] = sin / pow(10, 8 - i);
				alt += sinNum[i];
			}
			else {
				sinNum[i] = (sin / pow(10, 8 - i));
				sum += ((sinNum[i] * 2) / 10 + (sinNum[i] * 2) % 10);
			}
			sin -= (sinNum[i] * pow(10, 8 - i));
		}
		
		returnVal = ((sum + alt + sin) % 10 == 0);
		return returnVal;
	}

	void CRA_Account::set(int year, double balance) {
		if (check_sin(_sin))
		{
			if (count_year < max_yrs) {
					tax_year[count_year] = year;
					tax_balance[count_year] = balance;
					count_year++;
				}
		}
	}
	void CRA_Account::set(const char* familyName, const char* givenName, int sin)
	{
		if (sin > max_sin || sin < min_sin || familyName[0] == '\0' || givenName[0] == '\0') {
			_sin = -1;
			return;
		}
		else {
			if (check_sin(sin)) {
				_sin = sin;
				strncpy(_familyName, familyName, max_name_length - 1);
				strncpy(_givenName, givenName, max_name_length - 1);
				for (int i = 0; i < max_yrs; i++)
				{
					count_year = 0;
					tax_year[i] = 0;
					tax_balance[i] = 0;
				}
			}
		}
	}
	bool CRA_Account::isEmpty() const {
		if (_sin == -1) return true;
		else return false;
	}
	void CRA_Account::display() const{
		std::cout << "Family Name: " << _familyName << std::endl;
		std::cout << "Given Name : " << _givenName << std::endl;
		std::cout << "CRA Account: " << _sin << std::endl;
		for (int i = 0; i < max_yrs; i++)
		{
			if (tax_year[i] == 0) {
				if(i==0) std::cout << "Account object is empty!" << std::endl;
				break;
			}
			else{
				if (tax_balance[i] > 2) {
					std::cout << "Year (" << tax_year[i] << ") balance owing: " << std::fixed << std::setprecision(2) << tax_balance[i] << std::endl;
				}
				else if (tax_balance[i] < -2) {
					std::cout << "Year (" << tax_year[i] << ") refund due: " << std::fixed << std::setprecision(2) << -tax_balance[i] << std::endl;
				}
				else {
					std::cout << "Year (" << tax_year[i] << ") No balance owing or refund due!" << std::endl;
				}
					
			}
		}
	}
}