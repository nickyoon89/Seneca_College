#include "Product.h"

namespace w7 {
	Product::Product() {
		prdtNo = 0;
		price = 0.0;
	}

	Product::Product(int prdtNo, double price) {
		this->prdtNo = prdtNo;
		this->price = price;
	}

	double Product::getCharge() const {
		return price;
	}

	void Product::display(std::ostream& os) const {
		os << std::setw(10) << prdtNo << std::setw(10) << std::fixed << price;
	}
}