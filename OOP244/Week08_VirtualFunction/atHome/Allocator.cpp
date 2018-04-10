// TODO: add file header comments here
/**********************************************************
// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: Allocator.cpp
// Name: Jihyun Yoon
// email: jyoon31@myseneca.ca
// Student#: 124558172
// Revision History
///////////////////////////////////////////////////////////
// Name			Date		                         Reason
// Jihyun        2018/04/01                       file made
///////////////////////////////////////////////////////////
**********************************************************/

#include "SavingsAccount.h" 
#include "ChequingAccount.h"

namespace sict {

	// define interest rate
	//
	const double intRate = 0.05;
	const double trans_fee = 0.50;
	const double monthly_fee = 2.00;

	// TODO: Allocator function
	//
	iAccount* CreateAccount(const char* type , double balance) {
		iAccount* account = nullptr;
		switch (type[0])
		{
		case 'S':
			account = new SavingsAccount(intRate, balance);
			break;
		case 'C':
			account = new ChequingAccount(balance, trans_fee, monthly_fee);
			break;
		default:
			break;
		}
		return account;
	}

	
}
