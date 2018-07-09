/**********************************************************
// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
// Process.cpp
// Name: Jihyun Yoon
// email: jyoon31@myseneca.ca
// Student#: 124558172
// Revision History
///////////////////////////////////////////////////////////
// Name			Date		                         Reason
// Jihyun        2018/05/23                        file made
///////////////////////////////////////////////////////////
**********************************************************/

#include <iostream>
#include "CString.h"
#include "w1_Proccess.h"

void process(const char* str) {
	sict::CString a(str);
	std::cout << a << std::endl;
}