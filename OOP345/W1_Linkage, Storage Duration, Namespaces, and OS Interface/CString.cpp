/**********************************************************
// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
// Cstring.cpp
// Name: Jihyun Yoon
// email: jyoon31@myseneca.ca
// Student#: 124558172
// Revision History
///////////////////////////////////////////////////////////
// Name			Date		                         Reason
// Jihyun        2018/05/23                        file made
///////////////////////////////////////////////////////////
**********************************************************/
#include "CString.h"
#include <cstring>

namespace sict {
	static int no = 10;
	CString::CString(const char* string_c) {
		if (string_c!=nullptr) {
			if (strlen(string_c) < MAX_CHAR) {
				_string_c = new char[strlen(string_c)+1];
				strncpy(_string_c, string_c, strlen(string_c));
			}
			else {
				_string_c = new char[MAX_CHAR + 1];
				strncpy(_string_c, string_c, MAX_CHAR);
			}
			if (_string_c[strlen(_string_c)] != '\0') {
				_string_c[strlen(_string_c)] = '\0';
			}
		}
	}
	void CString::display(std::ostream& os) const{
		os << _string_c;
	}
	std::ostream& operator<<(std::ostream& os, const CString& cs) {
		if (no == 10) { os << " No  Record Contents ..." << std::endl; }
		os <<" "<<no<<": ";
		cs.display(os);
		no++;
		return os;
	}
	CString::~CString() {
		delete[] _string_c;
		_string_c = nullptr;
	}
}