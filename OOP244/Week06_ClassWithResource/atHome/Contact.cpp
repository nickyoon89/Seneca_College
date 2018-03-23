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
// Jihyun        2018/03/16                       atHome part
// Jihyun		 2018/03/19						  data leaking, self-assignment check
///////////////////////////////////////////////////////////
**********************************************************/

#include <iostream>
#include <cstring>
#include <iomanip>
#include "Contact.h"
using namespace std;
//#pragma warning(disable:4996)

namespace sict {
	bool phoneValid(long long phoneNum) {
		if (phoneNum / (long long)1e12 == 0 && phoneNum / (long long)1e10 != 0) {
			phoneNum -= (phoneNum / (long long)1e10)*(long long)1e10;
			if (phoneNum / (long long)1e9 != 0) {
				phoneNum -= (phoneNum / (long long)1e7)*(long long)1e7;
				if (phoneNum / (long long)1e6 != 0) {
					return true;
				}
			}
		}
		return false;
	}

	Contact::Contact() {
		_names[0] = '\0';
		_phones = nullptr;
		_storedNo = -1;
	}
	Contact::Contact(const char* names, const long long* phones, int storedNo) {
		if (names != nullptr&&names[0]!='\0'&&storedNo>=0) {
			int valNo = 0;
			int count = 0;
			for (int i = 0; i < storedNo; i++)
			{
				if (phoneValid(phones[i])) {
					valNo++;
				}
			}
			strncpy(_names, names, 20);
			if (_names[19] != '\0') _names[19] = '\0';
			_storedNo = valNo;
			_phones = new long long[valNo];
			for (int i = 0; i < storedNo; i++)
			{
				if (phoneValid(phones[i])) {
					_phones[count] = phones[i];
					count++;
				}
			}
		}
		else {
			*this = Contact();
		}
	}
	Contact::Contact(const Contact& cont) {
		if (strcmp(_names, cont._names) != 0 || _phones != cont._phones||_storedNo != cont._storedNo) {
			*this = cont;
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
	Contact& Contact::operator=(const Contact& cont) {
		if (strcmp(_names, cont._names) == 0 && _phones == cont._phones&&_storedNo == cont._storedNo) return *this;
		if (cont.isEmpty()) {
			_names[0] = '\0';
			_phones = nullptr;
			_storedNo = -1;
		}
		else {
			strcpy(_names, cont._names);
			_storedNo = cont._storedNo;
			if (cont._phones != nullptr) {
				//delete[] phones;
				_phones = new long long[_storedNo];
				for (int i = 0; i < _storedNo; i++)
					_phones[i] = cont._phones[i];
			}
		}
		return *this;
	}
	Contact& Contact::operator+=(long long phoneNum) {
		if (phoneValid(phoneNum)&&!isEmpty()) {
			_storedNo++;
			if (_storedNo > 1) {
				long long * tempPhone = new long long[_storedNo - 1];
				tempPhone = _phones;
				_phones = new long long[_storedNo];
				for (int i = 0; i < _storedNo; i++) {
					if (i == _storedNo - 1) {
						delete[] tempPhone;
						_phones[i] = phoneNum;
					}
					else _phones[i] = tempPhone[i];
				}
			}
			else {
				if (_storedNo == 0) _storedNo++;
				_phones = new long long[_storedNo];
				_phones[_storedNo - 1] = phoneNum;
			}
		}
		return *this;
	}
}