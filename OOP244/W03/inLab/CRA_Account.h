/**********************************************************
// Workshop 3: Classes and Privacy
// CRA_Account.h
// Name: Jihyun Yoon
// email: jyoon31@myseneca.ca
// Student#: 124558172
// Revision History
///////////////////////////////////////////////////////////
// Name			Date		                         Reason
// Jihyun        2018/02/06                        file made
///////////////////////////////////////////////////////////
**********************************************************/

#ifndef CRA_ACCOUNT_H
#define CRA_ACCOUNT_H
namespace sict {
	const int max_name_length = 40;
	const int min_sin = 100000000;
	const int max_sin = 999999999;

	class CRA_Account
	{
	public:
		void set(const char* familyName, const char* givenName, int sin);
		bool isEmpty() const;
		void display() const;
	};
}
#endif // !CRA_ACCOUNT_H
