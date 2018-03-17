/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.h
// Version 1.0
// Date 2018 Feb 01
// Author Cornel Barna
//
// Name: Jihyun Yoon
// Email: jyoon31@myseneca.ca
// Student Number: 124558172
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// Jihyun Y Feb.01  file made
///////////////////////////////////////////////////////////
***********************************************************/


// TODO: include the necessary headers
#include <iostream>
#include "Kingdom.h"
using namespace std;
// TODO: the sict namespace
namespace sict {
	void display(const Kingdom &kingdom) {
		cout << kingdom.m_name << ", population " << kingdom.m_population << endl;
	}
}
    // TODO:definition for display(...) 
