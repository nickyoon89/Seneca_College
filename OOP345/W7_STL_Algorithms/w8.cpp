// Workshop 8 - STL Algorithms
// w8.cpp


#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include "DataTable.h"

const int FW = 7;
const int ND = 2;

int main(int argc, char** argv) {
	std::cout << "\nCommand Line : ";
	for (int i = 0; i < argc; i++) {
		std::cout << argv[i] << ' ';
	}
	std::cout << std::endl;
	if (argc != 2 && argc != 3) {
		std::cerr << argv[0] << ": incorrect number of arguments\n";
		std::cerr << "Usage: " << argv[0] << " file_name [p]\n";
		return 1;
	}
	std::ifstream dataFile(argv[1]);
	if (!dataFile) {
		std::cerr << "\n***Failed to open file " << argv[1] << "***\n";
		return 2;
	}

	try {
		w8::DataTable<float> data(dataFile, FW, ND);
		if (argc == 3) {
			std::cout << "\nData Values\n===========\n";
			std::cout << data << std::endl;
		}
		float m, c;
		data.regression(m, c);
		std::cout << "\nStatistics\n==========\n";
		std::cout << std::fixed << std::setprecision(ND);
		std::cout << "y mean    = " << std::setw(FW) << data.mean() <<
			"\ny sigma   = " << std::setw(FW) << data.sigma() <<
			"\ny median  = " << std::setw(FW) << data.median() << std::endl;
		std::cout << "slope     = " << std::setw(FW) << m <<
			"\nintercept = " << std::setw(FW) << c << std::endl;
	}
	catch (std::string& msg) {
		std::cout << msg << std::endl;
		return 3;
	}

	std::cout << "\nPress any key to continue ... ";
	std::cin.get();
}