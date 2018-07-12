#include "TaxableProduct.h"

namespace w7 {
	TaxableProduct::TaxableProduct() {
		prdtNo = 0;
		price = 0.0;
		taxType = ' ';
	}

	TaxableProduct::TaxableProduct(int prdtNo, double price, char taxType) {
		this->prdtNo = prdtNo;
		this->price = price;
		this->taxType = taxType;
	}

	double TaxableProduct::getCharge() const {
		if (taxType == 'H') return price * taxRate[0];
		else return price * taxRate[1];
	}

	void TaxableProduct::display(std::ostream& os) const {
		os << std::setw(10) << prdtNo << std::setw(10) <<std::fixed<< price;
		os.width();
		if (taxType == 'H') os << " HST";
		else if (taxType == 'P') os << " PST";
	}

}