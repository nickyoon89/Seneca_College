// Final Project Milestone 3 - iProduct Interface
// Version 3.3
// MyProduct_prof.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include "MyProduct.h"
using namespace std;

namespace AMA {

  // constructor
  //
  MyProduct::MyProduct(const char* n) {
	value = 0;
	strcpy(sku, "sku");
    text_[0] = char(0);
	strcpy(name_, n);
  }

  // store record to file
  //
  fstream& MyProduct::store(std::fstream& file, bool addNewLine)const{
    int i = 0;
    while (text_[i]){
      file << text_[i];
      i++;
    }
    return file;
  }

  // load record from file
  //
  fstream& MyProduct::load(std::fstream& file){
    int i=0;
    while (!file.fail()){
      text_[i++] = file.get();
    }
    file.clear();
    if(i > 0) i--;
    text_[i] = 0;
    return file;
  }

  // write to standard output
  //
  ostream& MyProduct::write(std::ostream& os, bool linear)const{
    for (int i = 0; text_[i]; i++){
      if (linear && text_[i] == '\n'){
        os << " ";
      }
      else{
        os << text_[i];
      }
    }
    return os;
  }

  // read from standard input
  //
  istream& MyProduct::read(std::istream& is){
    is.getline(text_, 9999, EOF);
    return is;
  }

  // insertion operator
  //
  std::ostream& operator<<(std::ostream& ostr, const iProduct& mf){
    return mf.write(ostr, true);
  }

  // extraction operator
  //
  std::istream& operator>>(std::istream& istr, iProduct& mf){
    return mf.read(istr);
  }

  // sku equality comparison
  //
  bool MyProduct::operator==(const char* str) const {
	  return !strcmp(sku, str); 
  }

  // total cost
  //
  double MyProduct::total_cost() const {
	  return 113.50; 
  }

  // return MyProduct name
  //
  const char* MyProduct::name() const {
	  return name_; 
  }

  // set quantity
  //
  void MyProduct::quantity(int i) {
	  value = i; 
  }

  // return quantity needed
  //
  int MyProduct::qtyNeeded() const {
	  return 45; 
  }

  // return quantity
  //
  int MyProduct::quantity() const {
	  return value;  
  }

  // increment
  //
  int MyProduct::operator+=(int i) {
	  value += i;
	  return value;
  }

  // accumulate total costs
  //
  double operator+=(double& d, const iProduct& p) {
	  d += p.total_cost();
	  return d;
  }

  // compare iProducts
  //
  bool MyProduct::operator>(const iProduct& p) const {
	  return !strcmp(name_, p.name()); 
  }
}