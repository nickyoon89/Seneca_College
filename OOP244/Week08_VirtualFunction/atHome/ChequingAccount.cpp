// TODO: add file header comments here
/**********************************************************
// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: ChequingAccount.cpp
// Name: Jihyun Yoon
// email: jyoon31@myseneca.ca
// Student#: 124558172
// Revision History
///////////////////////////////////////////////////////////
// Name			Date		                         Reason
// Jihyun        2018/04/01                       file made
///////////////////////////////////////////////////////////
**********************************************************/

#include "ChequingAccount.h"

using namespace std;

namespace sict {
	// constructor initializes balance and transaction fee
	//
	ChequingAccount::ChequingAccount(double balance, double trans_fee, double monEnd_fee) : Account(balance){
		if (trans_fee > 0) {
			_trans_fee = trans_fee;
		}
		else _trans_fee = 0.0;
		if (monEnd_fee > 0) {
			_monEnd_fee = monEnd_fee;
		}
		else {
			_monEnd_fee = 0.0;
		}
	}


	// credit (add) an amount to the account balance and charge fee
	// returns bool indicating whether money was credited
	//
	bool ChequingAccount::credit(double balance) {
		if (Account::credit(balance)) {
			Account::debit(_trans_fee);
			return true;
		}
		else return false;
	}



	// debit (subtract) an amount from the account balance and charge fee
	// returns bool indicating whether money was debited
	//
	bool ChequingAccount::debit(double balance) {
		if (Account::debit(balance)) {
			Account::debit(_trans_fee);
			return true;
		}
		else return false;
	}


	// monthEnd debits month end fee
	//
	void ChequingAccount::monthEnd() {
		debit(_monEnd_fee);
	}


	// display inserts account information into ostream os
	//
	void ChequingAccount::display(std::ostream& os) const {
		os << "Account type: Chequing" << std::endl;
		os.setf(os.fixed, os.floatfield);
		os.precision(2);
		os << "Balance: $" << Account::balance() << std::endl;
		os << "Per Transaction Fee: " << _trans_fee << std::endl;
		os << "Monthly Fee: " << _monEnd_fee << std::endl;
	}



}