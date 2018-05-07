// Final Project Milestone 3 - iProduct Interface
// Version 3.3
// Allocator.cpp
// 2018-03-10
// Authors	Fardad Soleimanloo, Chris Szalwinski
//
// For you final test before submission:
//      DO NOT MODIFY THIS FILE IN ANY WAY
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#include "Product.h"
#include "Perishable.h"

namespace AMA {

	// creates an empty product
	//
	iProduct* CreateProduct() {
		return new Product();
	}

	// creates an empty perishable product
	//
	iProduct* CreatePerishable() {
		return new Perishable();
	}
}