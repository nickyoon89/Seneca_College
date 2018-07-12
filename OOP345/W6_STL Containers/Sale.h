#ifndef W7_SALE_H_
#define W7_SALE_H_

#include "Product.h"
#include "TaxableProduct.h"

namespace w7 {

	class Sale {
		std::vector<const iProduct*> prdtList;
	public:
		Sale(const char* name);
		void display(std::ostream& os) const;
	};
	//this function return the number of line of the parameter file.
	int getFileLine(std::ifstream& fin);
}
#endif