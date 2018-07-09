// Workshop 5 - Lambda Expression
// Grades.cpp
// Jihyun Yoon
// 124588172
// 2018-06-20

#include <string>
#include <fstream>
#include <iomanip>
#include "Grades.h"

namespace sict {
	//safe empty state
	Grades::Grades() {
		students = nullptr;
		grades = nullptr;
		n = 0;
	}
	//receive file name and store the data in the object
	Grades::Grades(const char* name) {
		std::ifstream file;
		std::string str = "";
		file.open(name);
		if (file.good()) {
			n = getFileLine(file);
			file.clear();
			file.seekg(0, std::ios::beg);
			students = new std::string[n];
			grades = new double[n];
			for (int i = 0; i < n; i++)
			{
				std::getline(file, str);
				int pos = str.find(' ');
				students[i] = str.substr(0, pos);
				str.erase(0, pos + 1);
				grades[i] = stod(str);
			}
		}
		else {
			students = nullptr;
			grades = nullptr;
			n = 0;
			throw n;
		}
	}
	//Destructor to deallocate dynamic memory
	Grades::~Grades() {
		delete[] students;
		delete[] grades;
	}
	//this function return the number of line of the parameter file.
	int getFileLine(std::ifstream& fin) {
		std::string temp;
		int numberOfLines = 0;
		while (std::getline(fin, temp))
		{
			numberOfLines++;
		}
		return numberOfLines;

	}
}