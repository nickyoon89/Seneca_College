// Final Project Milestone 1 - Date Module Tester
// Version 3.3
// ms1_tester.cpp
// Date	2018-03-10
// Author	Chris Szalwinski, Fardad Soleimanloo
// Description
// This program test the student implementation of the Date class
// for submission.
//
// For you final test before submission:
//      DO NOT MODIFY THIS FILE IN ANY WAY
//
//
// Revision History
// --------------------------------------------------------------
// Name               Date                 Reason
// CS                 2017-10-11           Fall semester upgrade
// CS                 2018-03-02           Final Draft 20181
// CS                 2018-03-10           entered -> accepted
/////////////////////////////////////////////////////////////////
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include "Date.h"

using namespace std;
using namespace AMA;

bool equalDates(const char* A, const char* B);
bool yes();

int main() {
	int ret = 0;
	bool ok = true;

	if (ok) {
		cout << "Checking defined and constant values: " << endl;
	}
	if (ok && min_year != 2000) {
		cout << "Minimum year must be 2000" << endl;
		ok = false;
	}
	if (ok && max_year != 2030) {
		cout << "Maximum year must be 2030" << endl;
		ok = false;
	}
	if (ok) {
		cout << "Passed!" << endl;
		cout << "Checking define values for error code in Data.h" << endl;
	}
	if (ok && NO_ERROR != 0) {
		cout << "NO_ERROR must be 0" << endl;
		ok = false;
	}
	if (ok && CIN_FAILED != 1) {
		cout << "CIN_FAILED must be 1" << endl;
		ok = false;
	}
	if (ok && YEAR_ERROR != 2) {
		cout << "YEAR_ERROR must be 2" << endl;
		ok = false;
	}
	if (ok && MON_ERROR != 3) {
		cout << "MON_ERROR must be 3" << endl;
		ok = false;
	}
	if (ok && DAY_ERROR != 4) {
		cout << "DAY_ERROR must be 4" << endl;
		ok = false;
	}
	if (ok) {
		cout << "Passed!" << endl;
	}

	if (ok) {
		cout << "Testing the Date() constructor and the operator << overload; " << endl;
		Date Empty, Temp(-1, 1, 1);
		cout << "Are these two dates the same? (regardless of format)" << endl
			<< "1- " << Empty << endl
			<< "2- " << Temp << endl
			<< "(y)es/(n)o: ";

		if (!yes()) {
			cout << "Either the Date() constructor or the operator << overload is not implemented correctly." << endl;
			ok = false;
		}
		else {
			cout << "Passed!" << endl;
		}
	}
	if (ok) {
		Date A(2018, 10, 18);
		Date B = A;
		cout << "Testing Date(int, int, int) constructor and operator>> overload; " << endl;
		cout << "Enter the following date, 2018/10/18" << endl << ">";;
		cin >> B;

		if (!equalDates((const char*)&A, (const char*)&B)) {
			cout << "Either the constructor or operator>> is not implemented correctly." << endl;
			ok = false;
		}
		else {
			cout << "Passed!" << endl;
		}
	}
	if (ok) {
		cout << "Testing the logical operators: " << endl;
	}
	if (ok) {
		Date A(2018, 10, 18);
		Date B(2018, 10, 18);
		cout << "Testing operator==" << endl;
		if (A == B) {
			cout << "passed!" << endl;
		}
		else {
			cout << A << " is equal to " << B << " but operator== returns otherwise!" << endl;
			ok = false;
		}
	}

	if (ok) {
		Date A(2018, 10, 18);
		Date B(2018, 10, 18);
		cout << "Testing operator>=" << endl;
		if (A >= B) {
			cout << "passed!" << endl;
		}
		else {
			cout << A << " is equal to " << B << endl << "but operator>= returns otherwise!" << endl;
			ok = false;
		}
	}

	if (ok) {
		Date A(2018, 10, 18);
		Date B(2018, 10, 18);
		cout << "Testing operator<=" << endl;
		if (A <= B) {
			cout << "passed!" << endl;
		}
		else {
			cout << A << " is equal to " << B << endl << "but operator<= returns otherwise!" << endl;
			ok = false;
		}
	}

	if (ok) {
		Date A(2018, 10, 17);
		Date B(2018, 10, 18);
		cout << "Testing operator!=" << endl;
		if (A != B) {
			cout << "passed!" << endl;
		}
		else {
			cout << A << " is not equal to " << B << " but operator!= returns otherwise!" << endl;
			ok = false;
		}
	}

	if (ok) {
		Date A(2018, 10, 17);
		Date B(2018, 10, 18);
		cout << "Testing operator<" << endl;
		if (A < B) {
			cout << "passed!" << endl;
		}
		else {
			cout << A << " is less than " << B << " but operator< returns otherwise!" << endl;
			ok = false;
		}
	}

	if (ok) {
		Date A(2018, 10, 17);
		Date B(2018, 10, 18);
		cout << "Testing operator>" << endl;
		if (B > A) {
			cout << "passed!" << endl;
		}
		else {
			cout << B << " is greater than " << B << " but operator> returns otherwise!" << endl;
			ok = false;
		}
	}

	if (ok) {
		Date A(2018, 10, 17);
		Date B(2018, 10, 18);
		cout << "Testing operator<=" << endl;
		if (A < B) {
			cout << "passed!" << endl;
		}
		else {
			cout << A << " is less than " << B << " but operator<= returns otherwise!" << endl;
			ok = false;
		}
	}

	if (ok) {
		Date A(2018, 10, 17);
		Date B(2018, 10, 18);
		cout << "Testing operator>=" << endl;
		if (B >= A) {
			cout << "passed!" << endl;
		}
		else {
			cout << B << " is greater than " << B << " but operator>= returns otherwise!" << endl;
			ok = false;
		}
	}

	if (ok) {
		Date A;
		cout << "Testing error handling in read function;" << endl;
		cout << "Testing cin failure detection, " << endl;
		cout << "Please enter the following string \"abcd\": ";
		cin >> A;
		if (A.errCode() == CIN_FAILED) {
			cout << "passed!" << endl;
		}
		else {
			cout << "Your read function does not check cin.fail() after entry," << endl
				<< "or it did not set _readErrorCode to CIN_FAILED" << endl;
			ok = false;
		}
		cin.clear();
		cin.ignore(2000, '\n');
	}

	if (ok) {
		Date A;
		cout << "Testing year validation, " << endl;
		cout << "Please enter the following string \"10/1/1\": ";
		cin >> A;
		cout << "You accepted: " << A << endl;
		if (A.errCode() == YEAR_ERROR) {
			cout << "passed!" << endl;
		}
		else {
			cout << "Your read function does not check the year entry limits after entry," << endl
				<< "or it did not set _readErrorCode to YEAR_ERROR" << endl;
			ok = false;
		}
		cin.ignore(2000, '\n');
	}

	if (ok) {
		Date A;
		cout << "Testing month validation, " << endl;
		cout << "Please enter the following string \"2000/13/1\": ";
		cin >> A;
		cout << "You accepted: " << A << endl;
		if (A.errCode() == MON_ERROR) {
			cout << "Passed" << endl;
		}
		else {
			cout << "Your read function does not check the month entry limits after entry," << endl
				<< "or it did not set _readErrorCode to MON_ERROR" << endl;
			ok = false;
		}
		cin.ignore(2000, '\n');
	}

	if (ok) {
		Date A;
		cout << "Testing day validation, " << endl;
		cout << "Please enter the following string \"2000/1/50\": ";
		cin >> A;
		cout << "You accepted: " << A << endl;
		if (A.errCode() == DAY_ERROR) {
			cout << "Passed!" << endl;
		}
		else {
			cout << "Your read function does not check the day entry limits after entry," << endl
				<< "or it did not set _readErrorCode to DAY_ERROR" << endl;
			ok = false;
		}
		cin.ignore(2000, '\n');
	}

	if (ok) {
		Date A;
		cout << "Testing day validation, leap year:" << endl;
		cout << "Please enter the following string \"2016/2/29\": ";
		cin >> A;
		cout << "You accepted: " << A << endl;
		if (A.errCode() == DAY_ERROR) {
			cout << "Your read function does not check the day entry limits using mday()" << endl;
			ok = false;
		}
		else {
			cout << "passed!" << endl;
		}
		cin.ignore(2000, '\n');
	}

	if (ok) {
		cout << "You passed all the tests!" << endl;
	}
	else {
		cout << "You did not pass all the tests, keep working on your project!" << endl;
		ret = 1;
	}

	return ret;
}

// checks equality of dates A and B
//
bool equalDates(const char* A, const char* B) {
	unsigned int i;
	for (i = 0; i < sizeof(Date); i++) {
		if (A[i] != B[i]) i = sizeof(Date);
	}
	return sizeof(Date) == i;
}

// accepts yes from console
//
bool yes() {
	char ch;
	ch = cin.get();
	cin.ignore(1000, '\n');
	return ch == 'y' || ch == 'Y';
}

