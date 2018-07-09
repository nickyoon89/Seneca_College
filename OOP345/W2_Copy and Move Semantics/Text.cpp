// Workshop 2 - Copy and Move Semantics
// Text.cpp
// It includes implementation of Contructors, Destructor, member function and helper function
// Jihyun Yoon
// jyoon31@myseneca.ca
// 124558172
// 2018.05.30

#include <iostream>
#include <string>
#include <fstream>
#include "Text.h"

namespace sict {
	//default constructor: It set the safe statement
	Text::Text(){
		this->name = "";
		str = nullptr;
		n = 0u;
	}
	//Constructor with a string parameter:
	//the parameter is file name. it reads data from file and save every lines in the str.
	//the file name is saved in "name" variable, and the number of line is saved in "n" variable
	Text::Text(const std::string name) {
		std::ifstream file;
		file.open(name);
		if (file.good()) {
			std::string dummy;
			n = getFileLine(file);
			file.clear();
			file.seekg(0, std::ios::beg);
			str = new std::string[n];
			for (size_t i = 0; i < n; i++)
			{
				std::getline(file, str[i]);
			}
			this->name = name;
		}
		else {
			this->name = "";
			str = nullptr;
			n = 0u;
		}
	}
	//Copy Constructor:
	//It copies a Text parameter to "this" Text object.
	Text::Text(const Text &obj) {
		*this = obj;
	}
	//Move Constructor:
	//It moves a Text parameter to "this" Text object.
	//After move, the parameter is set as safe statement.
	Text::Text(Text&& obj) {
		*this = std::move(obj);
	}
	//Copy Assingment:
	//It copies a Text parameter to a Text object, and return the reference of it.
	Text& Text::operator=(const Text& obj) {
		if (this != &obj) {
			delete[] str;
			name.assign(obj.name);
			n = obj.n;
			str = new std::string[n];
			for (size_t i = 0; i < n; i++)
			{
				str[i].assign(obj.str[i]);
			}			
		}
		return *this;
	}	
	//Move Assignemnt:
	//It moves a Text parameter to a Text object and return the reference of it.
	//After move, the parameter is set as safe statement.
	Text& Text::operator=(Text&& obj) {
		if (this != &obj) {
			delete[] str;
			name = obj.name;
			str = obj.str;
			n = obj.n;
 			obj.name = "";
			obj.str = nullptr;
			obj.n = 0u;
		}
		return *this;
	}
	//Destructor:
	//Deallocate the str variable.
	Text::~Text() {
		delete[] str;
	}
	//this function returns the number of line the object stores.
	size_t Text::size() const {
		return n;
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