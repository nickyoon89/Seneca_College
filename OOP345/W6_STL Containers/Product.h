#ifndef W7_PRODUCT_H
#define W7_PRODUCT_H

#include "iProduct.h"

namespace w7 {

	class Product : public iProduct {
		int prdtNo;
		double price;
	public:
		Product();
		Product(int prdtNo, double price);
		double getCharge() const;
		void display(std::ostream&) const;
	};
}

#endif // !1