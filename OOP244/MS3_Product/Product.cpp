// Final Project - Milestone 3 - MyProduct and Test Modules
// Version 1.0
// Date				2018/04/08
// Author			Jihyun Yoon
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Jihyun Yoon		2018/04/08			File Made
/////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <iomanip>
#include "Product.h"
//#pragma warning(disable:4996)

namespace AMA {
	void Product::name(const char* name) {
		if (_prdtName != nullptr) {
			delete[] _prdtName;
			_prdtName = nullptr;
		}
		if (name != nullptr) {
			if (strlen(name) > max_name_length) {
				_prdtName = new char[max_name_length + 1];
				strncpy(_prdtName, name, max_name_length);
				if (_prdtName[strlen(name)] != '\0') _prdtName[strlen(name)] = '\0';
			}
			else {
				_prdtName = new char[strlen(name) + 1];
				strcpy(_prdtName, name);
				if (_prdtName[strlen(name)] != '\0') _prdtName[strlen(name)] = '\0';
			}
		}
		
	}
	const char* Product::name() const {
		if (_prdtName==nullptr||_prdtName[0] == '\0') return nullptr;
		else return _prdtName;
	}
	const char* Product::sku() const {
		return _prdtSku;
	}
	const char* Product::unit() const {
		return _prdtUnitDesc;
	}
	bool Product::taxed() const {
		return _taxable;
	}
	double Product::price() const {
		return _prdtUnitPrc;
	}
	double Product::cost() const {
		if(_taxable) return _prdtUnitPrc + (_prdtUnitPrc*CUR_TAX);
		else return _prdtUnitPrc;
	}
	void Product::message(const char* errMsg) {
		_prdtErrSt.message(errMsg);
	}
	bool Product::isClear() const {
		return _prdtErrSt.isClear();
	}

	Product::Product(char prdtType) {
		_prdtType = prdtType;
		_prdtSku[0] = '\0';
		_prdtUnitDesc[0] = '\0';
		_prdtName = nullptr;
		_prdtQtyH = 0;
		_prdtQtyN = 0;
		_prdtUnitPrc = 0;
		_taxable = true;
	}
	Product::Product(const char* sku, const char* prdtName, const char* prdtUnit, int prdtQtyH, bool taxable, double prdtPrc, int prdtQtyN) {
		_prdtName = nullptr;
		*this = Product();
		strncpy(_prdtSku, sku, max_sku_length);
		if (_prdtSku[max_sku_length] != '\0') _prdtSku[max_sku_length] = '\0';
		name(prdtName);
		strncpy(_prdtUnitDesc, prdtUnit, max_unit_length);
		if (_prdtUnitDesc[max_unit_length] != '\0') _prdtUnitDesc[max_unit_length] = '\0';
		_prdtQtyH = prdtQtyH;
		_prdtQtyN = prdtQtyN;
		_taxable = taxable;
		_prdtUnitPrc = prdtPrc;
	}
	Product::Product(const Product& copyProduct) {
		if (!copyProduct.isEmpty()) {
			_prdtName = nullptr;
			*this = copyProduct;
		}
	}
	Product& Product::operator=(const Product& copyProduct) {
		if(this == &copyProduct) return *this;
		else {
			_prdtType = copyProduct._prdtType;
			strcpy(_prdtSku, copyProduct._prdtSku);
			name(copyProduct._prdtName);
			strcpy(_prdtUnitDesc, copyProduct._prdtUnitDesc);
			_prdtQtyH = copyProduct._prdtQtyH;
			_prdtQtyN = copyProduct._prdtQtyN;
			_taxable = copyProduct._taxable;
			_prdtUnitPrc = copyProduct._prdtUnitPrc;
			_prdtErrSt.message(copyProduct._prdtErrSt.message());
			return *this;
		}
	}
	Product::~Product() {
		delete[] _prdtName;
		_prdtName = nullptr;
	}
	std::fstream& Product::store(std::fstream& file, bool newLine) const {
		file << _prdtType <<","<< _prdtSku << "," << _prdtUnitDesc <<"," << _prdtName <<"," << _prdtQtyH <<"," << _prdtQtyN <<"," << _prdtUnitPrc <<"," << _taxable <<"," << _prdtErrSt;
		if (newLine) file << std::endl;
		return file;
	}
	std::fstream& Product::load(std::fstream& file) {
		std::string tempString[9];
		for (int i = 0; i < 9; i++)
		{
			std::getline(file, tempString[i], ',');
		}
		Product tempPrdt = Product(tempString[1].c_str(), tempString[3].c_str(), tempString[2].c_str(), std::stoi(tempString[4]), std::stoi(tempString[7]), std::stoi(tempString[6]), std::stoi(tempString[5]));
		tempPrdt._prdtType = tempString[0][0];
		tempPrdt.message(tempString[8].c_str());
		*this = tempPrdt;
		return file;
	}
	std::ostream& Product::write(std::ostream& os, bool linear) const {
		if (linear) {
			os << std::left << std::setw(max_sku_length) << _prdtSku << "|";
			os << std::left << std::setw(20) << _prdtName << "|";
			os << std::fixed << std::setprecision(2) << std::right << std::setw(7) << cost() << "|";
			os << std::right << std::setw(4) << _prdtQtyH << "|";
			os << std::left << std::setw(10) << _prdtUnitDesc << "|";
			os << std::right << std::setw(4) << _prdtQtyN << "|";
		}
		else {
			os << "Sku: " << _prdtSku << std::endl;
			os << "Name (no space): " << _prdtName << std::endl;
			os << "Price: " << price() << std::endl;
			if(taxed()) os << " Price after tax: " << cost() << std::endl;
			else os << " N/A" << std::endl;
			os << "Quantity on hand: " << _prdtQtyH << std::endl;
			os << "Quantity needed: " << _prdtQtyN << std::endl;
		}
		return os;
	}
	std::istream& Product::read(std::istream& is) {
		char* sku =new char[max_sku_length + 1];
		char* name=new char[max_name_length + 1];
		char* unit=new char[max_unit_length + 1];
		int  quantity, qtyNeeded;
		double price;
		char taxed;
		bool taxable;
		std::cout << " Sku: ";
		is >> sku;
		std::cout << " Name (no spaces): ";
		is >> name;
		std::cout << " Unit: ";
		is >> unit;
		std::cout << " Taxed? (y/n): ";
		is >> taxed;
		if (taxed != 'y'&&taxed != 'Y'&&taxed != 'n'&&taxed != 'N') {
			is.setstate(std::ios::failbit);
			_prdtErrSt.message("Only (Y)es or (N)o are acceptable");
		}
		else {
			if (taxed == 'y' || taxed == 'Y') taxable = true;
			else taxable = false;
		}
		if (!is.fail()) {
			std::cout << " Price: ";
			is >> price;
			if (is.fail()) _prdtErrSt.message("Invalid Price Entry");
		}
		if (!is.fail()) {
			std::cout << " Quantity on hand: ";
			is >> quantity;
			if (is.fail()) _prdtErrSt.message("Invalid Quantity Entry");
		}
		if (!is.fail()) {
			std::cout << " Quantity needed: ";
			is >> qtyNeeded;
			if (is.fail()) _prdtErrSt.message("Invalid Quantity Needed Entry");
		}
		if (!is.fail()) {
			Product temp = Product(sku, name, unit, quantity, taxable, price, qtyNeeded);
			*this = temp;
		}
		delete[] name;
		name = nullptr;
		return is;
	}
	bool Product::operator==(const char* sku) const {
		return (strcmp(_prdtSku, sku) == 0);
	}
	double Product::total_cost() const {
		return cost()*_prdtQtyH;
	}
	void Product::quantity(int unitNo) {
		_prdtQtyH = unitNo;
	}
	bool Product::isEmpty() const {
		if (_prdtType == 'N'&&_prdtSku[0] == '\0'&&_prdtUnitDesc[0] && '\0'&&_prdtQtyH == 0 && _prdtQtyN == 0 && _prdtUnitPrc == 0 && _taxable == true && _prdtName==nullptr) {
			return true;
		}
		else return false;
	}
	int Product::qtyNeeded() const {
		return _prdtQtyN;
	}
	int Product::quantity() const {
		return _prdtQtyH;
	}
	bool Product::operator>(const char* sku) const {
		return (_prdtSku > sku);
	}
	bool Product::operator>(const   Product& product) const {
		return (_prdtName > product._prdtName);
	}
	int Product::operator+=(int unitNo) {
		_prdtQtyH += unitNo;
		return _prdtQtyH;
	}


	std::ostream& operator<<(std::ostream& os, const Product& product) {
		product.write(os, false);
		return os;
	}
	std::istream& operator>>(std::istream& is, Product& product) {
		product.read(is);
		return is;
	}
	double operator+=(double& add, const Product& product) {
		add += product.total_cost();
		return add;
	}
} 