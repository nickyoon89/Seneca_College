// Workshop 2 - Copy and Move Semantics
// w2.cpp
// main function, it's provided by professor
// Jihyun Yoon
// jyoon31@myseneca.ca
// 124558172
// 2018.05.30

#include <fstream>
#include <iostream>
#include <iomanip>
#include <utility>
#include <ctime>
#include <chrono>
#include "Text.h"
using namespace std::chrono;

// report system time
//
void reportTime(std::ofstream& file, const char* msg,
	steady_clock::duration span) {
	auto ms = duration_cast<milliseconds>(span);
	file << msg << " - took - " << std::setw(5) <<
		ms.count() << " milliseconds" << std::endl;
}

int main(int argc, char* argv[]) {
	std::cout << "Command Line : ";
	for (int i = 0; i < argc; i++) {
		std::cout << argv[i] << ' ';
	}
	std::cout << std::endl;

	// Command Line syntax
	if (argc == 1) {
		std::cerr << "\n*** Insufficient number of arguments ***\n";
		std::cerr << "Usage: " << argv[0] << " fileName \n";
		return 1;
	}
	else if (argc != 2) {
		std::cerr << "\n*** Too many arguments ***\n";
		std::cerr << "Usage: " << argv[0] << " fileName \n";
		return 2;
	}

	steady_clock::time_point cs, ce;
	std::ofstream file("timer.txt");
	{
		std::cout << std::fixed << std::setprecision(3);
		cs = steady_clock::now();
		sict::Text a;
		ce = steady_clock::now();
		reportTime(file, "Dflt Constructor", ce - cs);
		std::cout << "Constructor - a.size = " << a.size() << std::endl;

		cs = steady_clock::now();
		sict::Text b(argv[1]);
		ce = steady_clock::now();
		reportTime(file, "Constructor     ", ce - cs);
		std::cout << "Constructor - b.size = " << b.size() << std::endl;

		cs = steady_clock::now();
		a = b;
		ce = steady_clock::now();
		reportTime(file, "Copy Assignment ", ce - cs);
		std::cout << "Copy Assignment - a.size = " << a.size() << std::endl;

		cs = steady_clock::now();
		a = std::move(b);
		ce = steady_clock::now();
		reportTime(file, "Move Assignment ", ce - cs);
		std::cout << "Move Assignment - a.size = " << a.size() << std::endl;

		cs = steady_clock::now();
		sict::Text c = a;
		ce = steady_clock::now();
		reportTime(file, "Copy Constructor", ce - cs);
		std::cout << "Copy Constructor - c.size = " << c.size() << std::endl;

		cs = steady_clock::now();
		sict::Text d = std::move(a);
		ce = steady_clock::now();
		reportTime(file, "Move Constructor", ce - cs);
		std::cout << "Move Constructor - d.size = " << d.size() << std::endl;

		cs = steady_clock::now();		
	}
	ce = steady_clock::now();
	reportTime(file, "Destructor      ", ce - cs);
}