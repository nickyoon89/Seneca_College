// TODO: add file header comments here
/**********************************************************
// Workshop 6: Class with a Resource
// Contact.cpp
// Name: Jihyun Yoon
// email: jyoon31@myseneca.ca
// Student#: 124558172
// Revision History
///////////////////////////////////////////////////////////
// Name			Date		                         Reason
// Jihyun        2018/03/13                       file made
///////////////////////////////////////////////////////////
**********************************************************/

#include <iostream>
#include <cstring>
#include <iomanip>
#include "Contact.h"
using namespace std;

namespace sict {
	Contact::Contact() {
		_names[0] = '\0';
		_phones = nullptr;
		_storedNo = -1;
	}
	Contact::Contact(const char* names, const long long* phones, int storedNo) {
		if (names != nullptr&&names[0]!='\0'&&storedNo>=0) {
			int valNo = 0;
			long long* tempPhones = new long long[storedNo];
			long long tempNum;
			for (int i = 0; i < storedNo; i++)
			{
				if (phones[i] / (long long)1e12 == 0 && phones[i] / (long long)1e10 != 0) {
					tempNum = phones[i];
					tempNum -= (tempNum / (long long)1e10)*(long long)1e10;
					if (tempNum / (long long)1e9 != 0) {
						tempNum -= (tempNum / (long long)1e7)*(long long)1e7;
						if (tempNum / (long long)1e6 != 0) {
							tempPhones[valNo] = phones[i];
							valNo++;
						}
					}
				}
			}
			strncpy(_names, names,20);
			if (_names[19] != '\0') _names[19] = '\0';
			_storedNo = valNo;
			_phones = new long long[valNo];
			for (int i = 0; i < valNo; i++)
			{
				_phones[i] = tempPhones[i];
			}
			delete[] tempPhones;
		}
		else {
			*this = Contact();
		}
	}
	Contact::~Contact() {
		delete[] _phones;
	}
	bool Contact::isEmpty() const {
		if (_names[0] == '\0'&&_phones == nullptr&&_storedNo == -1) return true;
		else return false;
	}
	void Contact::display() const {
		if (!isEmpty()) {
			int country;
			int area;
			int number1;
			int number2;
			Contact temp = Contact(_names, _phones, _storedNo);
			cout << _names << endl;
			for (int i = 0; i < _storedNo; i++)
			{
				country = temp._phones[i] / 1e10;
				temp._phones[i] -= country * 1e10;
				area = temp._phones[i] / 1e7;
				temp._phones[i] -= area * 1e7;
				number1 = temp._phones[i] / 1e4;
				temp._phones[i] -= number1 * 1e4;
				number2 = temp._phones[i];
				cout << "(+" << country << ") " << area << " " << number1 << "-" << setfill('0') << setw(4) << number2 << endl;
			}
		}
		else {
			cout << "Empty contact!" << endl;
		}
	}
}