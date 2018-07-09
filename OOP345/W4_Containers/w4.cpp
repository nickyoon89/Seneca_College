// Workshop 4 - Containers
// w4.cpp
// Chris Szalwinski
// 2018-05-21

#include <iostream>
#include <fstream>
#include "Notifications.h"

char recordDelimiter{ '\n' };

int main(int argc, char* argv[]) {
	std::cout << "Command Line : ";
	for (int i = 0; i < argc; i++) {
		std::cout << argv[i] << ' ';
	}
	std::cout << std::endl;

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

	std::cout << "\nNotifications\n=============\n\n";
	sict::Notifications notifications = std::move(sict::Notifications(input));

	notifications.display(std::cout);
	{};
}