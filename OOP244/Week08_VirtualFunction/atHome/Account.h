// TODO: add file header comments here
/**********************************************************
// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: Account.h
// Name: Jihyun Yoon
// email: jyoon31@myseneca.ca
// Student#: 124558172
// Revision History
///////////////////////////////////////////////////////////
// Name			Date		                         Reason
// Jihyun        2018/04/01                       file made
///////////////////////////////////////////////////////////
**********************************************************/

#ifndef SICT_ACCOUNT_H__
#define SICT_ACCOUNT_H__

#include "iAccount.h"

namespace sict {
   
	class Account : public iAccount {
		double _balance;

	protected:
		double balance() const;

	public:
		// TODO: constructor initializes account balance, defaults to 0.0 
		Account(double);

		// TODO: credit adds +ve amount to the balance 
		bool credit(double);

		// TODO: debit subtracts a +ve amount from the balance
		bool debit(double);
	};


}
#endif
