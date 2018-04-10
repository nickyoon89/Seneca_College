#include "SavingsAccount.h" 

namespace sict {

	// define interest rate
	//
	const double intRate = 0.05;

	// TODO: Allocator function
	//
	iAccount* CreateAccount(const char* type , double balance) {
		iAccount* account = nullptr;
		if (type[0] == 'S') {
			account = new SavingsAccount(intRate, balance);
		}
		return account;
	}

	
}
