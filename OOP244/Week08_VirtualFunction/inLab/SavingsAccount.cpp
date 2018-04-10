#include <iomanip>
#include "SavingsAccount.h"

namespace sict {
	// TODO: constructor initializes balance and interest rate
	SavingsAccount::SavingsAccount(double intRate, double balance): Account::Account(balance) {
		if (intRate > 0) {
			_intRate = intRate;
		}
		else _intRate = 0.0;
	}

	// TODO: perform month end transactions
	void SavingsAccount::monthEnd() {
		Account::credit(Account::balance()*_intRate);
	}

	// TODO: display inserts the account information into an ostream			
	void SavingsAccount::display(std::ostream& os) const {
		os << "Account type: Savings" << std::endl;
		os.setf(os.fixed, os.floatfield);
		os.precision(2);
		os << "Balance: $" << Account::balance() << std::endl;
		os << "Interest Rate (%): " << _intRate * 100 << std::endl;
	}

}