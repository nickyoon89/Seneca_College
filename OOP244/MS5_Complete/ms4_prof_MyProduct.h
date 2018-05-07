// Final Project Milestone 3 - Product Interface
// Version 3.3
// MyProduct_prof.h
// 2018/03/10
// Authors	Fardad Soleimanloo, Chris Szalwinski
//
// For you final test before submission:
//      DO NOT MODIFY THIS FILE IN ANY WAY
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Fardad             2017-07-11           corrected compile safegaurds
// Chris              2017-12-02           Streamable -> Product
// Chris              2017-12-06           C++17 -> C++11
// Chris              2018-01-25           Product -> iProduct
// Chris              2018-03-03           ErrorMessage -> ErrorState
// Chris              2018-03-10           Matching specs
/////////////////////////////////////////////////////////////////
#ifndef AMA_MYPRODUCT_H__
#define AMA_MYPRODUCT_H__
#include "iProduct.h"
#include "iProduct.h"
#include "iProduct.h" // Product.h is included three times on purpose.

namespace AMA {
  class MyProduct : public iProduct {
    char text_[10000];
	char sku[4];
	char name_[20];
	int value;
  public:
    MyProduct(const char* name);
    std::fstream& store(std::fstream& file, bool addNewLine)const;
    std::fstream& load(std::fstream& file);
    std::ostream& write(std::ostream& os, bool linear)const;
    std::istream& read(std::istream& is);
	bool operator==(const char*) const;
	double total_cost() const;
	const char* name() const;
	void quantity(int);
	int qtyNeeded() const;
	int quantity() const;
	int operator+=(int);
	bool operator>(const iProduct&) const;
  };
}
#endif