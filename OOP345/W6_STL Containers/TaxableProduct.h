#ifndef W7_TAXPRODUCT_H
#define W7_TAXPRODUCT_H

#include "iProduct.h"

namespace w7 {

	class TaxableProduct : public iProduct {
		int prdtNo;
		double price;
		char taxType;
		std::array<double, 2> taxRate = { {1.13, 1.08} };
	public:
		TaxableProduct();
		TaxableProduct(int prdtNo, double price, char taxType);
		double getCharge() const;
		void display(std::ostream&) const;
	};

}

#endif