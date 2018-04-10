// TODO: add file header comments here
/**********************************************************
// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: Account.cpp
// Name: Jihyun Yoon
// email: jyoon31@myseneca.ca
// Student#: 124558172
// Revision History
///////////////////////////////////////////////////////////
// Name			Date		                         Reason
// Jihyun        2018/04/01                       file made
///////////////////////////////////////////////////////////
**********************************************************/

#include "Account.h"

namespace sict {

	double Account::balance() const {
		return _balance;
	}

	// TODO: constructor initializes account balance, defaults to 0.0 
	Account::Account(double balance = 0.0) {
		if (balance > 0) {
			_balance = balance;
		}
		else {
			_balance = 0.0;
		}
	}

	// TODO: credit adds +ve amount to the balance 
	bool Account::credit(double balance) {
		if (balance > 0) {
			_balance += balance;
			return true;
		}
		else return false;
	}

	// TODO: debit subtracts a +ve amount from the balance
	bool Account::debit(double balance) {
		if (balance > 0) {
			_balance -= balance;
			return true;
		}
		else return false;
	}


}
