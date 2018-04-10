// TODO: add file header comments here
/**********************************************************
// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: ChequingAccount.h
// Name: Jihyun Yoon
// email: jyoon31@myseneca.ca
// Student#: 124558172
// Revision History
///////////////////////////////////////////////////////////
// Name			Date		                         Reason
// Jihyun        2018/04/01                       file made
///////////////////////////////////////////////////////////
**********************************************************/

#ifndef SICT_CHEQUINGACCOUNT_H__
#define SICT_CHEQUINGACCOUNT_H__

#include "Account.h"

namespace sict {
	class ChequingAccount : public Account{
		double _trans_fee;
		double _monEnd_fee;


		public:
			// TODO: constructor initializes account balance and transaction fee
			ChequingAccount(double, double, double);

			// TODDO: credit adds +ve amount to the balance
			bool credit(double);

			// TODO: debit subtracts a +ve amount from the balance
			bool debit(double);

			// TODO: month end
			void monthEnd();

			// TODO: display inserts the account information into an ostream
			void display(std::ostream&) const;

	};
}
#endif
