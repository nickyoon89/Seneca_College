// Final Project - Milestone 3 - MyProduct and Test Modules
// Version 3.3
// Date	2018-03-03
// MyProduct.cpp
// Author	Fardad Soleimanloo, Chris Szalwinski
//
// For you final test before submission:
//      DO NOT MODIFY THIS FILE IN ANY WAY
//
//
// Revision History
// --------------------------------------------------------------
// Name               Date                 Reason
// Chris              2018-02-08           Removed polymorphism
// Chris              2018-03-02           Final Draft 20181
// Chris              2018-03-03           ErrorMessage -> ErrorState
/////////////////////////////////////////////////////////////////

#include <iomanip>
#include <fstream>
#include <cstring>
#include "MyProduct.h"
#ifdef TAB
#undef TAB
#endif
#define TAB '\t'
using namespace std;

namespace AMA {
	MyProduct::MyProduct() : Product("", "", "") {}
	MyProduct::MyProduct(const char* sku, const char* name, const char* unit, int qty,
		bool isTaxed, double price, int qtyNeeded) :
		Product(sku, name, unit, qty, isTaxed, price, qtyNeeded) {}
	const char* MyProduct::sku() const { return Product::sku(); }
	const char* MyProduct::name() const { return Product::name(); }
	const char* MyProduct::unit() const { return Product::unit(); }
	bool MyProduct::taxed() const { return Product::taxed(); }
	double MyProduct::price() const { return Product::price(); }
	double MyProduct::cost() const { return Product::cost(); }

	Test::Test(const char* file) : filename(file) { }
	Test::Test(const char* file, const char* theSku, const char* theName) : 
		product(theSku, theName, ""), filename(file) { }
	std::fstream& Test::store(std::fstream& file, bool addNewLine) const {
		if (!product.isEmpty()) {
			file.open(filename, ios::out | ios::app);
			file << product.sku() << TAB << product.name() << TAB << product.unit() << TAB <<
				(product.taxed() ? 1 : 0) << TAB << product.price() << TAB << product.quantity() << TAB <<
				product.qtyNeeded() << endl;
			file.clear();
			file.close();
		}
		return file;
	}
	std::fstream& Test::load(std::fstream& file) {
		char sku_[max_sku_length + 1];
		char name[max_name_length + 1];
		char unit[max_unit_length + 1];
		int  quantity, qtyNeeded;
		double price_;
		char taxed_;
		file.open(filename, ios::in);
		file >> sku_;
		file >> name;
		file >> unit;
		file >> taxed_;
		file >> price_;
		file >> quantity;
		file >> qtyNeeded;
		file.clear();
		file.close();
		product = MyProduct(sku_, name, unit, quantity, taxed_ != 0, price_, qtyNeeded);
		return file;
	}
	std::ostream& Test::write(std::ostream& os, bool linear) const {
		return product.isEmpty() ? os : (os << product.sku() << ": " << product.name() << ", quantity: "
			<< product.quantity() << ", quantity needed:" << product.qtyNeeded()
			<< ", Cost: " << fixed << setprecision(2) << product.cost());
	}
	std::istream& Test::read(std::istream& is) {
		char sku_[max_sku_length + 1];
		char name[max_name_length + 1];
		char unit[max_unit_length + 1];
		int  quantity, qtyNeeded;
		double price_;
		char taxed_;
		cout << " Sku: ";
		is >> sku_;
		cout << " Name (no spaces): ";
		is >> name;
		cout << " Unit: ";
		is >> unit;
		cout << " Taxed? (y/n): ";
		is >> taxed_;
		cout << " Price: ";
		is >> price_;
		cout << " Quantity On hand: ";
		is >> quantity;
		cout << " Quantity Needed: ";
		is >> qtyNeeded;
		product = MyProduct(sku_, name, unit, quantity, taxed_ != 0, price_, qtyNeeded);
		return is;
	}
	int Test::operator+=(int value) {
		product.quantity(product += value);
		return product.quantity();
	}
	bool Test::operator==(const char* sku) const {
		return !std::strcmp(product.sku(), sku);
	}
	std::ostream& operator<<(std::ostream& os, const Test& test) {
		return test.product.write(os, true);
	}
	double operator+=(double& d, const Test& test) {
		return d += test.product.total_cost();
	}
	std::istream& operator>>(std::istream& is, Test& test) {
		return test.product.read(is);
	}
}
