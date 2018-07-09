// Workshop 2 - Copy and Move Semantics
// Text.h
// It includes prototypes of Contructors, Destructor, member function and helper function
// Jihyun Yoon
// jyoon31@myseneca.ca
// 124558172
// 2018.05.30

#ifndef SICT_TEXT_H
#define SICT_TEXT_H

namespace sict {
	class Text {
		std::string name;
		std::string* str;
		size_t n;
	public:
		//default constructor: It set the safe statement
		Text();
		//Constructor with a string parameter:
		//the parameter is file name. it reads data from file and save every lines in the str.
		//the file name is saved in "name" variable, and the number of line is saved in "n" variable
		Text(const std::string name);
		//Copy Constructor:
		//It copies a Text parameter to "this" Text object.
		Text(const Text &obj);
		//Move Constructor:
		//It moves a Text parameter to "this" Text object.
		//After move, the parameter is set as safe statement.
		Text(Text&& obj);
		//Copy Assingment:
		//It copies a Text parameter to a Text object, and return the reference of it.
		Text& operator=(const Text& obj);
		//Move Assignemnt:
		//It moves a Text parameter to a Text object and return the reference of it.
		//After move, the parameter is set as safe statement.
		Text& operator=(Text&& obj);
		//Destructor:
		//Deallocate the str variable.
		~Text();
		//this function returns the number of line the object stores.
		size_t size() const;
	};
	//this function return the number of line of the parameter file.
	int getFileLine(std::ifstream& fin);
}
#endif 
