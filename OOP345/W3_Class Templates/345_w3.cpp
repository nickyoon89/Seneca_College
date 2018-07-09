// Workshop 3 - Class Templates
// 345_w3.cpp
// Chris Szalwinski
// 2018.05.17

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include "KVList.h"
//#define CONSOLE
#ifndef CONSOLE
#define SOURCE input
#else
#define SOURCE std::cin
#endif

// display list of key-value pairs
//
template <typename K, typename V, int N>
void display(const std::string& msg, const KVList<K, V, N>& list, int w) {
    std::cout << msg;
    for (size_t i = 0; i < list.size(); i++)
        std::cout << std::setw(w) << list.key(i)
         << " : " << list.value(i) << std::endl;
}

// prompt for user input
//
void prompt(const char* str) {
	#ifndef CONSOLE
	std::cout << ". ";
	#else
	std::cout << str;
	#endif
}

int main(int argc, char** argv) {
	std::cout << "Command Line : ";
	for (int i = 0; i < argc; i++) {
		std::cout << argv[i] << ' ';
	}
	std::cout << std::endl;

	#ifndef CONSOLE
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
	std::ifstream input(argv[1]);
	if (!input) {
		std::cerr << "*** Failed to open file " << argv[1] << " successfully ***\n";
		return 3;
	}
	#endif

	bool keepreading;
	std::cout << std::fixed << std::setprecision(2);

	std::cout << "\nInventory\n=========\n";
	KVList <std::string, double, 5> inventory;
	std::string str;
	double price;

	keepreading = true;
	do {
		prompt("Product : ");
		getline(SOURCE, str);
		if (str.compare("quit") == 0) {
			keepreading = false;
		}
		else {
			prompt("Price : ");
			SOURCE >> price;
			SOURCE.ignore();
			inventory.add(str, price);
		}
	} while (keepreading);
	display("\nPrice List\n-----------\n", inventory, 13);

	std::cout << "\nCorrections\n-----------\n";
	keepreading = true;
	do {
		prompt("Product : ");
		getline(SOURCE, str);
		if (str.compare("quit") == 0) {
			keepreading = false;
		}
		else {
			int i = inventory.find(str);
			if (i != -1) {
				prompt("Price : ");
				SOURCE >> price;
				SOURCE.ignore();
				inventory.replace(i, str, price);
			}
		}
	} while (keepreading);
	display("\nPrice List\n-----------\n", inventory, 13);

	std::cout << "\nGlossary\n========\n";
	KVList <std::string, std::string, 5> glossary;
	std::string key, definition;

	keepreading = true;
	do {
		prompt("Key : ");
		getline(SOURCE, key);
		if (key.compare("quit") == 0) {
			keepreading = false;
		}
		else {
			prompt("Definition : ");
			getline(SOURCE, definition);
			glossary.add(key, definition);
		}
	} while (keepreading);
	display("\nEntries\n-------\n", glossary, 5);
}