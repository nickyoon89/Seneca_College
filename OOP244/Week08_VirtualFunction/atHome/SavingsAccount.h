// TODO: add file header comments here
/**********************************************************
// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: SavingsAccount.h
// Name: Jihyun Yoon
// email: jyoon31@myseneca.ca
// Student#: 124558172
// Revision History
///////////////////////////////////////////////////////////
// Name			Date		                         Reason
// Jihyun        2018/04/01                       file made
///////////////////////////////////////////////////////////
**********************************************************/

#ifndef SICT_SAVINGSACCOUNT_H__
#define SICT_SAVINGSACCOUNT_H__

#include "Account.h"

namespace sict {
	class SavingsAccount: public Account{
		double _intRate;
	
	public:
		// TODO: constructor initializes balance and interest rate
		SavingsAccount(double, double);

		// TODO: perform month end transactions
		void monthEnd();

		// TODO: display inserts the account information into an ostream			
		void display(std::ostream&) const;
	};
}
#endif
