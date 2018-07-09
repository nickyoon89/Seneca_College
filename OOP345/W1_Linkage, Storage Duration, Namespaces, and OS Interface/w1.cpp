/**********************************************************
// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
// w1.cpp
// Name: Jihyun Yoon
// email: jyoon31@myseneca.ca
// Student#: 124558172
// Revision History
///////////////////////////////////////////////////////////
// Name			Date		                         Reason
// Jihyun        2018/05/23                        file made
///////////////////////////////////////////////////////////
**********************************************************/

#include "CString.h"
#include "345_w1_Process.h"
#include <fstream>


int main(int argc, char** argv) {
	std::cout << "Command Line : w1";
	for (int i = 1; i < argc; i++)
	{
		std::cout << " " << argv[i]<<" \n";
	}
	std::ifstream file;
	char str_c[1001];
	file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	switch (argc)
	{
	case 1:
		std::cerr << "*** Insufficient number of arguments ***\nUsage : w1 filename" << std::endl;
		break;
	case 2:
		try {
			file.open(argv[1]);
			std::cout << "Reading records from file " << argv[1] << std::endl;
			while (!file.eof()) {
				file.getline(str_c,1000);
				process(str_c);
			}
			file.close();
		}
		catch (std::ifstream::failure e) {
			std::cerr << "*** Failed to open file " << argv[1] << " ***" << std::endl;
		}
		break;
	default:
		std::cerr << "*** Too many arguments ***\nUsage : w1 filename" << std::endl;
		break;
	}
	return 0;
}