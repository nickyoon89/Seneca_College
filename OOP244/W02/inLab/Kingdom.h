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

// TODO: header safeguards
#ifndef KINGDOM_H
#define KINGDOM_H



// TODO: sict namespace

namespace sict {
	struct Kingdom
	{
		char m_name[32];
		int m_population;
	};
	void display(const Kingdom &kingdom);
}

#endif // !KINGDOM_H
