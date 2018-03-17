// Final Project Milestone 1
//
// Version 1.0
// Date 2018-03-12
// Author Jihyun Yoon
// Description
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Jihyun Yoon		2018-03-12			
/////////////////////////////////////////////////////////////////
#include <iostream>
#include <cstring>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include "Date.h"

namespace AMA {

	// number of days in month mon_ and year year_
	int Date::mdays(int mon, int year)const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}

	void Date::errCode(int errCode) {
		_errCode = errCode;
	}

	bool Date::bad() const {
		if (_errCode == NO_ERROR) return false;
		else return true;
	}

	Date::Date() {
		_year = 0;
		_month = 0;
		_day = 0;
		_compValue = 0;
		errCode(NO_ERROR);
	}
	Date::Date(int year, int month, int day) {
		_year = year;
		_month = month;
		_day = day;
		_compValue = _year * 372 + _month * 13 + _day;
		
		if (_year == 0 && _month == 0 && _day == 0) errCode(CIN_FAILED);
		else if (_year < min_year || _year > max_year) errCode(YEAR_ERROR);
		else if (_month < 1 || _month > 12)  errCode(MON_ERROR);
		else if (_day < 1 || _day > mdays(_month, _year)) errCode(DAY_ERROR);
		else errCode(NO_ERROR);

		if (bad()) {
			_year = 0;
			_month = 0;
			_day = 0;
			_compValue = 0;
		}
	}
	std::ostream& Date::write(std::ostream& os) const {
		os << _year << "/" << std::setfill('0') << std::setw(2) << _month << "/" << std::setfill('0') << std::setw(2) << _day;
		return os;
	}

	std::istream& Date::read(std::istream& is) {
		char inputString[50];
		int inputData[3];
		char * token;
		int i;
		is >> inputString;
		token = strtok(inputString, " `-=[];',./~!@#$%^&()_+{}|:<>?");

		if (is.fail()) {
			*this = Date();
			errCode(CIN_FAILED);
			is.clear();
			return is;
		}
		else {
			for (i = 0; i < 3; i++)
			{
				if (token == NULL) break;
				inputData[i] = atoi(token);
				token = strtok(NULL, " `-=[];',./~!@#$%^&()_+{}|:<>?");
			}
			if (i == 3) {
				*this = Date(inputData[0], inputData[1], inputData[2]);
			}
			else {
				*this = Date();
				errCode(CIN_FAILED);
				is.clear();
				return is;
			}
		}
		return is;
	}
	int Date::errCode() {
		return _errCode;
	}
	bool Date::operator==(Date d) {
		if (_compValue==d._compValue) return true;
		else return false;
	}
	bool Date::operator!=(Date d) {
		if (_compValue != d._compValue) return true;
		else return false;
	}
	bool Date::operator>=(Date d) {
		if (_compValue>=d._compValue) return true;
		else return false;
	}
	bool Date::operator<=(Date d) {
		if (_compValue <= d._compValue) return true;
		else return false;
	}
	bool Date::operator<(Date d) {
		if (_compValue < d._compValue) return true;
		else return false;
	}
	bool Date::operator>(Date d) {
		if (_compValue > d._compValue) return true;
		else return false;
	}

	std::ostream& operator<<(std::ostream& os, const Date& d) {
		return d.write(os);
	}
	std::istream& operator >> (std::istream& is, Date& d) {
		return d.read(is);
	}
}
