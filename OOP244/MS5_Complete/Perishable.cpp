// Final Project Milestone 5
//
// Version 1.0
// Date			2018/04/15
// Author		Jihyun Yoon
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Jihyun Yoon		2018/04/15			File Made
/////////////////////////////////////////////////////////////////


#include "Perishable.h"

namespace AMA {
	Perishable::Perishable() : Product::Product('P') {
		expDate = Date();
	}
	std::fstream& Perishable::store(std::fstream& file, bool newLine) const {
		Product::store(file, false);
		file << "," << expDate;
		if (newLine) file << std::endl;
		return file;
	}
	std::fstream& Perishable::load(std::fstream& file){
		Product::load(file);
		for (int i = 0; i < 8; i++) {
			file.ignore(2000, ',');
		}
		expDate.read(file);
		return file;
	}
	std::ostream& Perishable::write(std::ostream& os, bool linear) const {
		os << std::setfill(' ');
		if (Product::write(os, linear)) {
			if (Product::isClear()) {
				if (linear) {
					os << expDate;
				}
				else {
					os << std::endl << " Expiry date: " << expDate;
				}
			}
		};
		return os;
	}
	std::istream& Perishable::read(std::istream& is) {
		Date tempDate;
		
		if (Product::read(is)) {
			std::cout << " Expiry date (YYYY/MM/DD): ";
			is >> tempDate;
			if (tempDate.errCode() != 0) {
				is.setstate(std::ios::failbit);
				switch (tempDate.errCode())
				{
				case CIN_FAILED:
					Product::message("Invalid Date Entry");
					break;
				case YEAR_ERROR:
					Product::message("Invalid Year in Date Entry");
					break;
				case MON_ERROR:
					Product::message("Invalid Month in Date Entry");
					break;
				case DAY_ERROR:
					Product::message("Invalid Day in Date Entry");
					break;
				default:
					break;
				}
			}
		}
		if (!is.fail()) {
			expDate = tempDate;
		}
		return is;
	}
	const Date& Perishable::expiry() const {
		return expDate;
	}
}