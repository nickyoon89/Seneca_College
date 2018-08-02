// Workshop 9 - Smart Pointers
// Element.h

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

extern const int FWC;
extern const int FWD;
extern const int FWP;

namespace w9 {

	struct Description {
		unsigned code;
		std::string desc;
		bool load(std::ifstream& f) {
			f >> code >> desc;
			return f.good();
		}
		void display(std::ostream& os) const {
			os << std::setw(FWC) << code << std::setw(FWD)
				<< desc << std::endl;
		}
	};

	struct Price {
		unsigned code;
		double price;
		bool load(std::ifstream& f) {
			f >> code >> price;
			return f.good();
		}
		void display(std::ostream& os) const {
			os << std::setw(FWC) << code << std::setw(FWP)
				<< price << std::endl;
		}
	};

	struct Product {
		std::string desc;
		double price;
		Product() {}
		Product(const std::string& str, double p) : desc(str), price(p) {
			validate();
		}
		void display(std::ostream& os) const {
			os << std::setw(FWD) << desc << std::setw(FWP)
				<< price << std::endl;
		}
		void validate() {
			if (price < 0) throw "*** Negative prices are invalid ***";
		}
	};
}
