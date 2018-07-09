#ifndef SICT_CSTRING_H
#define SICT_CSTRING_H
/**********************************************************
// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
// CString.h
// Name: Jihyun Yoon
// email: jyoon31@myseneca.ca
// Student#: 124558172
// Revision History
///////////////////////////////////////////////////////////
// Name			Date		                         Reason
// Jihyun        2018/05/23                        file made
///////////////////////////////////////////////////////////
**********************************************************/

#define MAX_CHAR 14
#include<iostream>
namespace sict {
	class CString {
		char* _string_c;		
	public:
		CString(const char* string_c = nullptr);
		void display(std::ostream& os) const;
		~CString();
	};
	std::ostream& operator<<(std::ostream& os, const CString& cs);
}
#endif // !SICT_CSTRING_H

