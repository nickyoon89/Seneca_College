// Workshop 5 - Lambda Expression
// w5.cpp
// Chris Szalwinski
// 2018-05-23

#include <iostream>
#include "Grades.h"
#include "Letter.h"
using namespace sict;

int main(int argc, char* argv[]) {
	std::cout << "Command Line : ";
	for (int i = 0; i < argc; i++) {
		std::cout << argv[i] << ' ';
	}
	std::cout << std::endl;

	if (argc == 1) {
		std::cerr <<
			"\n*** Insufficient number of arguments ***\n";
		std::cerr << "Usage: " << argv[0] << " fileName \n";
		return 1;
	}
	else if (argc != 2) {
		std::cerr << "\n*** Too many arguments ***\n";
		std::cerr << "Usage: " << argv[0] << " fileName \n";
		return 2;
	}

	try {
		sict::Grades grades(argv[1]);
		// lambda expression for converting to letter 

		auto letter = [](double grade) {
			if (grade < 50)
				return Letter::F;
			else if (grade < 55)
				return Letter::D;
			else if (grade < 60)
				return Letter::D_;
			else if (grade < 65)
				return Letter::C;
			else if (grade < 70)
				return Letter::C_;
			else if (grade < 75)
				return Letter::B;
			else if (grade < 80)
				return Letter::B_;
			else if (grade < 90)
				return Letter::A;
			else if (grade >= 90)
				return Letter::A_;

			return Letter::X;
		};

		grades.displayGrades(std::cout, letter);
	}
	catch (int) {
		// report the error message
		std::cerr << argv[0] << ": Failed to open file "
			<< argv[1] << "\n";
	}
	catch (...) {
		std::cerr << "Error Occured";
	}
	//std::cin.get();
	return 2;
}
