// Final Project Milestone 1
//
// Version 1.0
// Date
// Author
// Description
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#ifndef AMA_DATE_H
#define AMA_DATE_H

namespace AMA {
	int const min_year = 2000;
	int const max_year = 2030;
	int const NO_ERROR = 0;
	int const CIN_FAILED = 1;
	int const YEAR_ERROR = 2;
	int const MON_ERROR = 3;
	int const DAY_ERROR = 4;
	class Date {
		int _year;
		int _month;
		int _day;
		int _compValue;
		int _errCode;

		int mdays(int, int)const;
		void errCode(int errCode);
	public:
		Date();
		Date(int year, int month, int day);
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& is);
		int errCode();
		bool bad() const;
		bool operator==(Date d);
		bool operator!=(Date d);
		bool operator>=(Date d);
		bool operator<=(Date d);
		bool operator>(Date d);
		bool operator<(Date d);
	};
	std::ostream& operator<<(std::ostream& os, const Date& d);
	std::istream& operator>>(std::istream& is, Date& d);
}
#endif